#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <string.h>
#include <qbytearray.h>

//QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Light Sensor Interface");
    serial = new QSerialPort(this);
    updateSerialPorts();

}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

// Update combo box to display all serial devices
void MainWindow::updateSerialPorts()
{
    mSerialPorts = QSerialPortInfo::availablePorts();

    ui-> device_list -> clear();
    for (QSerialPortInfo port : mSerialPorts) {
        ui->device_list->addItem(port.portName(), port.systemLocation());
    }
}

// Connect to device selected in devices combo box
void MainWindow::on_connect_button_clicked()
{
    qDebug() << "Connect Button Clicked";

    // Get device name from list of serial devices
    QString device_name  =  ui->device_list->currentData().toString();

    // Get baud rate from list of baud's
    // Currently not used because setting baud rate needs "QSerialPort::Baud9600" format
    QString baud_sel =  ui->baud_list->currentData().toString();

    qDebug() << "Connecting with device " << device_name;

    serial->setPortName(device_name);
   // mSerial->setBaudRate(baud_sel.toInt());
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    if(serial->isOpen() == true) {
        qDebug() << "Serial is open";
        connect(serial, SIGNAL(readyRead()), this, SLOT(on_ReceivedData()));
        serial->setDataTerminalReady(true);
        ui->dev_conn->setText("Device Connected");
    }
    else {
        qDebug() << "Error opening connection";
    }
}

// Handles recieved data from connected device
void MainWindow::on_ReceivedData()
{
    // Recieving Data
    QByteArray data;
    while(serial->waitForReadyRead(1000)) {
        data.append(serial->readAll());
    }
    int len = data.count();
    len = len - 26;
    data.replace(len, 26, "");
    ui ->textEdit -> setText(data);
    qDebug() << data << data.count();

    check_command(data);
}

// Send help command to light sensor
void MainWindow::on_help_button_clicked()
{
    qDebug()<< "Sending 'help' command";
    QString text = "help\n\r";
    serial->write(text.toStdString().c_str());
}

// Send time report command to light sensor
void MainWindow::on_tr_button_clicked()
{
    qDebug()<< "Sending 'tr' command";
    QString text = "tr\n\r";
    serial->write(text.toStdString().c_str());
}

// Send date report command to light sensor
void MainWindow::on_dr_button_clicked()
{
    qDebug()<< "Sending 'dr' command";
    QString text = "dr\n\r";
    serial->write(text.toStdString().c_str());
}

// Send temperature command to light sensor
void MainWindow::on_temp_button_clicked()
{
    qDebug()<< "Sending 'temp' command";
    QString text = "temp\n\r";
    serial->write(text.toStdString().c_str());
}

// Send battery command to light sensor
void MainWindow::on_batt_button_clicked()
{
    qDebug()<< "Sending 'batt' command";
    QString text = "batt\n\r";
    serial->write(text.toStdString().c_str());
}

// Send data command to light sensor
void MainWindow::on_data_button_clicked()
{
    qDebug()<< "Sending 'data' command";
    QString text = "data\n\r";
    serial->write(text.toStdString().c_str());
}

// Check for succusful command using OK or NOK
// Shows error in textbox if NOK is recieved
void MainWindow::check_command(QByteArray response)
{
    qDebug()<< "Made it to check command with response: "<< response;
    bool response_error;
    response_error = response.contains("NOK");

    if(response_error) {
        ui ->textEdit -> setText("NOK Recieved, try sending new command");
        qDebug()<<"INVALID COMMAND";
    }
    else {
        qDebug()<<"VALID COMMAND";
    }
  //  qDebug()<< "Contains:? "<<response.contains("NOK");

}




void MainWindow::on_tabWidget_currentChanged(int index)
{

}

