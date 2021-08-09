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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *program_pages;
    QWidget *get_serial_number;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *serial_direction;
    QLineEdit *serial_num_input;
    QPushButton *serial_enter;
    QWidget *check_connection;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *check_conn_label;
    QLabel *status_img;
    QPushButton *check_conn_button;
    QPushButton *continue_button;
    QWidget *device_info;
    QLabel *info_label;
    QLabel *dev_ser_num_label;
    QLabel *dev_uid_lab;
    QLabel *dev_ser_num;
    QLabel *dev_uid;
    QLabel *flash_info_label;
    QLabel *flash_used_label;
    QProgressBar *flash_usage_bar;
    QLabel *flash_value;
    QPushButton *get_flash_info;
    QLabel *entries_label;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *read_data_label;
    QLabel *start_label;
    QLabel *end_label;
    QLabel *read_logs_label;
    QPushButton *read_data_button;
    QPushButton *read_logs_button;
    QProgressBar *data_read_bar;
    QProgressBar *data_read_bar_2;
    QLabel *location_label;
    QLineEdit *path_edit;
    QPushButton *change_path_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(800, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        centralwidget->setPalette(palette);
        centralwidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        program_pages = new QStackedWidget(centralwidget);
        program_pages->setObjectName(QString::fromUtf8("program_pages"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush6(QColor(235, 235, 235, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush7(QColor(245, 245, 245, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(117, 117, 117, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(157, 157, 157, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush10(QColor(192, 192, 192, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        program_pages->setPalette(palette1);
        program_pages->setAcceptDrops(false);
        program_pages->setAutoFillBackground(true);
        get_serial_number = new QWidget();
        get_serial_number->setObjectName(QString::fromUtf8("get_serial_number"));
        formLayoutWidget = new QWidget(get_serial_number);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(250, 140, 261, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 10, 10);
        serial_direction = new QLabel(formLayoutWidget);
        serial_direction->setObjectName(QString::fromUtf8("serial_direction"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        serial_direction->setFont(font);
        serial_direction->setAlignment(Qt::AlignCenter);
        serial_direction->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, serial_direction);

        serial_num_input = new QLineEdit(formLayoutWidget);
        serial_num_input->setObjectName(QString::fromUtf8("serial_num_input"));

        formLayout->setWidget(1, QFormLayout::FieldRole, serial_num_input);

        serial_enter = new QPushButton(formLayoutWidget);
        serial_enter->setObjectName(QString::fromUtf8("serial_enter"));
        QFont font1;
        font1.setPointSize(16);
        serial_enter->setFont(font1);
        serial_enter->setAcceptDrops(false);
        serial_enter->setAutoFillBackground(false);
        serial_enter->setAutoDefault(false);
        serial_enter->setFlat(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, serial_enter);

        program_pages->addWidget(get_serial_number);
        check_connection = new QWidget();
        check_connection->setObjectName(QString::fromUtf8("check_connection"));
        layoutWidget = new QWidget(check_connection);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 140, 271, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        check_conn_label = new QLabel(layoutWidget);
        check_conn_label->setObjectName(QString::fromUtf8("check_conn_label"));
        check_conn_label->setEnabled(true);
        check_conn_label->setFont(font);
        check_conn_label->setAlignment(Qt::AlignCenter);
        check_conn_label->setWordWrap(true);

        verticalLayout_2->addWidget(check_conn_label);

        status_img = new QLabel(layoutWidget);
        status_img->setObjectName(QString::fromUtf8("status_img"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        status_img->setFont(font2);
        status_img->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(status_img);

        check_conn_button = new QPushButton(layoutWidget);
        check_conn_button->setObjectName(QString::fromUtf8("check_conn_button"));
        check_conn_button->setFont(font1);
        check_conn_button->setAcceptDrops(false);
        check_conn_button->setFlat(false);

        verticalLayout_2->addWidget(check_conn_button);

        continue_button = new QPushButton(layoutWidget);
        continue_button->setObjectName(QString::fromUtf8("continue_button"));
        continue_button->setFont(font1);

        verticalLayout_2->addWidget(continue_button);

        program_pages->addWidget(check_connection);
        device_info = new QWidget();
        device_info->setObjectName(QString::fromUtf8("device_info"));
        info_label = new QLabel(device_info);
        info_label->setObjectName(QString::fromUtf8("info_label"));
        info_label->setGeometry(QRect(320, 20, 161, 21));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        info_label->setFont(font3);
        dev_ser_num_label = new QLabel(device_info);
        dev_ser_num_label->setObjectName(QString::fromUtf8("dev_ser_num_label"));
        dev_ser_num_label->setGeometry(QRect(210, 50, 101, 16));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        dev_ser_num_label->setFont(font4);
        dev_uid_lab = new QLabel(device_info);
        dev_uid_lab->setObjectName(QString::fromUtf8("dev_uid_lab"));
        dev_uid_lab->setGeometry(QRect(470, 50, 31, 16));
        dev_uid_lab->setFont(font4);
        dev_ser_num = new QLabel(device_info);
        dev_ser_num->setObjectName(QString::fromUtf8("dev_ser_num"));
        dev_ser_num->setGeometry(QRect(320, 50, 71, 16));
        QFont font5;
        font5.setPointSize(12);
        dev_ser_num->setFont(font5);
        dev_uid = new QLabel(device_info);
        dev_uid->setObjectName(QString::fromUtf8("dev_uid"));
        dev_uid->setGeometry(QRect(510, 50, 181, 31));
        dev_uid->setFont(font5);
        flash_info_label = new QLabel(device_info);
        flash_info_label->setObjectName(QString::fromUtf8("flash_info_label"));
        flash_info_label->setGeometry(QRect(290, 90, 211, 21));
        flash_info_label->setFont(font3);
        flash_used_label = new QLabel(device_info);
        flash_used_label->setObjectName(QString::fromUtf8("flash_used_label"));
        flash_used_label->setGeometry(QRect(400, 130, 71, 16));
        flash_used_label->setFont(font4);
        flash_usage_bar = new QProgressBar(device_info);
        flash_usage_bar->setObjectName(QString::fromUtf8("flash_usage_bar"));
        flash_usage_bar->setGeometry(QRect(480, 120, 171, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush11(QColor(214, 214, 214, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush11);
        QBrush brush12(QColor(255, 147, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush12);
        QBrush brush13(QColor(255, 92, 63, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(127, 19, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(170, 25, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush16(QColor(255, 146, 127, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush17(QColor(255, 38, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        flash_usage_bar->setPalette(palette2);
        flash_usage_bar->setAutoFillBackground(false);
        flash_usage_bar->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background: white;\n"
"padding: 0px;\n"
"text-align: right;\n"
"margin-right: 4ex;\n"
"background-color: rgb(214, 214, 214);"));
        flash_usage_bar->setValue(24);
        flash_usage_bar->setInvertedAppearance(false);
        flash_value = new QLabel(device_info);
        flash_value->setObjectName(QString::fromUtf8("flash_value"));
        flash_value->setGeometry(QRect(270, 130, 101, 16));
        get_flash_info = new QPushButton(device_info);
        get_flash_info->setObjectName(QString::fromUtf8("get_flash_info"));
        get_flash_info->setGeometry(QRect(310, 150, 141, 32));
        entries_label = new QLabel(device_info);
        entries_label->setObjectName(QString::fromUtf8("entries_label"));
        entries_label->setGeometry(QRect(210, 130, 58, 16));
        entries_label->setFont(font4);
        line_2 = new QFrame(device_info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 180, 711, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(device_info);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(30, 80, 711, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        read_data_label = new QLabel(device_info);
        read_data_label->setObjectName(QString::fromUtf8("read_data_label"));
        read_data_label->setGeometry(QRect(100, 280, 231, 21));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setUnderline(true);
        font6.setWeight(75);
        read_data_label->setFont(font6);
        start_label = new QLabel(device_info);
        start_label->setObjectName(QString::fromUtf8("start_label"));
        start_label->setGeometry(QRect(40, 320, 71, 16));
        start_label->setFont(font4);
        end_label = new QLabel(device_info);
        end_label->setObjectName(QString::fromUtf8("end_label"));
        end_label->setGeometry(QRect(40, 360, 58, 16));
        end_label->setFont(font4);
        read_logs_label = new QLabel(device_info);
        read_logs_label->setObjectName(QString::fromUtf8("read_logs_label"));
        read_logs_label->setGeometry(QRect(440, 280, 231, 21));
        read_logs_label->setFont(font6);
        read_data_button = new QPushButton(device_info);
        read_data_button->setObjectName(QString::fromUtf8("read_data_button"));
        read_data_button->setGeometry(QRect(70, 400, 112, 32));
        read_logs_button = new QPushButton(device_info);
        read_logs_button->setObjectName(QString::fromUtf8("read_logs_button"));
        read_logs_button->setGeometry(QRect(420, 400, 112, 32));
        data_read_bar = new QProgressBar(device_info);
        data_read_bar->setObjectName(QString::fromUtf8("data_read_bar"));
        data_read_bar->setGeometry(QRect(210, 400, 151, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        data_read_bar->setPalette(palette3);
        data_read_bar->setAutoFillBackground(false);
        data_read_bar->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background: white;\n"
"padding: 0px;\n"
"text-align: right;\n"
"margin-right: 4ex;\n"
"background-color: rgb(214, 214, 214);"));
        data_read_bar->setValue(24);
        data_read_bar_2 = new QProgressBar(device_info);
        data_read_bar_2->setObjectName(QString::fromUtf8("data_read_bar_2"));
        data_read_bar_2->setGeometry(QRect(540, 400, 151, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        data_read_bar_2->setPalette(palette4);
        data_read_bar_2->setAutoFillBackground(false);
        data_read_bar_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-radius: 8px;\n"
"background: white;\n"
"padding: 0px;\n"
"text-align: right;\n"
"margin-right: 4ex;\n"
"background-color: rgb(214, 214, 214);"));
        data_read_bar_2->setValue(24);
        location_label = new QLabel(device_info);
        location_label->setObjectName(QString::fromUtf8("location_label"));
        location_label->setGeometry(QRect(120, 240, 101, 16));
        location_label->setFont(font4);
        path_edit = new QLineEdit(device_info);
        path_edit->setObjectName(QString::fromUtf8("path_edit"));
        path_edit->setGeometry(QRect(240, 230, 321, 31));
        change_path_button = new QPushButton(device_info);
        change_path_button->setObjectName(QString::fromUtf8("change_path_button"));
        change_path_button->setGeometry(QRect(570, 230, 131, 32));
        label = new QLabel(device_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 200, 301, 21));
        label->setFont(font3);
        program_pages->addWidget(device_info);
        info_label->raise();
        dev_ser_num_label->raise();
        dev_uid_lab->raise();
        dev_ser_num->raise();
        dev_uid->raise();
        flash_info_label->raise();
        flash_used_label->raise();
        flash_value->raise();
        get_flash_info->raise();
        flash_usage_bar->raise();
        entries_label->raise();
        line_2->raise();
        line_3->raise();
        read_data_label->raise();
        start_label->raise();
        end_label->raise();
        read_logs_label->raise();
        read_data_button->raise();
        read_logs_button->raise();
        data_read_bar->raise();
        data_read_bar_2->raise();
        location_label->raise();
        path_edit->raise();
        change_path_button->raise();
        label->raise();

        verticalLayout->addWidget(program_pages);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        program_pages->setCurrentIndex(0);
        serial_enter->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IULS Dashboard", nullptr));
        serial_direction->setText(QCoreApplication::translate("MainWindow", "Please Enter Device Serial Number", nullptr));
        serial_enter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        check_conn_label->setText(QCoreApplication::translate("MainWindow", "Check Connection To Light Sensor", nullptr));
        status_img->setText(QCoreApplication::translate("MainWindow", "Not Connected", nullptr));
        check_conn_button->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        continue_button->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        info_label->setText(QCoreApplication::translate("MainWindow", "Device Information", nullptr));
        dev_ser_num_label->setText(QCoreApplication::translate("MainWindow", "Serial Number:", nullptr));
        dev_uid_lab->setText(QCoreApplication::translate("MainWindow", "UID: ", nullptr));
        dev_ser_num->setText(QCoreApplication::translate("MainWindow", "serial_num", nullptr));
        dev_uid->setText(QCoreApplication::translate("MainWindow", "dev_uid", nullptr));
        flash_info_label->setText(QCoreApplication::translate("MainWindow", "Flash Memory Information", nullptr));
        flash_used_label->setText(QCoreApplication::translate("MainWindow", "Flash Used:", nullptr));
        flash_value->setText(QCoreApplication::translate("MainWindow", "xxx / 11646", nullptr));
        get_flash_info->setText(QCoreApplication::translate("MainWindow", "Get Usage Info ", nullptr));
        entries_label->setText(QCoreApplication::translate("MainWindow", "Entries:", nullptr));
        read_data_label->setText(QCoreApplication::translate("MainWindow", "Read Data", nullptr));
        start_label->setText(QCoreApplication::translate("MainWindow", "Start Date:", nullptr));
        end_label->setText(QCoreApplication::translate("MainWindow", "End Date:", nullptr));
        read_logs_label->setText(QCoreApplication::translate("MainWindow", "Read Logs", nullptr));
        read_data_button->setText(QCoreApplication::translate("MainWindow", "Read Data", nullptr));
        read_logs_button->setText(QCoreApplication::translate("MainWindow", "Read Logs", nullptr));
        location_label->setText(QCoreApplication::translate("MainWindow", "Select Location:", nullptr));
        path_edit->setText(QCoreApplication::translate("MainWindow", "/Users/brianschwantes/Dowloads/", nullptr));
        change_path_button->setText(QCoreApplication::translate("MainWindow", "Change Location", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Download Data/Logs from Light Sensor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
