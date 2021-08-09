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
    //updateSerialPorts();
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
        //ui ->output_box -> setText("NOK Recieved, try sending new command");
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

    // Get device name from list of serial devices
   // QString device_name  =  ui->device_list->currentData().toString();
    QString device_name = "tty.SLAB_USBtoUART";

   // qDebug() << "Connecting with device " << device_name;

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
       // ui->status_label->setText("Device Connected");
      //  get_uid();
    }
    else {
        qDebug() << "Error opening connection";

    }
}


/**
 * @brief Send uid command to light sensor
 */
void MainWindow::get_uid()
{
    qDebug()<< "Sending 'UID' command";
//    QString text = "uid\n\r";
//    serial->write(text.toStdString().c_str());
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
    QString default_path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    saving_path = default_path;
    ui->path_edit->setText(default_path);
}
void MainWindow::on_serial_enter_clicked()
{
    qDebug()<<"Function: on_serial_enter_clicked()";
    device_serial_num = ui->serial_num_input->text();
    qDebug()<<"Serial Number Entered: "<<device_serial_num;
    ui->continue_button->setVisible(false);
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
    //send_command("flash");
    ui->flash_usage_bar->setValue(0);
    ui->data_read_bar->setValue(0);

    set_default_path();

}

void MainWindow::on_get_flash_info_clicked()
{
    qDebug()<<"Function: on_get_flash_info_clicked()";
    send_command("flash");
}


void MainWindow::on_read_data_button_clicked()
{
    qDebug() << "Function: on_read_data_button_clicked()";
    send_command("data");
}

void MainWindow::on_read_logs_button_clicked()
{
    qDebug() << "Function: on_read_logs_button_clicked()";
    send_command("log");
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


void MainWindow::save_logs(QList<QByteArray> lines)
{
     qDebug()<<"Function: Save Logs";
    QString filename = saving_path;
    filename.append("/Logs_");
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");

    qDebug() << " File name: "<< filename;
    QFile file(filename);

    int largest_index = get_largest_data_index(filename);

    file.open(QIODevice::Append);

    // Save any unsaved entries
    QTextStream out(&file);
    QList<QByteArray> temp_line;
    int temp_index = 0;

    int num_lines = lines.count();
    qDebug() << "Number of lines to write: "<<num_lines;
    //int i = 1;

//    qDebug() << " LINE 0"<< lines[0]<<"\n";
//    qDebug() << " LINE 1"<< lines[1]<<"\n";
    //int i = 1;
    //while(lines[i].split('\n') != "OK\r"){
    for(int i = 1; i<lines.count()-2; i++) {
        temp_line = lines[i].split(',');
        temp_index = temp_line[1].toInt();
     //   qDebug()<<"TEMP INDEX: "<<temp_index;
    //    qDebug()<< "LINE: "<<i;

        if(temp_index < largest_index)
            continue;
        else
            out<<lines[i];
            qDebug() << lines[i];
        //i++;
    }

    qDebug() << "LARGEST INDEX "<< largest_index;
    out.flush();
    file.close();
}

/**
 * @brief Function to save data returned from the light sensor
 * @param Array of all of the lines in the returned data
 */
void MainWindow::save_data(QList<QByteArray> lines)
{
    qDebug()<<"Function: Save Data";
    QString filename = saving_path;
    filename.append("/Data_");
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");

    qDebug() << " File name: "<< filename;
    QFile file(filename);

    int largest_index = get_largest_data_index(filename);

    file.open(QIODevice::Append);

    // Save any unsaved entries
    QTextStream out(&file);
    QList<QByteArray> temp_line;
    int temp_index = 0;

    int num_lines = lines.count();
    qDebug() << "Number of lines to write: "<<num_lines;
    //int i = 1;

  //  qDebug() << " LINE 0"<< lines[0]<<"\n";
  //  qDebug() << " LINE 1"<< lines[1]<<"\n";
    //int i = 1;
    //while(lines[i].split('\n') != "OK\r"){
    for(int i = 1; i<lines.count()-2; i++) {
        temp_line = lines[i].split(',');
        temp_index = temp_line[1].toInt();
  //      qDebug()<<"TEMP INDEX: "<<temp_index;
   //     qDebug()<< "LINE: "<<i;

        if(temp_index < largest_index)
            continue;
        else
            out<<lines[i];
            qDebug() << lines[i];
        //i++;
    }

    qDebug() << "LARGEST INDEX "<< largest_index;
    out.flush();
    file.close();
}

// Handles recieved data from connected device
void MainWindow::on_ReceivedData()
{
    // Recieving Data
    QByteArray data;
    int count = 0;
    QByteArray temp;
    while(serial->waitForReadyRead(1000)) {
   // while(serial->canReadLine()) {
        temp = serial->readAll();
        if (temp == "\n") {
            count++;
            if(last_command == "data") {
                if (count % 15 == 0) {
//                    double data_read_percent = double(count) / double(num_records) * 100.0;
//                    ui->data_read_bar->setValue(data_read_percent);
                    qDebug()<< "1 Second";
                }
            }
        }

        // Replaced read all with temp
        data.append(temp);

    }
 //   qDebug() << "Response from light sensor" << data ;

    // Deletes IULS xxxxxx from end of message
//    int len = data.count();
//    len = len - 26;
//    data.replace(len, 26, "");
   // ui ->output_box -> setText(data);
   // qDebug() << data << data.count();


    // Check for "@" command to verify connection to light sensor
    if (last_command == "@") {
        if(check_command(data)) {
            qDebug()<< "Connected to Light Sensor";
            ui->status_img->setText("Device Connected");
            ui->continue_button->setVisible(true);
        }
        else {
            ui->status_img->setText("Unable to Connect");
        }
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
           // qDebug()<<"percent: "<< percent ;
            QString mem_info = temp_line + "/11646  ";
            ui->flash_value->setText(mem_info);
            ui->flash_usage_bar->setValue(percent);

        }
    }

    if (last_command == "data") {
        if(check_command(data)) {
            qDebug()<< "Response after Data call"<<data;
            save_data(lines);
        }
    }

    if (last_command == "log") {
        if(check_command(data)) {
            qDebug()<< "Response after Logs call"<<data;
            save_logs(lines);
        }
    }
   //check_command(data);

   // QList<QByteArray> lines = data.split('\r');
//    qDebug() <<lines.count();

//    if (lines[0] == "data\n") {
//        save_data(lines);
//    }
}

