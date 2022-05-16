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
#include <QSettings>
#include <QtCore>
#include <QDialog>
#include <QFileSystemModel>
#include "file_saving.h"
#include "light_sensor.h"
#include "current_user.h"
#include "location_manager.h"
#include <QDirIterator>
#include <QInputDialog>


//// Function prototypes
//QString get_current_date();
//QString get_current_time();

LightSensor* light_sensor = new LightSensor();
current_user* user = new current_user();
location_manager* location_handler = new location_manager();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//class light_sensor;
//    LightSensor light_sensor = new LightSensor();
    ui->setupUi(this);
    serial = new QSerialPort(this);

    ui->serial_num_diagram->setPixmap(QPixmap(":/icon/serial_number"));
    intialize_program();
    load_settings();

    QString sPath = user->get_def_path();
    qDebug()<<"path = "<<sPath;
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    dirModel->setRootPath(sPath);

    ui->location_tree_view->setModel(dirModel);
    QModelIndex index_1 = dirModel->index(sPath, 0);
    ui->location_tree_view->setRootIndex(index_1);
    for (int i = 1; i < dirModel->columnCount(); ++i)
        ui->location_tree_view->hideColumn(i);

    subDirs = new QFileSystemModel(this);
    subDirs->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    subDirs->setRootPath(sPath);

    ui->location_list_view->setModel(subDirs);
    QModelIndex index_2 = dirModel->index(sPath, 0);
    ui->location_list_view->setRootIndex(index_2);
