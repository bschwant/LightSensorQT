#include "helper_functions.h"
//#include "ui_mainwindow.h"
#include "QDebug"
#include <QTime>
#include <QDate>

helper_functions::helper_functions()
{


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
 * @return Formated time set command string (i.e. "ts,12,30,27")
 */
QString helper_functions::get_current_time() {
    qDebug()<<"Function: get_current_time()";
    QString time;

    QTime ct = QTime::currentTime();
   // time = "ts,"+ct.toString("HH:m\n\r");
    time = ct.toString("HH:m");

    qDebug()<<"Current Time: "<< time;

    return time;
}

