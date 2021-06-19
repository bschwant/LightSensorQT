/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *device_list;
    QTextEdit *textEdit;
    QLabel *command_label;
    QLabel *light_sensor_dash;
    QLabel *device_label;
    QLabel *baud_label;
    QComboBox *baud_list;
    QPushButton *connect_button;
    QPushButton *help_button;
    QPushButton *tr_button;
    QPushButton *dr_button;
    QPushButton *temp_button;
    QPushButton *batt_button;
    QPushButton *data_button;
    QLabel *output_label;
    QLabel *dev_conn;
    QTabWidget *tabWidget;
    QWidget *Setup;
    QWidget *Collection;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        device_list = new QComboBox(centralwidget);
        device_list->setObjectName(QString::fromUtf8("device_list"));
        device_list->setGeometry(QRect(180, 50, 241, 71));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(220, 180, 451, 181));
        command_label = new QLabel(centralwidget);
        command_label->setObjectName(QString::fromUtf8("command_label"));
        command_label->setGeometry(QRect(90, 150, 81, 16));
        light_sensor_dash = new QLabel(centralwidget);
        light_sensor_dash->setObjectName(QString::fromUtf8("light_sensor_dash"));
        light_sensor_dash->setGeometry(QRect(250, 10, 291, 41));
        QFont font;
        font.setPointSize(28);
        light_sensor_dash->setFont(font);
        device_label = new QLabel(centralwidget);
        device_label->setObjectName(QString::fromUtf8("device_label"));
        device_label->setGeometry(QRect(90, 70, 91, 20));
        baud_label = new QLabel(centralwidget);
        baud_label->setObjectName(QString::fromUtf8("baud_label"));
        baud_label->setGeometry(QRect(430, 70, 81, 16));
        baud_list = new QComboBox(centralwidget);
        baud_list->addItem(QString());
        baud_list->setObjectName(QString::fromUtf8("baud_list"));
        baud_list->setGeometry(QRect(510, 70, 101, 32));
        connect_button = new QPushButton(centralwidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setGeometry(QRect(220, 110, 181, 32));
        help_button = new QPushButton(centralwidget);
        help_button->setObjectName(QString::fromUtf8("help_button"));
        help_button->setGeometry(QRect(80, 170, 112, 32));
        tr_button = new QPushButton(centralwidget);
        tr_button->setObjectName(QString::fromUtf8("tr_button"));
        tr_button->setGeometry(QRect(80, 200, 112, 32));
        dr_button = new QPushButton(centralwidget);
        dr_button->setObjectName(QString::fromUtf8("dr_button"));
        dr_button->setGeometry(QRect(80, 230, 112, 32));
        temp_button = new QPushButton(centralwidget);
        temp_button->setObjectName(QString::fromUtf8("temp_button"));
        temp_button->setGeometry(QRect(80, 260, 112, 32));
        batt_button = new QPushButton(centralwidget);
        batt_button->setObjectName(QString::fromUtf8("batt_button"));
        batt_button->setGeometry(QRect(80, 290, 112, 32));
        data_button = new QPushButton(centralwidget);
        data_button->setObjectName(QString::fromUtf8("data_button"));
        data_button->setGeometry(QRect(80, 320, 112, 32));
        output_label = new QLabel(centralwidget);
        output_label->setObjectName(QString::fromUtf8("output_label"));
        output_label->setGeometry(QRect(380, 160, 91, 16));
        dev_conn = new QLabel(centralwidget);
        dev_conn->setObjectName(QString::fromUtf8("dev_conn"));
        dev_conn->setGeometry(QRect(430, 110, 141, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        dev_conn->setFont(font1);
        dev_conn->setAutoFillBackground(false);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(530, 340, 261, 201));
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(true);
        Setup = new QWidget();
        Setup->setObjectName(QString::fromUtf8("Setup"));
        tabWidget->addTab(Setup, QString());
        Collection = new QWidget();
        Collection->setObjectName(QString::fromUtf8("Collection"));
        tabWidget->addTab(Collection, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        command_label->setText(QCoreApplication::translate("MainWindow", "Commands", nullptr));
        light_sensor_dash->setText(QCoreApplication::translate("MainWindow", "Light Sensor Dashboard", nullptr));
        device_label->setText(QCoreApplication::translate("MainWindow", "Select Device", nullptr));
        baud_label->setText(QCoreApplication::translate("MainWindow", "Select Baud", nullptr));
        baud_list->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));

        connect_button->setText(QCoreApplication::translate("MainWindow", "Connect To Device", nullptr));
        help_button->setText(QCoreApplication::translate("MainWindow", "help", nullptr));
        tr_button->setText(QCoreApplication::translate("MainWindow", "Report Time", nullptr));
        dr_button->setText(QCoreApplication::translate("MainWindow", "Report Date", nullptr));
        temp_button->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        batt_button->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        data_button->setText(QCoreApplication::translate("MainWindow", "Get Data", nullptr));
        output_label->setText(QCoreApplication::translate("MainWindow", "Device Output", nullptr));
        dev_conn->setText(QCoreApplication::translate("MainWindow", "Device Not Connected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Setup), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Collection), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