//    for (int i = 1; i < subDirs->columnCount(); ++i)
//        ui->location_list_view->hideColumn(i);



    QObject::connect(this, SIGNAL(progress(int)), this, SLOT(on_data_read_bar_valueChanged(int)));
    QObject::connect(this, SIGNAL(function_step(int)), this, SLOT(collection_functions(int)));
    QObject::connect(this, SIGNAL(deployment_step(int)), this, SLOT(deployment_functions(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::intialize_program(){
    light_sensor->new_device();
//    light_sensor->init_paths(user->get_def_path());
//    ui->path_edit->setText(user->get_def_path());



//    device_uid = "";
//    device_serial_num = "";
//    num_records = 0;
//    saving_path = "";
//    device_dir = "";
//    device_latitude = "";
//    device_longitude = "";
    updateSerialPortsConnect();
    collection_complete = 0;
    collection_progress = 0;
    downloading_data = 0;
    sensor_deployment = 0;
    ui->latitude_edit->setText("");
    ui->longitude_edit->setText("");
    ui->date_label->setText("N/A");
    ui->time_label->setText("N/A");
    ui->note_input->setText("");

    ui->serial_num_input->setText("");
    ui->program_pages->setCurrentIndex(0);
    ui->data_read_bar->setValue(0);
    ui->curr_status_label->setVisible(false);
   // ui->data_read_bar->setVisible(false);
    ui->img_status_label->setPixmap(QPixmap(":/icon/yellow_box.png"));
    ui->change_location_button->setEnabled(false);
    ui->latitude_edit->setEnabled(true);
    ui->longitude_edit->setEnabled(true);
    ui->note_input->setEnabled(true);
    ui->collection_pages->setCurrentIndex(0);
//    ui->other_options_group_box->setVisible(false);
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
    if(serial->isOpen()){
         serial->write(command_ready.toStdString().c_str());
         PORT_ERROR = 0;
    }
    else {
        qDebug()<<"SERIAL PORT ERROR: CONNECTION NOT OPEN";
        PORT_ERROR = 1;
        if(command == "flash"){
            double temp = 0;
            ui->flash_usage_bar->setValue(temp);
        }
    }
//    serial->write(command_ready.toStdString().c_str());
    last_command = command;

}
void MainWindow::updateSerialPortsConnect()
{
    mSerialPorts = QSerialPortInfo::availablePorts();

    ui->ports_box ->clear();
    for (QSerialPortInfo port : mSerialPorts) {
        ui->ports_box->addItem(port.portName(), port.systemLocation());
    }
}

/**
 * @brief Functions open up serial port to communicate with light sensor
 */
void MainWindow::open_port_for_commun()
{
    qDebug() << "Function to open port for uart to usb device";
    QString device_name = ui->ports_box->currentText();
//    QString device_name = "tty.SLAB_USBtoUART";
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
        ui->img_status_label->setPixmap(QPixmap(":/icon/red_box.png"));
        qApp->processEvents();
        qDebug() << "Error opening connection";
    }
}

/**
 * @brief Send uid command to light sensorsl
 */
void MainWindow::get_uid()
{
    qDebug()<< "Sending 'UID' command";
    send_command("uid");
}

/**
 * @brief Function handles updating of paths when changed
 * @param new_path
 */
void MainWindow::change_path(QString new_path)
{
    light_sensor->update_paths(new_path);
    ui->path_edit->setText(light_sensor->get_base_path());
    qDebug()<< "New Path: "<<light_sensor->get_base_path();
}

/**
 * @brief Sets default path for program.
 * Path is path from user settings.
 * If not path in settings, path is default desktop location
 */
void MainWindow::set_default_path()
{
    // Set Default path to downloads
    QString default_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    QString user_default_path = user->get_def_path();
    if(user_default_path.length() != 0){
        qDebug()<<"Using users default path";
        light_sensor->init_paths(user_default_path);
    }
    else {
        qDebug()<<"Using program default path";
        light_sensor->init_paths(default_path);
    }

//    QString default_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
//    light_sensor->init_paths(default_path);
}

void MainWindow::update_device_directory() {
    light_sensor->update_paths(light_sensor->get_base_path());
}

void MainWindow::on_serial_enter_clicked()
{
    qDebug()<<"Function: on_serial_enter_clicked()";
    QMessageBox msgBox;
    QString serial_input = ui->serial_num_input->text();
    if (serial_input == "") {
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Serial Number Input is Empty");
        msgBox.setInformativeText("Please enter the device serial number.");
        msgBox.exec();
        return;
    }
    light_sensor->set_serial_num(serial_input);
    qDebug()<<"Serial Number Entered: "<< light_sensor->get_serial_num();
    ui->continue_button->setVisible(false);
    ui->change_location_button->setVisible(false);
    ui->program_pages->setCurrentIndex(3);

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
    // Populate location menus
    populate_location_list();
    ui->program_pages->setCurrentIndex(7);
//    ui->dev_ser_num->setText(light_sensor->get_serial_num());
//    send_command("uid");
//    ui->flash_usage_bar->setValue(0);
//    ui->data_read_bar->setValue(0);
//    if(user->get_def_path().length() != 0) {
//        ui->path_edit->setText(user->get_def_path());
//        light_sensor->init_paths(user->get_def_path());
//    }

//    set_default_path();

}

void MainWindow::on_get_flash_info_clicked()
{
    qDebug()<<"Function: on_get_flash_info_clicked()";
    send_command("flash");
}

/**
 * @brief Handles all functions related to data collection
 * @param Signal value representing step
 */
void MainWindow::collection_functions(int value) {
    downloading_data = 1;

    // Check that flash memory is set
    if(value == 1) {
        if (num_records == 0) {
            send_command("flash");
        }
        else
            emit function_step(2);
    }
    // Run data command
    else if (value == 2) {
        ui->curr_status_label->setText("Saving Device Data");
        send_command("data");
    }
    // Run log command
    else if (value == 3) {
        ui->curr_status_label->setText("Saving Device Logs");
        send_command("log");
    }
    // run records command
    else if (value == 4) {
        ui->curr_status_label->setText("Saving Collection Records");
        save_collection_record();
        ui->other_options_group_box->setVisible(true);
    }
}

/**
 * @brief Handles steps when collect data button is clicked.
 */
void MainWindow::on_collect_button_clicked()
{
    qDebug() << "Function: on_collect_button_clicked()";
    helper_functions::make_directory(light_sensor->get_device_directory());

    // Check if user has entered location and collection note
    QMessageBox msgBox;
    QString lat = ui->latitude_edit->text();
    QString lon = ui->longitude_edit->text();
    QStringList temp_loc;
    temp_loc << lat << lon;
    light_sensor->set_device_lat_long(temp_loc);
    if (lat == "" || lon == "") {
        msgBox.setText("No Sensor Location Provided");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setInformativeText("Please enter the location of the sensor before downloading data");
        msgBox.exec();
        return;
    }
    ui->collection_pages->setCurrentIndex(1);
    ui->curr_status_label->setVisible(true);
    ui->data_read_bar->setVisible(true);
    emit function_step(1);
}

/**
 * @brief Function allows user to change path where data and logs will be saved
 */
void MainWindow::on_change_path_button_clicked()
{
    qDebug() << "Function: on_change_path_button_clicked()";
    QString temp_path = QFileDialog::getExistingDirectory();
    light_sensor->init_paths(temp_path);
    ui->path_edit->setText(light_sensor->get_base_path());
    light_sensor->update_paths(light_sensor->get_base_path());
    qDebug()<<"new base path:"<<light_sensor->get_base_path();
}



/**
 * @brief Function to data and logs to respective files
 * @param lines
 * @param file_type int - 0 = data, 1 = logs
 */
void MainWindow::save_to_file(QList<QByteArray> lines, int file_type)
{
    qDebug()<<"Function: save_to_file()";

    // Updates file name to directory .../.../<serial_number>_<device_uid>
    QString filename = helper_functions::make_directory(light_sensor->get_device_directory());

    if(file_type == 0)
        filename = light_sensor->get_data_path();
    else if(file_type == 1)
        filename = light_sensor->get_log_path();
    else
        qDebug()<<"ERROR: File Type Not Valid";

//<<<<<<< HEAD
    filename.append(device_serial_num);
    filename.append("_");
    filename.append(device_uid);
    filename.append(".txt");

//<<<<<<< HEAD
    // Make sure path seperators are correct for OS
//    filename = QDir::toNativeSeparators(filename);

//    qDebug() << " File name: "<< filename;
//    QFile file(filename);

//    // Handles saving of data and logs
//    if (file_type == 0 or file_type == 1) {
//        int largest_index = get_largest_data_index(filename);

//        file.open(QIODevice::Append);

//        // Save any unsaved entries
//        QTextStream out(&file);
//        QList<QByteArray> temp_line;
//        int temp_index = 0;

//        int num_lines = lines.count();

//        for(int i = 1; i<lines.count()-2; i++) {
//            temp_line = lines[i].split(',');
//            temp_index = temp_line[1].toInt();

//            if(temp_index < largest_index)
//                continue;
//            else
//                out<<lines[i];
//              //  qDebug() << lines[i];
//        }
//        qDebug() << "LARGEST INDEX "<< largest_index;
//        out.flush();
//    }

//    file.close();
//=======
//=======
//>>>>>>> development
    // Call function to save data given file path ("filename") and data ("lines")
    file_saving::save_sensor_data_logs_to_file(filename, lines);
//>>>>>>> development
}

/**
 * @brief Function handles saving record for each collection
 */
void MainWindow::save_collection_record()
{
    qDebug()<<"Function: save_collection_record()";
    QString filename;

    // Updates file name to directory .../.../<serial_number>_<device_uid>
    filename = helper_functions::make_directory(light_sensor->get_device_directory());
    filename = light_sensor->get_record_path();

//<<<<<<< HEAD
    // Make sure path seperators are correct for OS
    filename = QDir::toNativeSeparators(filename);

    qDebug() << " Filename: "<< filename;
    QFile file(filename);

//=======
//>>>>>>> development
    // Get current date and time of collection
    QString current_date = helper_functions::get_current_date();
    QString current_time = helper_functions::get_current_time();
    // Get user long/lat input
    QString longitude = ui->longitude_edit->text();
    QString latitude = ui->latitude_edit->text();
    device_latitude = longitude;
    device_longitude = latitude;
    collection_complete = 0;
    // Get user note input
    QString user_note = ui->note_input->toPlainText();

    // Add all data for record to strong list
    QStringList record_data;
    record_data << current_date << current_time << latitude<< longitude << user_note;

    file_saving::add_collection_record_to_file(filename, record_data);

    ui->curr_status_label->setText("Download Finished");
    collection_complete = 1;
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

        if (temp == "\n" ) {
            collection_progress+=1;
            if(collection_progress % 15 == 0) {
                if(last_command == "data" || last_command=="log") {
                    int data_read_percent = double(collection_progress) / double(num_records) * 100.0;
                    emit progress (data_read_percent);
                    qApp->processEvents();
                }
            }
         }
        data.append(temp);
    }
    // Show sensor return
    qDebug()<<"Sensor Return: "<<data;

    // Check for "@" command to verify connection to light sensor
    if (last_command == "@") {
        if(check_command(data)) {
            qDebug()<< "Connected to Light Sensor";
            ui->img_status_label->setPixmap(QPixmap(":/icon/green_box.png"));
            ui->continue_button->setVisible(true);
            qApp->processEvents();
        }
        else {
            ui->img_status_label->setPixmap(QPixmap(":/icon/red_box.png"));
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
            light_sensor->set_uid(device_uid);
            ui->dev_uid->setText(light_sensor->get_uid());
            light_sensor->update_paths(light_sensor->get_base_path());

//            update_device_directory();
        }
        else
            qDebug()<< "Error getting Device UID";
        return 0;
    }

    if (last_command == "flash") {
        if(check_command(data) && PORT_ERROR == 0) {
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
            light_sensor->set_num_records(mem_index);
            if (downloading_data == 1) {
                 emit function_step(2);
            }
        }
        else {
            double temp = 0;
            ui->flash_usage_bar->setValue(temp);
        }
        return 0;
    }

    if (last_command == "data") {
        if(check_command(data)) {
            save_to_file(lines, 0);
            emit function_step(3);
            //send_command("log");
        }
        return 0;
    }

    if (last_command == "log") {
        if(check_command(data)) {
            save_to_file(lines, 1);
            emit progress(100);
            emit function_step(4);
        }
        return 0;
    }

    if(last_command == "tr") {
        qDebug()<< "In tr check";
        if(sensor_deployment == 1 and check_command(data)) {
            qDebug()<<"Inside check";
            device_time  = lines[1];
            qDebug()<<"Device Time:"<<device_time  ;
            emit deployment_step(1);
        }
        return 0;
    }

    return 0;
}

/**
 * @brief Function gets last location for fields on data collection page
 */
void MainWindow::on_get_last_location_clicked()
{
    QMessageBox msgBox;
    QPushButton *changePathButton = msgBox.addButton(tr("Change Path"), QMessageBox::ActionRole);
    QStringList record_lines;

    qDebug()<<"Function: get_last_location_clicked()";

    QString filename;
//    helper_functions::check_if_directory_exists(light_sensor->get_device_directory());

//    filename = light_sensor->get_record_path();
    filename = light_sensor->get_device_info_path();
    qDebug()<<filename;


    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QString info = "Device might have no previous collection records.\n";
        info.append("If data has been previously collected from device, check that correct path is selected.");
        msgBox.setText("Unable to Locate Collection Records for This Light Sensor");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setInformativeText(info);
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();

        if(msgBox.clickedButton() == changePathButton) {
            on_change_path_button_clicked();
        }
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        record_lines.append(line);
    }

    QString temp_ser_num = record_lines[0];
    QString temp_uid = record_lines[1];
    QString temp_date = record_lines[2];
    QString temp_loc = record_lines[3];
    QString temp_hint = record_lines[4];
    QStringList loc = temp_loc.split(',');

    light_sensor->set_device_lat_long(loc);
    ui->latitude_edit->setText(loc[0]);
    ui->longitude_edit->setText(loc[1]);


//    QStringList temp_record_lines;
//    QString parsed_record;
//    parsed_record = helper_functions::parse_past_records(record_lines);
//    temp_record_lines = parsed_record.split(',');
//    QString latitude = temp_record_lines[0];
//    QString longitude = temp_record_lines[1];
//    QString date = temp_record_lines[2];
//    QString time = temp_record_lines[3];
//    QString note = temp_record_lines[4];



//    device_latitude = latitude;
//    device_longitude = longitude;
//    ui->latitude_edit->setText(latitude);
//    ui->longitude_edit->setText(longitude);

    ui->latitude_edit->setEnabled(false);
    ui->longitude_edit->setEnabled(false);

    ui->date_label->setText(temp_date);
//    ui->time_label->setText(time);
    ui->date_label->setEnabled(false);
    ui->time_label->setEnabled(false);
    ui->change_location_button->setVisible(true);

//    ui->note_input->setText(note);
    ui->note_input->setEnabled(false);
    ui->change_location_button->setEnabled(true);
}

