#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "helper_functions.h"
#include "file_saving.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void progress(int value);
    void ready (int value);
    void next_command(QString next_command);
    void function_step(int value);
    void deployment_step(int value);

private slots:
    int on_ReceivedData();
    bool check_command(QByteArray response);
    void on_serial_enter_clicked();
    void on_check_conn_button_clicked();
    void on_continue_button_clicked();
    void on_get_flash_info_clicked();
    void on_change_path_button_clicked();
    void on_collect_button_clicked();
    void on_get_last_location_clicked();
    void on_change_location_button_clicked();
    void on_data_read_bar_valueChanged(int value);
    void collection_functions(int value);
    void on_new_device_button_clicked();
    void on_mem_page_button_clicked();
    void on_deploy_button_clicked();
    void on_back_mem_button_clicked();

    void on_back_deploy_button_clicked();

    void on_use_last_button_clicked();

    void on_deploy_light_sensor_clicked();
    void deployment_functions(int value);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QSerialPort *mSerial;
    QList<QSerialPortInfo> mSerialPorts;
    void intialize_program();
    void updateSerialPorts();
    void get_uid();
    int get_largest_data_index(QString filename);
    void change_path(QString new_path);
    void set_default_path();
    void save_to_file(QList<QByteArray> lines, int file_type );
    void save_collection_record();

    void open_port_for_commun();
    void send_command(QString command);
    void update_device_directory();

    // Global Variables for use in program
    QString last_command;
    QString device_uid;
    QString device_serial_num;
    qint16 num_records;
    QString saving_path;
    QString device_dir;
    int collection_progress;
    int downloading_data;
    QString device_latitude;
    QString device_longitude;
    int collection_complete;
    int sensor_deployment;
    QString device_time;
};
#endif // MAINWINDOW_H
