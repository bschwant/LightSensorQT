#include "helper_functions.h"
//#include "ui_mainwindow.h"
#include "QDebug"
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include "helper_functions.h"
#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>

helper_functions::helper_functions()
{


}

//QString helper_functions::get_location_hint(QString filename) {

////}
/**
 * @brief helper function to create string for the device directory
 * @param path
 * @param ser_num
 * @return
 */
QString helper_functions::get_device_dir(QString path, QString ser_num, QString dev_uid){
<<<<<<< HEAD
    QString new_dir = path + "/" + ser_num + "_" + dev_uid;
    new_dir = QDir::toNativeSeparators(new_dir);
=======
//    QString new_dir;
>>>>>>> development
//    new_dir.append(path);
//    new_dir.append("/");
//    new_dir.append(ser_num);
//    new_dir.append("_");
//    new_dir.append(dev_uid);
<<<<<<< HEAD
=======
    QString new_dir = path + "/" + ser_num + "_" + dev_uid;
    new_dir = QDir::toNativeSeparators(new_dir);
>>>>>>> development
    return new_dir;
}

/**
 * @brief helper function that checks if directory exists for connected device exists
 * @param device_directory input as <path>/<serial#>_<device uid>
 */
QString helper_functions::check_if_directory_exists(QString device_directory) {
    QDir dir(device_directory);
    if(!dir.exists())
        return "";
//       dir.mkpath(".");
    return device_directory;
}
QString helper_functions::make_directory(QString device_directory) {
    QDir dir(device_directory);
    if(!dir.exists())
//        return "";
       dir.mkpath(".");
    return device_directory;
}

QString helper_functions::parse_past_records(QStringList record_lines) {
    int len = record_lines.length();
    qDebug()<< "Num Lines in record:"<<len;

    QString temp_line;
    QString date = NULL;
    QString time;
    QString location;
    QString longitude;
    QString latitude;
    QString note;
    QStringList temp_list;

    qDebug()<< "Record lines:"<<record_lines;
   for (int i = len-1; date==NULL; i--) {
   // while(date == NULL) {
        temp_line = record_lines[i];
        if (temp_line == "-------------------------------------------------------------")
            continue;
        qDebug()<<"Parsed Line:"<< temp_line;

        temp_list = temp_line.split(':');

        if (temp_list[0] == "Location") {
            location = temp_list[1];
            temp_list = location.split(',');
            longitude = temp_list[1];
            latitude = temp_list[0];
        }
        else if(temp_list[0] == "Collection Time") {
            time = temp_list[1]+':'+temp_list[2];
        }
        else if(temp_list[0] == "Collection Date") {
            date= temp_list[1];
        }
        else if(temp_list[0] == "Note") {
            note= temp_list[1];
        }
    }
    QString return_string = latitude+','+longitude+','+date+','+time+','+note;
    return return_string;
}

/**
 * @brief Function to get current date based on system
 * @arg Function takes no arguments
 * @return Formated date set command string (i.e: "ds,1,1,2021")
 */
QString helper_functions::get_current_date() {

    qDebug()<<"Function: get_current_date()";
    QString date;

    QDate cd = QDate::currentDate();
//    date = "ds," + cd.toString("MM/dd/yyyy\n\r");
     date = cd.toString("MM/dd/yyyy");

    qDebug()<<"Current Date: "<< date;

    return date;
}

/**
 * @brief Function to get current time based on system
 * @arg Function takes no arguments
 * @return Formated time (i.e. 12:30:27")
 */
QString helper_functions::get_current_time() {
    qDebug()<<"Function: get_current_time()";
    QString time;

    QTime ct = QTime::currentTime();
   // time = "ts,"+ct.toString("HH:mm,\n\r");
    time = ct.toString("HH:mm:ss");

    qDebug()<<"Current Time: "<< time;

    return time;
}

/**
 * @brief Function to get current time based on system for sensor deployment
 * @return Formated time same as tr return for sensor (i.e. 12,30,27")
 */
QString helper_functions::get_current_time_deployment() {
    qDebug()<<"Function: get_current_time()";
    QString time;

    QTime ct = QTime::currentTime();
   // time = "ts,"+ct.toString("HH:mm,\n\r");
    time = "ts,"+ct.toString("HH,mm,ss");

    //qDebug()<<"Current Time: "<< time;

    return time;
}