void MainWindow::on_change_location_button_clicked()
{
    ui->latitude_edit->setEnabled(true);
    ui->longitude_edit->setEnabled(true);
    ui->note_input->setEnabled(true);
}


void MainWindow::on_data_read_bar_valueChanged(int value)
{
    ui->data_read_bar->setValue(value);
}


void MainWindow::on_new_device_button_clicked()
{
    intialize_program();
    ui->program_pages->setCurrentIndex(2);
}

void MainWindow::on_mem_page_button_clicked()
{
    qDebug()<<"Function: on_mem_page_button_clicked()";
    ui->program_pages->setCurrentIndex(5);
}

/**
 * @brief Function updates all lists of locations
 */
void MainWindow::populate_location_list(){
    ui->location_dropdown->clear();
    ui->deploy_location->clear();

    location_handler->set_locations(user->get_def_path());

    QStringList temp_locations = location_handler->get_locations();

    for (int i = 0; i < temp_locations.length(); i++) {
//        if(locations[i]=="NoLocation")
        ui->location_dropdown->insertItem(i, temp_locations[i]);
        ui->deploy_location->insertItem(i, temp_locations[i]);
        qDebug()<<"Index: "<< i;
    }

    int num_items = ui->location_dropdown->count();
    ui->location_dropdown->insertItem(num_items, "New Location");
    ui->deploy_location->insertItem(num_items, "New Location");
}

