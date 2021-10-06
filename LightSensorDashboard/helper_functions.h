#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "mainwindow.h"

class helper_functions
{

public:
    helper_functions();
    static QString get_current_date();
    static QString get_current_time();
    static QString get_device_dir(QString path, QString ser_num, QString dev_uid);
    static QString check_if_directory_exists(QString device_directory);
    static QString parse_past_records(QStringList);
    static QString get_current_time_deployment();
};

#endif // HELPER_FUNCTIONS_H
