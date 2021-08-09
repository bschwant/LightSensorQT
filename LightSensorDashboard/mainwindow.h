#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "helper_functions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ReceivedData();
//    void on_connect_button_clicked();
    bool check_command(QByteArray response);

//    void on_data_button_clicked();

//    void on_ds_button_clicked();

//    void on_batt_button_clicked();

//    void on_help_button_clicked();

//    void on_ts_button_clicked();

//    void on_sample_button_clicked();

//    void on_ef_button_clicked();

//    void on_log_button_clicked();

//    void on_ef_all_button_clicked();

    void on_serial_enter_clicked();

    void on_check_conn_button_clicked();

    void on_continue_button_clicked();

//    void on_flash_usage_bar_valueChanged(int value);

    void on_get_flash_info_clicked();

    void on_read_data_button_clicked();

    void on_read_logs_button_clicked();

    void on_change_path_button_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QSerialPort *mSerial;
    QList<QSerialPortInfo> mSerialPorts;
    void updateSerialPorts();
    void get_uid();
    int get_largest_data_index(QString filename);
    void save_data(QList<QByteArray> lines);
    void save_logs(QList<QByteArray> lines);
    void change_path(QString new_path);
    void set_default_path();

    void open_port_for_commun();
    void send_command(QString command);

    // Global Variables for use in program
    QString last_command;
    QString device_uid;
    QString device_serial_num;
    qint16 num_records;
    QString saving_path;
};
#endif // MAINWINDOW_H