// Send data command
//void MainWindow::on_data_button_clicked()
//{
//    qDebug()<< "Sending 'data' command";
//    QString text = "data\n\r";
//    serial->write(text.toStdString().c_str());
//}

/**
 * @brief Sets date on light sensor based on users system
 *
 * CURRENTLY NOT WORKING
 */
//void MainWindow::on_ds_button_clicked()
//{
//    qDebug()<<"Function: on_ds_button_clicked()";
//    QString current_date = helper_functions::get_current_date();
//    qDebug()<<"Current Date Recieved: "<< current_date;

//    serial->write(current_date.toStdString().c_str());
//    last_command = current_date;

//}

/**
 * @brief Sets time on light sensor based on users system
 */
//void MainWindow::on_ts_button_clicked()
//{
//    qDebug()<<"Function: on_ts_button_clicked()";
//    QString current_time = helper_functions::get_current_time();
//    qDebug()<<"Current Time Recieved: "<< current_time;

//    serial->write(current_time.toStdString().c_str());
//    last_command = current_time;
//}

/**
 * @brief Send battery command to light sensor
 * CURRENTLY NOT WORKING
 */
//void MainWindow::on_batt_button_clicked()
//{
//    qDebug()<<"Function: on_batt_button_clicked()";
//    QString command = "batt\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;

//}

/**
 * @brief Send help command to light sensor
 */
//void MainWindow::on_help_button_clicked()
//{
//    qDebug()<<"Function: on_help_button_clicked()";
//    QString command = "help\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;
//}



/**
 * @brief Sends sample command to light sensor
 */
//void MainWindow::on_sample_button_clicked()
//{
//    qDebug()<<"Function: on_sample_button_clicked()";
//    QString command = "sample\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;
//}

/**
 * @brief Sends flash command to light sensor
 */
//void MainWindow::on_ef_button_clicked()
//{
//    qDebug()<<"Function: on_ef_button_clicked()";
//    QString command = "flash\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;
//}

/**
 * @brief Sends erase flash command to light sensor
 */
//void MainWindow::on_ef_all_button_clicked()
//{
//    qDebug()<<"Function: on_ef_all_button_clicked()";
//    QString command = "ef,all\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;
//}

/**
 * @brief Sends log command to light sensor
 */
//void MainWindow::on_log_button_clicked()
//{
//    qDebug()<<"Function: on_log_button_clicked()";
//    QString command = "log\n\r";
//    serial->write(command.toStdString().c_str());
//    last_command = command;
//}


//void MainWindow::on_flash_usage_bar_valueChanged(int value)
//{
//    ui->flash_usage_bar->setValue(value)
//}



