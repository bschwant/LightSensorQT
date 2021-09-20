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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *serial_direction;
    QLineEdit *serial_num_input;
    QPushButton *serial_enter;
    QWidget *check_connection;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *check_conn_label;
    QPushButton *check_conn_button;
    QPushButton *continue_button;
    QLabel *img_status_label;
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
    QProgressBar *data_read_bar;
    QLabel *file_location_label;
    QLineEdit *path_edit;
    QPushButton *change_path_button;
    QLabel *download_label;
    QPushButton *collect_button;
    QLabel *sensor_location_label;
    QLabel *loc_instruct_label;
    QLabel *note_label;
    QFrame *line_4;
    QTextEdit *note_input;
    QWidget *layoutWidget2;
    QVBoxLayout *longitude_label;
    QLineEdit *longitude_edit;
    QLabel *long_label;
    QWidget *layoutWidget3;
    QVBoxLayout *latitude_layout;
    QLineEdit *latitude_edit;
    QLabel *lat_label;
    QLabel *curr_status_label;
    QLabel *curr_task_label;
    QPushButton *get_last_location;
    QPushButton *change_location_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(192, 192, 192, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(223, 223, 223, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(96, 96, 96, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(128, 128, 128, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(800, 16777215));
        centralwidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        program_pages = new QStackedWidget(centralwidget);
        program_pages->setObjectName(QString::fromUtf8("program_pages"));
        program_pages->setAcceptDrops(false);
        program_pages->setAutoFillBackground(false);
        get_serial_number = new QWidget();
        get_serial_number->setObjectName(QString::fromUtf8("get_serial_number"));
        layoutWidget = new QWidget(get_serial_number);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 130, 281, 151));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        serial_direction = new QLabel(layoutWidget);
        serial_direction->setObjectName(QString::fromUtf8("serial_direction"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        serial_direction->setFont(font);
        serial_direction->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        serial_direction->setWordWrap(true);

        verticalLayout_3->addWidget(serial_direction);

        serial_num_input = new QLineEdit(layoutWidget);
        serial_num_input->setObjectName(QString::fromUtf8("serial_num_input"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serial_num_input->sizePolicy().hasHeightForWidth());
        serial_num_input->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(serial_num_input);

        serial_enter = new QPushButton(layoutWidget);
        serial_enter->setObjectName(QString::fromUtf8("serial_enter"));
        sizePolicy1.setHeightForWidth(serial_enter->sizePolicy().hasHeightForWidth());
        serial_enter->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        serial_enter->setFont(font1);
        serial_enter->setAcceptDrops(false);
        serial_enter->setLayoutDirection(Qt::LeftToRight);
        serial_enter->setAutoFillBackground(false);
        serial_enter->setAutoDefault(false);
        serial_enter->setFlat(false);

        verticalLayout_3->addWidget(serial_enter);

        program_pages->addWidget(get_serial_number);
        check_connection = new QWidget();
        check_connection->setObjectName(QString::fromUtf8("check_connection"));
        layoutWidget1 = new QWidget(check_connection);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(250, 130, 281, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        check_conn_label = new QLabel(layoutWidget1);
        check_conn_label->setObjectName(QString::fromUtf8("check_conn_label"));
        check_conn_label->setEnabled(true);
        check_conn_label->setFont(font);
        check_conn_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        check_conn_label->setWordWrap(true);

        verticalLayout_2->addWidget(check_conn_label);

        check_conn_button = new QPushButton(layoutWidget1);
        check_conn_button->setObjectName(QString::fromUtf8("check_conn_button"));
        check_conn_button->setFont(font1);
        check_conn_button->setAcceptDrops(false);
        check_conn_button->setAutoFillBackground(false);
        check_conn_button->setFlat(false);

        verticalLayout_2->addWidget(check_conn_button);

        continue_button = new QPushButton(layoutWidget1);
        continue_button->setObjectName(QString::fromUtf8("continue_button"));
        continue_button->setFont(font1);
        continue_button->setAcceptDrops(true);
        continue_button->setAutoFillBackground(false);

        verticalLayout_2->addWidget(continue_button);

        img_status_label = new QLabel(check_connection);
        img_status_label->setObjectName(QString::fromUtf8("img_status_label"));
        img_status_label->setEnabled(true);
        img_status_label->setGeometry(QRect(340, 190, 121, 111));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(img_status_label->sizePolicy().hasHeightForWidth());
        img_status_label->setSizePolicy(sizePolicy2);
        img_status_label->setMinimumSize(QSize(0, 0));
        img_status_label->setMaximumSize(QSize(150, 150));
        img_status_label->setAcceptDrops(false);
        img_status_label->setLayoutDirection(Qt::RightToLeft);
        img_status_label->setAutoFillBackground(false);
        img_status_label->setFrameShape(QFrame::NoFrame);
        img_status_label->setPixmap(QPixmap(QString::fromUtf8(":/status/yellow.png")));
        img_status_label->setScaledContents(true);
        img_status_label->setAlignment(Qt::AlignCenter);
        img_status_label->setWordWrap(false);
        program_pages->addWidget(check_connection);
        device_info = new QWidget();
        device_info->setObjectName(QString::fromUtf8("device_info"));
        info_label = new QLabel(device_info);
        info_label->setObjectName(QString::fromUtf8("info_label"));
        info_label->setGeometry(QRect(20, 0, 161, 21));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        info_label->setFont(font2);
        dev_ser_num_label = new QLabel(device_info);
        dev_ser_num_label->setObjectName(QString::fromUtf8("dev_ser_num_label"));
        dev_ser_num_label->setGeometry(QRect(90, 40, 101, 16));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        dev_ser_num_label->setFont(font3);
        dev_uid_lab = new QLabel(device_info);
        dev_uid_lab->setObjectName(QString::fromUtf8("dev_uid_lab"));
        dev_uid_lab->setGeometry(QRect(330, 40, 31, 16));
        dev_uid_lab->setFont(font3);
        dev_ser_num = new QLabel(device_info);
        dev_ser_num->setObjectName(QString::fromUtf8("dev_ser_num"));
        dev_ser_num->setGeometry(QRect(200, 40, 101, 16));
        QFont font4;
        font4.setPointSize(14);
        dev_ser_num->setFont(font4);
        dev_uid = new QLabel(device_info);
        dev_uid->setObjectName(QString::fromUtf8("dev_uid"));
        dev_uid->setGeometry(QRect(370, 40, 181, 16));
        dev_uid->setFont(font4);
        flash_info_label = new QLabel(device_info);
        flash_info_label->setObjectName(QString::fromUtf8("flash_info_label"));
        flash_info_label->setGeometry(QRect(20, 80, 211, 21));
        flash_info_label->setFont(font2);
        flash_used_label = new QLabel(device_info);
        flash_used_label->setObjectName(QString::fromUtf8("flash_used_label"));
        flash_used_label->setGeometry(QRect(320, 160, 151, 16));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        flash_used_label->setFont(font5);
        flash_used_label->setAlignment(Qt::AlignCenter);
        flash_usage_bar = new QProgressBar(device_info);
        flash_usage_bar->setObjectName(QString::fromUtf8("flash_usage_bar"));
        flash_usage_bar->setGeometry(QRect(320, 130, 191, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush8(QColor(255, 147, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(255, 92, 63, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(127, 19, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(170, 25, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush12(QColor(255, 146, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush13(QColor(255, 38, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        flash_usage_bar->setPalette(palette1);
        flash_usage_bar->setAutoFillBackground(false);
        flash_usage_bar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 4px;\n"
"     background-color: rgb(255, 255, 255);\n"
"	text-align: right;\n"
"	margin-right: 6ex;\n"
" }\n"
"\n"
" QProgressBar::chunk {\n"
"     background-color:rgb(0, 150, 255);\n"
"	border-radius: 0px;\n"
"     width: 20px;\n"
" }\n"
"\n"
"\n"
""));
        flash_usage_bar->setValue(24);
        flash_usage_bar->setInvertedAppearance(false);
        flash_value = new QLabel(device_info);
        flash_value->setObjectName(QString::fromUtf8("flash_value"));
        flash_value->setGeometry(QRect(190, 130, 101, 21));
        get_flash_info = new QPushButton(device_info);
        get_flash_info->setObjectName(QString::fromUtf8("get_flash_info"));
        get_flash_info->setGeometry(QRect(610, 110, 141, 51));
        entries_label = new QLabel(device_info);
        entries_label->setObjectName(QString::fromUtf8("entries_label"));
        entries_label->setGeometry(QRect(90, 130, 91, 20));
        entries_label->setFont(font3);
        line_2 = new QFrame(device_info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(290, 180, 451, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(device_info);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(230, 80, 511, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        data_read_bar = new QProgressBar(device_info);
        data_read_bar->setObjectName(QString::fromUtf8("data_read_bar"));
        data_read_bar->setGeometry(QRect(590, 410, 181, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        data_read_bar->setPalette(palette2);
        data_read_bar->setLayoutDirection(Qt::LeftToRight);
        data_read_bar->setAutoFillBackground(false);
        data_read_bar->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 8px;\n"
"background: gray;\n"
"padding: 0px;\n"
"text-align: right;\n"
"margin-right: 6ex;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        data_read_bar->setValue(24);
        data_read_bar->setAlignment(Qt::AlignCenter);
        file_location_label = new QLabel(device_info);
        file_location_label->setObjectName(QString::fromUtf8("file_location_label"));
        file_location_label->setGeometry(QRect(90, 230, 121, 31));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setUnderline(true);
        font6.setWeight(50);
        file_location_label->setFont(font6);
        path_edit = new QLineEdit(device_info);
        path_edit->setObjectName(QString::fromUtf8("path_edit"));
        path_edit->setGeometry(QRect(200, 230, 411, 31));
        QFont font7;
        font7.setPointSize(12);
        path_edit->setFont(font7);
        change_path_button = new QPushButton(device_info);
        change_path_button->setObjectName(QString::fromUtf8("change_path_button"));
        change_path_button->setGeometry(QRect(610, 230, 141, 32));
        download_label = new QLabel(device_info);
        download_label->setObjectName(QString::fromUtf8("download_label"));
        download_label->setGeometry(QRect(20, 180, 261, 21));
        download_label->setFont(font2);
        collect_button = new QPushButton(device_info);
        collect_button->setObjectName(QString::fromUtf8("collect_button"));
        collect_button->setGeometry(QRect(600, 430, 141, 51));
        sensor_location_label = new QLabel(device_info);
        sensor_location_label->setObjectName(QString::fromUtf8("sensor_location_label"));
        sensor_location_label->setGeometry(QRect(90, 280, 121, 21));
        QFont font8;
        font8.setPointSize(16);
        font8.setUnderline(true);
        sensor_location_label->setFont(font8);
        sensor_location_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loc_instruct_label = new QLabel(device_info);
        loc_instruct_label->setObjectName(QString::fromUtf8("loc_instruct_label"));
        loc_instruct_label->setGeometry(QRect(70, 300, 161, 16));
        QFont font9;
        font9.setPointSize(10);
        font9.setItalic(true);
        loc_instruct_label->setFont(font9);
        loc_instruct_label->setAlignment(Qt::AlignCenter);
        note_label = new QLabel(device_info);
        note_label->setObjectName(QString::fromUtf8("note_label"));
        note_label->setGeometry(QRect(90, 370, 121, 21));
        note_label->setFont(font8);
        note_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line_4 = new QFrame(device_info);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(180, 0, 561, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        note_input = new QTextEdit(device_info);
        note_input->setObjectName(QString::fromUtf8("note_input"));
        note_input->setGeometry(QRect(90, 400, 271, 61));
        layoutWidget2 = new QWidget(device_info);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(230, 320, 127, 41));
        longitude_label = new QVBoxLayout(layoutWidget2);
        longitude_label->setSpacing(0);
        longitude_label->setObjectName(QString::fromUtf8("longitude_label"));
        longitude_label->setContentsMargins(0, 0, 0, 0);
        longitude_edit = new QLineEdit(layoutWidget2);
        longitude_edit->setObjectName(QString::fromUtf8("longitude_edit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(longitude_edit->sizePolicy().hasHeightForWidth());
        longitude_edit->setSizePolicy(sizePolicy3);

        longitude_label->addWidget(longitude_edit);

        long_label = new QLabel(layoutWidget2);
        long_label->setObjectName(QString::fromUtf8("long_label"));
        sizePolicy.setHeightForWidth(long_label->sizePolicy().hasHeightForWidth());
        long_label->setSizePolicy(sizePolicy);
        long_label->setFont(font9);
        long_label->setAlignment(Qt::AlignCenter);

        longitude_label->addWidget(long_label);

        layoutWidget3 = new QWidget(device_info);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(90, 320, 127, 41));
        latitude_layout = new QVBoxLayout(layoutWidget3);
        latitude_layout->setSpacing(0);
        latitude_layout->setObjectName(QString::fromUtf8("latitude_layout"));
        latitude_layout->setContentsMargins(0, 0, 0, 0);
        latitude_edit = new QLineEdit(layoutWidget3);
        latitude_edit->setObjectName(QString::fromUtf8("latitude_edit"));

        latitude_layout->addWidget(latitude_edit);

        lat_label = new QLabel(layoutWidget3);
        lat_label->setObjectName(QString::fromUtf8("lat_label"));
        lat_label->setFont(font9);
        lat_label->setAlignment(Qt::AlignCenter);

        latitude_layout->addWidget(lat_label);

        curr_status_label = new QLabel(device_info);
        curr_status_label->setObjectName(QString::fromUtf8("curr_status_label"));
        curr_status_label->setGeometry(QRect(620, 390, 111, 17));
        QFont font10;
        font10.setPointSize(10);
        font10.setBold(false);
        font10.setUnderline(false);
        font10.setWeight(50);
        curr_status_label->setFont(font10);
        curr_status_label->setAlignment(Qt::AlignCenter);
        curr_task_label = new QLabel(device_info);
        curr_task_label->setObjectName(QString::fromUtf8("curr_task_label"));
        curr_task_label->setGeometry(QRect(610, 360, 129, 19));
        curr_task_label->setFont(font6);
        get_last_location = new QPushButton(device_info);
        get_last_location->setObjectName(QString::fromUtf8("get_last_location"));
        get_last_location->setGeometry(QRect(90, 470, 131, 32));
        change_location_button = new QPushButton(device_info);
        change_location_button->setObjectName(QString::fromUtf8("change_location_button"));
        change_location_button->setGeometry(QRect(232, 470, 131, 32));
        program_pages->addWidget(device_info);
        layoutWidget2->raise();
        curr_status_label->raise();
        curr_task_label->raise();
        layoutWidget2->raise();
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
        data_read_bar->raise();
        file_location_label->raise();
        path_edit->raise();
        change_path_button->raise();
        download_label->raise();
        collect_button->raise();
        sensor_location_label->raise();
        loc_instruct_label->raise();
        note_label->raise();
        line_4->raise();
        note_input->raise();
        get_last_location->raise();
        change_location_button->raise();

        verticalLayout->addWidget(program_pages);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        program_pages->setCurrentIndex(2);
        serial_enter->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IULS Dashboard", nullptr));
        serial_direction->setText(QCoreApplication::translate("MainWindow", "Please Enter Device Serial Number", nullptr));
        serial_enter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        check_conn_label->setText(QCoreApplication::translate("MainWindow", "Check Connection To Light Sensor", nullptr));
        check_conn_button->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        continue_button->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        img_status_label->setText(QString());
        info_label->setText(QCoreApplication::translate("MainWindow", "Device Information", nullptr));
        dev_ser_num_label->setText(QCoreApplication::translate("MainWindow", "Serial Number:", nullptr));
        dev_uid_lab->setText(QCoreApplication::translate("MainWindow", "UID: ", nullptr));
        dev_ser_num->setText(QCoreApplication::translate("MainWindow", "serial_num", nullptr));
        dev_uid->setText(QCoreApplication::translate("MainWindow", "dev_uid", nullptr));
        flash_info_label->setText(QCoreApplication::translate("MainWindow", "Flash Memory Information", nullptr));
        flash_used_label->setText(QCoreApplication::translate("MainWindow", "Flash Memory Used", nullptr));
        flash_value->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        get_flash_info->setText(QCoreApplication::translate("MainWindow", "Get Usage Info ", nullptr));
        entries_label->setText(QCoreApplication::translate("MainWindow", "Total Entries:", nullptr));
        file_location_label->setText(QCoreApplication::translate("MainWindow", "File Location:", nullptr));
        path_edit->setText(QCoreApplication::translate("MainWindow", "/Users/brianschwantes/Dowloads/", nullptr));
        change_path_button->setText(QCoreApplication::translate("MainWindow", "Change File Path", nullptr));
        download_label->setText(QCoreApplication::translate("MainWindow", "Download Data from Light Sensor", nullptr));
        collect_button->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        sensor_location_label->setText(QCoreApplication::translate("MainWindow", "Sensor Location", nullptr));
        loc_instruct_label->setText(QCoreApplication::translate("MainWindow", "(Decimal Degree Format)", nullptr));
        note_label->setText(QCoreApplication::translate("MainWindow", "Collection Note", nullptr));
        long_label->setText(QCoreApplication::translate("MainWindow", "Longitude (-180 to 180)", nullptr));
        lat_label->setText(QCoreApplication::translate("MainWindow", "Latitude (-90 to 90)", nullptr));
        curr_status_label->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        curr_task_label->setText(QCoreApplication::translate("MainWindow", "Download Status:", nullptr));
        get_last_location->setText(QCoreApplication::translate("MainWindow", "Get Last Location", nullptr));
        change_location_button->setText(QCoreApplication::translate("MainWindow", "Change Location", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
