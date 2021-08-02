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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *user_options;
    QWidget *collect_tab;
    QPushButton *data_button;
    QWidget *setup_tab;
    QPushButton *ds_button;
    QPushButton *ts_button;
    QPushButton *calibrate_button;
    QPushButton *ef_button;
    QPushButton *log_button;
    QPushButton *pushButton_2;
    QWidget *command_line;
    QPushButton *tr_button;
    QPushButton *dr_button;
    QPushButton *sample_button;
    QPushButton *tsl237_button;
    QPushButton *batt_button;
    QTabWidget *device_connection;
    QWidget *tab;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *conn_label;
    QLabel *status_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *device_label;
    QComboBox *device_list;
    QPushButton *connect_button;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dev_uid_label;
    QLabel *uid_label;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *output_label;
    QTextEdit *output_box;
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
        centralwidget->setMaximumSize(QSize(800, 16777215));
        centralwidget->setAutoFillBackground(true);
        user_options = new QTabWidget(centralwidget);
        user_options->setObjectName(QString::fromUtf8("user_options"));
        user_options->setGeometry(QRect(90, 170, 641, 151));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(user_options->sizePolicy().hasHeightForWidth());
        user_options->setSizePolicy(sizePolicy);
        user_options->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(14);
        user_options->setFont(font);
        user_options->setAutoFillBackground(true);
        user_options->setTabShape(QTabWidget::Rounded);
        user_options->setElideMode(Qt::ElideRight);
        collect_tab = new QWidget();
        collect_tab->setObjectName(QString::fromUtf8("collect_tab"));
        data_button = new QPushButton(collect_tab);
        data_button->setObjectName(QString::fromUtf8("data_button"));
        data_button->setGeometry(QRect(250, 30, 112, 32));
        user_options->addTab(collect_tab, QString());
        setup_tab = new QWidget();
        setup_tab->setObjectName(QString::fromUtf8("setup_tab"));
        ds_button = new QPushButton(setup_tab);
        ds_button->setObjectName(QString::fromUtf8("ds_button"));
        ds_button->setGeometry(QRect(110, 20, 121, 32));
        ts_button = new QPushButton(setup_tab);
        ts_button->setObjectName(QString::fromUtf8("ts_button"));
        ts_button->setGeometry(QRect(110, 60, 121, 32));
        calibrate_button = new QPushButton(setup_tab);
        calibrate_button->setObjectName(QString::fromUtf8("calibrate_button"));
        calibrate_button->setGeometry(QRect(400, 20, 112, 32));
        ef_button = new QPushButton(setup_tab);
        ef_button->setObjectName(QString::fromUtf8("ef_button"));
        ef_button->setGeometry(QRect(400, 60, 112, 32));
        log_button = new QPushButton(setup_tab);
        log_button->setObjectName(QString::fromUtf8("log_button"));
        log_button->setGeometry(QRect(260, 60, 112, 32));
        pushButton_2 = new QPushButton(setup_tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 20, 112, 32));
        user_options->addTab(setup_tab, QString());
        command_line = new QWidget();
        command_line->setObjectName(QString::fromUtf8("command_line"));
        tr_button = new QPushButton(command_line);
        tr_button->setObjectName(QString::fromUtf8("tr_button"));
        tr_button->setGeometry(QRect(30, 20, 141, 32));
        dr_button = new QPushButton(command_line);
        dr_button->setObjectName(QString::fromUtf8("dr_button"));
        dr_button->setGeometry(QRect(30, 60, 141, 32));
        sample_button = new QPushButton(command_line);
        sample_button->setObjectName(QString::fromUtf8("sample_button"));
        sample_button->setGeometry(QRect(190, 20, 131, 32));
        tsl237_button = new QPushButton(command_line);
        tsl237_button->setObjectName(QString::fromUtf8("tsl237_button"));
        tsl237_button->setGeometry(QRect(190, 60, 131, 32));
        batt_button = new QPushButton(command_line);
        batt_button->setObjectName(QString::fromUtf8("batt_button"));
        batt_button->setGeometry(QRect(340, 20, 112, 32));
        user_options->addTab(command_line, QString());
        device_connection = new QTabWidget(centralwidget);
        device_connection->setObjectName(QString::fromUtf8("device_connection"));
        device_connection->setGeometry(QRect(260, 0, 291, 151));
        device_connection->setFont(font);
        device_connection->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 1, 284, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        conn_label = new QLabel(widget);
        conn_label->setObjectName(QString::fromUtf8("conn_label"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        conn_label->setFont(font1);

        horizontalLayout->addWidget(conn_label);

        status_label = new QLabel(widget);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        QFont font2;
        font2.setPointSize(13);
        status_label->setFont(font2);

        horizontalLayout->addWidget(status_label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        device_label = new QLabel(widget);
        device_label->setObjectName(QString::fromUtf8("device_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(device_label->sizePolicy().hasHeightForWidth());
        device_label->setSizePolicy(sizePolicy1);
        device_label->setFont(font1);
        device_label->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(device_label);

        device_list = new QComboBox(widget);
        device_list->setObjectName(QString::fromUtf8("device_list"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(device_list->sizePolicy().hasHeightForWidth());
        device_list->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(device_list);


        verticalLayout->addLayout(horizontalLayout_2);

        connect_button = new QPushButton(widget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        sizePolicy2.setHeightForWidth(connect_button->sizePolicy().hasHeightForWidth());
        connect_button->setSizePolicy(sizePolicy2);
        connect_button->setFont(font);
        connect_button->setAcceptDrops(false);
        connect_button->setAutoFillBackground(false);
        connect_button->setStyleSheet(QString::fromUtf8("backgroundColourButton->setStyleSheet(\"background-color: red\");\n"
"\n"
""));
        connect_button->setAutoDefault(false);
        connect_button->setFlat(false);

        verticalLayout->addWidget(connect_button);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dev_uid_label = new QLabel(widget);
        dev_uid_label->setObjectName(QString::fromUtf8("dev_uid_label"));
        dev_uid_label->setFont(font1);
        dev_uid_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(dev_uid_label);

        uid_label = new QLabel(widget);
        uid_label->setObjectName(QString::fromUtf8("uid_label"));

        horizontalLayout_3->addWidget(uid_label);


        verticalLayout->addLayout(horizontalLayout_3);

        device_connection->addTab(tab, QString());
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(150, 340, 521, 191));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        output_label = new QLabel(widget1);
        output_label->setObjectName(QString::fromUtf8("output_label"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        output_label->setFont(font3);
        output_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(output_label);

        output_box = new QTextEdit(widget1);
        output_box->setObjectName(QString::fromUtf8("output_box"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(output_box->sizePolicy().hasHeightForWidth());
        output_box->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(output_box);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        user_options->setCurrentIndex(0);
        device_connection->setCurrentIndex(0);
        connect_button->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IULS Dashboard", nullptr));
        data_button->setText(QCoreApplication::translate("MainWindow", "Collect Data", nullptr));
        user_options->setTabText(user_options->indexOf(collect_tab), QCoreApplication::translate("MainWindow", "Collect Data", nullptr));
        ds_button->setText(QCoreApplication::translate("MainWindow", "Set Date (ds)", nullptr));
        ts_button->setText(QCoreApplication::translate("MainWindow", "Set Time (ts)", nullptr));
        calibrate_button->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
        ef_button->setText(QCoreApplication::translate("MainWindow", "Erase Flash", nullptr));
        log_button->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Sample", nullptr));
        user_options->setTabText(user_options->indexOf(setup_tab), QCoreApplication::translate("MainWindow", "Device Setup", nullptr));
        tr_button->setText(QCoreApplication::translate("MainWindow", "Report Time (tr)", nullptr));
        dr_button->setText(QCoreApplication::translate("MainWindow", "Report Data (dr)", nullptr));
        sample_button->setText(QCoreApplication::translate("MainWindow", "Sample", nullptr));
        tsl237_button->setText(QCoreApplication::translate("MainWindow", "TSL237", nullptr));
        batt_button->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        user_options->setTabText(user_options->indexOf(command_line), QCoreApplication::translate("MainWindow", "Commands", nullptr));
        conn_label->setText(QCoreApplication::translate("MainWindow", "Device Connection Status:", nullptr));
        status_label->setText(QCoreApplication::translate("MainWindow", "Not Connected", nullptr));
        device_label->setText(QCoreApplication::translate("MainWindow", "Select Device", nullptr));
        connect_button->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        dev_uid_label->setText(QCoreApplication::translate("MainWindow", "UID:", nullptr));
        uid_label->setText(QCoreApplication::translate("MainWindow", "Not Connected", nullptr));
        device_connection->setTabText(device_connection->indexOf(tab), QCoreApplication::translate("MainWindow", "Connect to Device", nullptr));
        output_label->setText(QCoreApplication::translate("MainWindow", "Device Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
