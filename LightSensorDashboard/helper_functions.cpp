#include "helper_functions.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDate>

helper_functions::helper_functions()
{


}
// Testing github
void helper_functions::print_message()
{
    qDebug() << "\n\n WE ARE IN THE HELPER FUNCTION FILE";

}

/**
 * @brief Function to get current date based
 * @arg Function takes no arguments
 * @return Formated date set command string (i.e: "ds,1,1,2021")
 */
QString helper_functions::get_current_date() {

    qDebug()<<"Function: get_current_date()";
    QString date;

    QDate cd = QDate::currentDate();
    date = "ds," + cd.toString("MM,dd,yyyy");

    qDebug()<<"Current Date: "<< date;

    return date;
}
