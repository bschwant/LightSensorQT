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
    void on_connect_button_clicked();
    void check_command(QByteArray response);
    void on_data_button_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QSerialPort *mSerial;
    QList<QSerialPortInfo> mSerialPorts;
    void updateSerialPorts();
    void get_uid();
    int get_largest_data_index(QString filename);
    void save_data(QList<QByteArray> lines);
};
#endif // MAINWINDOW_H