void MainWindow::on_deploy_button_clicked()
{
    if (collection_complete != 1) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please Download Data From Device Before Deployment");
        msgBox.exec();
    }
    ui->name_input->setText(user->get_users_name());
    ui->phone_input->setText(user->get_users_phone());
    QStringList temp_loc= light_sensor->get_device_lat_long();
    if(temp_loc[0].length()>0) {
        ui->latitude_input_deploy->setText(temp_loc[0]);
        ui->longitude_input_deploy->setText(temp_loc[1]);
    }

    /**  AUTOMATICALLY SET LAT AND LONG FROM DEPLOYMENT PAGE **/
//    ui->latitude_input_deploy->setText(light_sensor->get)

    qDebug()<<"Function: on_deploy_button_clicked()";
    populate_location_list();
    ui->program_pages->setCurrentIndex(6);

}


void MainWindow::on_use_last_button_clicked()
{
    if (device_latitude == "" || device_longitude == "") {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Cannot Retrieve Past Location");
        msgBox.setInformativeText("Please enter the coorderniates where light sensor is being deployed");
        msgBox.exec();
        return;
    }
    ui->latitude_input_deploy->setText(device_latitude);
    ui->longitude_input_deploy->setText(device_longitude);
    ui->deploy_location->setCurrentIndex(light_sensor->get_location_index());
}

