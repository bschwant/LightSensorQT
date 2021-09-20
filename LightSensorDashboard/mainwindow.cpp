#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <string.h>
#include <qbytearray.h>
#include <QFile>
#include <QTextStream>
#include "helper_functions.h"
#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>

// Function prototypes
QString get_current_date();
QString get_current_time();


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    ui->program_pages->setCurrentIndex(0);
    ui->data_read_bar->setValue(0);
    num_records = 0;
    count = 0;
    ui->img_status_label->setPixmap(QPixmap(":/status/yellow.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

/**
 * @brief Check return from device for OK or NOK
 * @param The message received from the device
 */
bool MainWindow::check_command(QByteArray response)
{
    qDebug()<< "Function: check_command()";
    bool response_error;
    response_error = response.contains("NOK");

    if(response_error) {
        qDebug()<<"INVALID COMMAND: "<< last_command;
        last_command = "";
        return false;
    }
    else {
        qDebug()<<"Command: "<< last_command<< "   VALID";
        last_command = "";
        return true;
    }

}

/**
 * @brief Function to handle sending of commands and appending \n\r
 * @param String of the command
 * Saves command to last command variable
 */
void MainWindow:: send_command(QString command)
{
    qDebug()<<"Sending Command: "<< command;
    QString command_ready = command + "\n\r";
    serial->write(command_ready.toStdString().c_str());
    last_command = command;

}

void MainWindow::open_port_for_commun()
{
    qDebug() << "Function to open port for uart to usb device";

    QString device_name = "tty.SLAB_USBtoUART";
    serial->setPortName(device_name);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    if(serial->isOpen() == true) {
        qDebug() << "Serial is open";
        connect(serial, SIGNAL(readyRead()), this, SLOT(on_ReceivedData()));
        serial->setDataTerminalReady(true);
    }
    else {
        ui->img_status_label->setPixmap(QPixmap(":/status/red_x.png"));
        qApp->processEvents();
        qDebug() << "Error opening connection";
    }
}

/**
 * @brief Send uid command to light sensor
 */
void MainWindow::get_uid()
{
    qDebug()<< "Sending 'UID' command";
    send_command("uid");
}

void MainWindow::change_path(QString new_path)
{
    saving_path = new_path;
    ui->path_edit->setText(new_path);
    qDebug()<< "New Path: "<<new_path;
}

void MainWindow::set_default_path()
{
    // Set Default path to downloads
    QString default_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    saving_path = default_path;
    device_dir = saving_path + ',' +device_serial_num;
    ui->path_edit->setText(default_path);
}

void MainWindow::update_device_directory() {
    device_dir = saving_path + ',' +device_serial_num;
}
void MainWindow::on_serial_enter_clicked()
{
    qDebug()<<"Function: on_serial_enter_clicked()";
    device_serial_num = ui->serial_num_input->text();
    qDebug()<<"Serial Number Entered: "<<device_serial_num;
    ui->continue_button->setVisible(false);
    ui->change_location_button->setVisible(false);
    ui->program_pages->setCurrentIndex(1);

}

void MainWindow::on_check_conn_button_clicked()
{
    open_port_for_commun();
    qDebug()<<"Function: on_check_conn_button_clicked()";
    send_command("@");
}

void MainWindow::on_continue_button_clicked()
{
    qDebug()<<"Function:: on_continue_button_clicked()";
    ui->program_pages->setCurrentIndex(2);
    ui->dev_ser_num->setText(device_serial_num);
    send_command("uid");
    ui->flash_usage_bar->setValue(0);
    ui->data_read_bar->setValue(0);

    set_default_path();

}

void MainWindow::on_get_flash_info_clicked()
{
    qDebug()<<"Function: on_get_flash_info_clicked()";
    send_command("flash");
}


void MainWindow::on_collect_button_clicked()
{
    qDebug() << "Function: on_collect_button_clicked()";
    count = 0;
    ui->curr_status_label->setText("Downloading Data");
    send_command("data");
}

/**
 * @brief Function allows user to change path where data and logs will be saved
 */
void MainWindow::on_change_path_button_clicked()
{
    qDebug() << "Function: on_change_path_button_clicked()";
    QString temp_path = QFileDialog::getExistingDirectory();
    ui->path_edit->setText(temp_path);
    saving_path = temp_path;
    qDebug()<<"New Path: "<< saving_path;
    update_device_directory();
}

/**
 * @brief Function to find index of largest sample if data file exists
 * @param File name is the UID of the light sensor in .txt format
 * @return Index of largest sample, or 0 if file does not exist and all
 *  samples need to be saved
 */
int MainWindow:: get_largest_data_index(QString filename)
{
    QFile file(filename);

    // Check if file already exists
    if(!file.open(QIODevice:: ReadOnly)) {
        qDebug() << "Cannot Open File";
        return 0;
    }

    file.open(QIODevice:: ReadOnly);

    QTextStream in(&file);

    int largest_index = 0;

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> parsed = line.split(',');
        largest_index = parsed[1].toInt();
    }
    file.close();
    qDebug()<< "Largest index found in file: "<< largest_index;
    return largest_index;
}

/**
 * @brief Function to data/logs/records to respective files
 * @param lines
 * @param file_type int - 0 = data, 1 = logs
 */
void MainWindow::save_to_file(QList<QByteArray> lines, int file_type)
{
    qDebug()<<"Function: save_to_file";
    QString filename = saving_path;
   // device_dir = helper_functions::get_device_dir(saving_path, device_serial_num);
    filename = helper_functions::check_if_directory_exists(device_dir);


    if(file_type == 0)
        filename.append("/Data_");
    else if(file_type == 1)
        filename.append("/Logs_");
    else
        qDebug()<<"File Type Not Valid";

  //  filename.append("/Data_");
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");

    qDebug() << " File name: "<< filename;
    QFile file(filename);

    // Handles saving of data and logs
    if (file_type == 0 or file_type == 1) {
        int largest_index = get_largest_data_index(filename);

        file.open(QIODevice::Append);

        // Save any unsaved entries
        QTextStream out(&file);
        QList<QByteArray> temp_line;
        int temp_index = 0;

        int num_lines = lines.count();

        for(int i = 1; i<lines.count()-2; i++) {
            temp_line = lines[i].split(',');
            temp_index = temp_line[1].toInt();

            if(temp_index < largest_index)
                continue;
            else
                out<<lines[i];
              //  qDebug() << lines[i];
        }
        qDebug() << "LARGEST INDEX "<< largest_index;
        out.flush();
    }

    file.close();
}


void MainWindow::save_collection_record()
{
    qDebug()<<"Function: save_to_file";
    QString filename = saving_path;
   // device_dir = helper_functions::get_device_dir(saving_path, device_serial_num);
    filename = helper_functions::check_if_directory_exists(device_dir);
    filename.append("/Records_");
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");

    qDebug() << " Filename: "<< filename;
    QFile file(filename);

    // Get current date and time of collection
    QString current_date = helper_functions::get_current_date();
    QString current_time = helper_functions::get_current_time();

    // Get user long/lat input
    QString longitude = ui->longitude_edit->text();
    QString latitude = ui->latitude_edit->text();

    // Get user note input
    QString user_note = ui->note_input->toPlainText();

    file.open(QIODevice::Append);

    QTextStream out(&file);

    file.open(QIODevice::Append);

    out<<"Collection Date: " << current_date << "\n";
    out<<"Collection Time: " << current_time << "\n";
    out<<"Location: "<< latitude << ", " << longitude << "\n";
    out<<"Note: "<< user_note << "\n";
    out<<"-------------------------------------------------------------\n\n";

    out.flush();
    file.close();

    ui->curr_status_label->setText("Download Finished");
}

// Handles recieved data from connected device
int MainWindow::on_ReceivedData()
{
    // Recieving Data
    QByteArray data;
    //int count = 0;
    QByteArray temp;
    while(serial->waitForReadyRead(100)) {
        temp = serial->readAll();
        if (temp == "\n") {
            count++;
            if(last_command == "data") {
                if (count % 30 == 0) {
                    int data_read_percent = double(count) / double(num_records) * 100.0;
                    qDebug()<< "Perecent: " << data_read_percent;
                    ui->data_read_bar->setValue(data_read_percent);
                    qApp->processEvents();
               //     qDebug()<< "2 Second";
                }
            }
            else if(last_command == "log") {
                if (count % 30 == 0) {
                    int data_read_percent = double(count) / double(num_records) * 100.0;
                    qDebug()<< "Perecent: " << data_read_percent;
                    ui->data_read_bar->setValue(data_read_percent);
                    qApp->processEvents();
                  //  qDebug()<< "2 Second";
                }
            }

        }
        data.append(temp);
    }

    // Check for "@" command to verify connection to light sensor
    if (last_command == "@") {
        if(check_command(data)) {
            qDebug()<< "Connected to Light Sensor";
            ui->img_status_label->setPixmap(QPixmap(":/status/green_check.png"));
            ui->continue_button->setVisible(true);
            qApp->processEvents();
        }
        else {
            ui->img_status_label->setPixmap(QPixmap(":/status/red_X.png"));
            qApp->processEvents();
        }
        return 0;
    }

    QList<QByteArray> lines = data.split('\r');
    qDebug() <<lines.count();

    if (last_command == "uid") {
        if(check_command(data)) {
            qDebug()<< "Recieved Device UID";
            device_uid = lines[1];
            device_uid.replace(QString("\n"),QString(""));
            ui->dev_uid->setText(device_uid);
        }
        else
            qDebug()<< "Error getting Device UID";
        return 0;
    }

    if (last_command == "flash") {
        if(check_command(data)) {
            qDebug()<< "Recieved Flash Information";
            QRegExp rx("[= ]");
            QString temp_line = lines[2];
            QStringList temp_val = temp_line.split(rx, QString::SkipEmptyParts);
            int list_len = temp_val.size();
            temp_line = temp_val[list_len-1];
            temp_line.replace(QString("\n"),QString(""));
            qDebug()<<temp_val;
            qDebug()<<temp_line;
            int mem_index = temp_line.toInt();
            num_records=mem_index;
            double percent = double(mem_index) / 11646.0 * 100;
            QString mem_info = temp_line + "/11646  ";
            ui->flash_value->setText(mem_info);
            ui->flash_usage_bar->setValue(percent);
        }
        return 0;
    }

    if (last_command == "data") {
        if(check_command(data)) {
            save_to_file(lines, 0);
            send_command("log");
        }
        return 0;
    }

    if (last_command == "log") {
        if(check_command(data)) {
            save_to_file(lines, 1);
            ui->data_read_bar->setValue(100);
            qApp->processEvents();
        }
        ui->curr_status_label->setText("Saving Collection Record");
        save_collection_record();
        return 0;
    }
}


void MainWindow::on_get_last_location_clicked()
{
    QMessageBox msgBox;
    QPushButton *changePathButton = msgBox.addButton(tr("Change Path"), QMessageBox::ActionRole);
    QStringList record_lines;

    qDebug()<<"Function: get_last_location_clicked()";

    QString filename = saving_path;
    device_dir = helper_functions::get_device_dir(saving_path, device_serial_num);
    filename = helper_functions::check_if_directory_exists(device_dir);
    filename.append("/Records");
    filename.append("_");
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");
    qDebug()<<"Trying to open file: "<<filename;


    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        msgBox.setText("Unable to locate previous collection records");
        msgBox.setInformativeText("Change file path to get past collection data");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();

        if(msgBox.clickedButton() == changePathButton) {
            on_change_path_button_clicked();
            return;
        }
    }


    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        record_lines.append(line);
    }

    QStringList temp_record_lines;
    QString parsed_record;
    parsed_record = helper_functions::parse_past_records(record_lines);
    temp_record_lines = parsed_record.split(',');
    QString latitude = temp_record_lines[0];
    QString longitude = temp_record_lines[1];
    QString date = temp_record_lines[2];
    QString time = temp_record_lines[3];
    QString note = temp_record_lines[4];

    ui->latitude_edit->setText(latitude);
    ui->longitude_edit->setText(longitude);

    ui->latitude_edit->setEnabled(false);
    ui->longitude_edit->setEnabled(false);

    ui->date_label->setText(date);
    ui->time_label->setText(time);
    ui->date_label->setEnabled(false);
    ui->time_label->setEnabled(false);
    ui->change_location_button->setVisible(true);

    ui->note_input->setText(note);
    ui->note_input->setEnabled(false);
}


void MainWindow::on_change_location_button_clicked()
{
    ui->latitude_edit->setEnabled(true);
    ui->longitude_edit->setEnabled(true);
    ui->note_input->setEnabled(true);
}