void MainWindow::deployment_functions(int value) {
    QString current_time;
    if(value == 0) {
        send_command("tr");
    }
    else if(value == 1) {
        current_time = helper_functions::get_current_time_deployment();
        QString update_time = current_time+"\n\r";
        send_command(update_time);
        qDebug()<<"Update time command being sent to LS: "<< update_time;
        emit deployment_step(2);
    }
    else if(value == 2) {
        current_time = helper_functions::get_current_time_deployment();
        qDebug()<<"Current time: "<< current_time;
        qDebug()<<"Device time: "<<device_time;

        QStringList sys_time_list = current_time.split(',');
        QStringList dev_time_list = device_time.split(',');

        int hour_dif = sys_time_list[1].toInt() - dev_time_list[1].toInt();
        int min_dif = sys_time_list[2].toInt() - dev_time_list[2].toInt();
        int sec_dif = sys_time_list[3].toInt() - dev_time_list[3].toInt();

        int time_delta = (hour_dif * 3600) + (min_dif * 60) + (sec_dif);


        QString contact_name = ui->name_input->text();
        QString contact_phone = ui->phone_input->text();
        QString deploy_lat = ui->latitude_input_deploy->text();
        QString deploy_long = ui->longitude_input_deploy->text();
        QString time_diff = QString::number(time_delta);
        QStringList deployment_info;
        deployment_info << contact_name << contact_phone << deploy_lat << deploy_long << time_diff;

        QString filename;
        filename = helper_functions::make_directory(light_sensor->get_device_directory());

        filename = light_sensor->get_record_path();

        file_saving::add_deployment_record_to_file(filename, deployment_info);
    }

}
void MainWindow::on_deploy_light_sensor_clicked()
{
    qDebug()<<"Function: deploy_light_sensor_clicked()";
    light_sensor->set_current_location(ui->deploy_location->currentText());
    light_sensor->update_paths_with_location();

    QString temp_lat = ui->latitude_input_deploy->text();
    QString temp_long = ui->longitude_input_deploy->text();

    QStringList temp_loc;
    temp_loc<<temp_lat<<temp_long;
    light_sensor->set_device_lat_long(temp_loc);

    QStringList device_info;
    QString current_date = helper_functions::get_current_date();
    device_info << light_sensor->get_device_serial_num();
    device_info << light_sensor->get_device_uid();
    device_info << current_date;
    device_info << temp_lat + "," + temp_long;
    device_info << ui->location_hint->text();

    file_saving::save_device_info(light_sensor->get_device_info_path(), device_info);

    sensor_deployment = 1;

    if(temp_lat == "" || temp_long == "") {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("No Location Input");
        msgBox.setInformativeText("Please make sure the latitude and longitude inputs are not empty.");
        msgBox.exec();
        return;
    }
    emit deployment_step(0);
}




void MainWindow::on_data_collect_button_clicked()
{
    ui->program_pages->setCurrentIndex(2);
}




void MainWindow::on_setting_button_clicked()
{
     ui->name_settings_input->setText(user->get_users_name());
     ui->phone_settings_input->setText(user->get_users_phone());
     ui->path_settings_input->setText(user->get_def_path());

     ui->name_settings_input->setEnabled(false);
     ui->phone_settings_input->setEnabled(false);
     ui->path_settings_input->setEnabled(false);

     ui->change_path_settings_button->setVisible(false);
     ui->program_pages->setCurrentIndex(1);
}

void MainWindow::load_settings() {

    qDebug() << "Loading Settings";
    QSettings settings("LightSensorManager", "ls_settings");
    settings.beginGroup("MainWindow");
    user->set_users_name(settings.value("users_name").toString());
    user->set_users_phone(settings.value("users_phone").toString());
    user->set_def_path(settings.value("def_path").toString());
    set_default_path();

    qDebug() << "Settings Loaded"<<user->get_users_name() <<user->get_users_phone()<<user->get_def_path();

    settings.endGroup();
}

void MainWindow::save_settings() {
    qDebug()<<"Saving Settings";

    ui->name_settings_input->setEnabled(false);
    ui->phone_settings_input->setEnabled(false);
    ui->path_settings_input->setEnabled(false);

    QString name_input = ui->name_settings_input->text();
    QString phone_input = ui->phone_settings_input->text();
    QString path_input = ui->path_settings_input->text();
    ui->change_path_settings_button->setVisible(false);

    QSettings settings("LightSensorManager", "ls_settings");
    settings.beginGroup("MainWindow");
    settings.setValue("users_name", name_input);
    settings.setValue("users_phone", phone_input);
    settings.setValue("def_path", path_input);

    settings.endGroup();

}
void MainWindow::on_save_settings_button_clicked()
{
    save_settings();
}


void MainWindow::on_edit_settings_button_clicked()
{
    ui->name_settings_input->setEnabled(true);
    ui->phone_settings_input->setEnabled(true);
    ui->path_settings_input->setEnabled(true);
    ui->change_path_settings_button->setVisible(true);
}


void MainWindow::on_change_path_settings_button_clicked()
{
    qDebug() << "Function: change_path_settings()";
    QString temp_path = QFileDialog::getExistingDirectory();
    if((temp_path.length())!=0) {
        ui->path_settings_input->setText(temp_path);
    }
}



void MainWindow::on_continue_from_location_button_clicked()
{
    light_sensor->set_current_location(ui->location_dropdown->currentText());
    light_sensor->update_paths_with_location();

    ui->program_pages->setCurrentIndex(4);
    ui->dev_ser_num->setText(light_sensor->get_serial_num());
    send_command("uid");
    ui->flash_usage_bar->setValue(0);
    ui->data_read_bar->setValue(0);
    ui->path_edit->setText(light_sensor->get_base_path());

}

/**
 * *****************************************************************
 * @brief Back Button handler functions
 * *****************************************************************
 */
// Back button on serial input page
void MainWindow::on_back_serial_button_clicked()
{
    ui->program_pages->setCurrentIndex(0);
}

// Back button on settings page
void MainWindow::on_back_settings_button_clicked()
{
    ui->program_pages->setCurrentIndex(0);
}

// Back button on memory info page
void MainWindow::on_back_mem_button_clicked()
{
    qDebug()<<"Function: on_back_mem_button_clicked()";
    ui->program_pages->setCurrentIndex(4);
}

// Back button on deploy light sensor page
void MainWindow::on_back_deploy_button_clicked()
{
    qDebug()<<"Function: on_back_deploy_button_clicked()";
    ui->program_pages->setCurrentIndex(4);
}
// Back button on location manager page
void MainWindow::on_back_loc_man_button_clicked()
{
    ui->program_pages->setCurrentIndex(0);
}



/**
 * *****************************************************************
 * @brief QComboBox handler functions
 * *****************************************************************
 */
void MainWindow::on_location_dropdown_currentIndexChanged(int index)
{
    ui->location_dropdown->setCurrentIndex(index);
    QString loc = ui->location_dropdown->currentText();
    ui->location_dropdown->setCurrentText(loc);
    if (loc == "New Location") {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Enter Name of New Location"), tr("Location:"), QLineEdit::Normal,"New Location", &ok);
        QString new_dir = light_sensor->get_def_path() + "/" +text;
        new_dir = QDir::toNativeSeparators(new_dir);

        if(ok && !text.isEmpty())
            helper_functions::make_directory(new_dir);

        int num_items = ui->location_dropdown->count();
        ui->location_dropdown->insertItem(num_items, text);
        ui->location_dropdown->setCurrentText(text);
        ui->location_dropdown->setCurrentIndex(num_items);
    }

    qDebug()<< "Location selected 1st: "<<loc;
    int temp_index = ui->location_dropdown->currentIndex();
    light_sensor->set_location_index(temp_index);
}

void MainWindow::on_deploy_location_currentIndexChanged(int index)
{
    ui->deploy_location->setCurrentIndex(index);
    QString loc = ui->deploy_location->currentText();
    ui->deploy_location->setCurrentText(loc);
    qDebug()<< "Location selected Deploy: "<<loc;

    if (loc == "New Location") {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Enter Name of New Location"), tr("Location:"), QLineEdit::Normal,"New Location", &ok);
        QString new_dir = light_sensor->get_def_path() + "/" +text;
        new_dir = QDir::toNativeSeparators(new_dir);

        if(ok && !text.isEmpty())
            helper_functions::make_directory(new_dir);
        int num_items = ui->location_dropdown->count();
        ui->deploy_location->insertItem(num_items, text);
        ui->deploy_location->setCurrentText(text);
        ui->deploy_location->setCurrentIndex(num_items);
    }

    int temp_index = ui->deploy_location->currentIndex();
    light_sensor->set_location_index(temp_index);
    light_sensor->set_current_location(loc);
//    light_sensor->update_paths_with_location();
}


void MainWindow::on_manage_loc_button_clicked()
{
    ui->program_pages->setCurrentIndex(8);
}


void MainWindow::on_location_tree_view_clicked(const QModelIndex &index)
{
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->location_list_view->setRootIndex(subDirs->setRootPath(sPath));
}



/**
 * *****************************************************************
 * @brief Location manager adding and removing locations
 * *****************************************************************
 */

void MainWindow::on_new_location_button_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Name of New Location"), tr("Location:"), QLineEdit::Normal,"New Location", &ok);
    QString new_dir = light_sensor->get_def_path() + "/" +text;
    new_dir = QDir::toNativeSeparators(new_dir);

    if(ok && !text.isEmpty())
        helper_functions::make_directory(new_dir);
}

void MainWindow::remove_location() {
    QModelIndex curr_index = ui->location_tree_view->currentIndex();
    QString sPath = dirModel->fileInfo(curr_index).absoluteFilePath();
    QDir dir_remove(sPath);

    dir_remove.removeRecursively();
}

void MainWindow::on_remove_location_button_clicked()
{
    QMessageBox msgBox;

    msgBox.setText("Delete Location");
    msgBox.setInformativeText("Deleting location deletes all device data in location directory. Do you wish to continue?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch(ret){
        case QMessageBox::Ok:
            remove_location();
            break;

        case QMessageBox::Cancel:
            break;

        default:
            break;
    }

}


void MainWindow::on_back_lock_sel_button_clicked()
{
    ui->program_pages->setCurrentIndex(3);
}


void MainWindow::on_skip_download_button_clicked()
{
    ui->collection_pages->setCurrentIndex(1);
}

void MainWindow::on_location_list_view_clicked(const QModelIndex &index)
{
    qDebug()<<index;
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    sPath += "/device_info.txt";

    qDebug()<<"Function: file_saving::get_largest_data_index()";

    QFile file(sPath);

    // Check if file already exists
    if(!file.open(QIODevice:: ReadOnly)) {
        qDebug() << "Cannot Open Device Info File";
        return;
    }

    file.open(QIODevice:: ReadOnly);

    QTextStream in(&file);
    QStringList temp_list;
    while(!file.atEnd()) {
        temp_list <<file.readLine();
    }
    file.close();
    if (temp_list.length() > 4) {
        QString hint = temp_list[4];
        qDebug()<< "Device locaiton hint: "<< hint;

        QMessageBox msgBox;

        msgBox.setText("Location Description from Last Deployment");
        msgBox.setInformativeText(hint);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else {
        qDebug()<<"Invalid device information file";
    }
}

/**
 * @brief Back button for check connection page
 */
void MainWindow::on_back_check_button_clicked()
{
   ui->program_pages->setCurrentIndex(2);
}

/**
 * @brief Skip Serial Number input page. For DEBUG use only.
 */
void MainWindow::on_skip_serial_clicked()
{
    ui->program_pages->setCurrentIndex(3);
}

/**
 * @brief Skip Check Connection page. For DEBUG use only.
 */
void MainWindow::on_skip_check_button_clicked()
{
    ui->program_pages->setCurrentIndex(4);
}

/**
 * @brief Back button for check connection page
 */
void MainWindow::on_back_data_button_clicked()
{
    ui->program_pages->setCurrentIndex(7);
}



void MainWindow::on_ports_box_currentIndexChanged(int index)
{
    ui->ports_box->setCurrentIndex(index);
    QString port = ui->ports_box->currentText();
    ui->ports_box->setCurrentText(port);
    qDebug()<< "Port Selected: "<<port;
}

