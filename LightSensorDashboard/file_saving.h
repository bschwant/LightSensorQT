#ifndef FILE_SAVING_H
#define FILE_SAVING_H

#include "mainwindow.h"

class file_saving
{
public:
    file_saving();
    static int get_largest_data_index(QString filename);
//    static QString get_location_hint
    static void save_device_info(QString filename, QStringList data);
    static void save_sensor_data_logs_to_file(QString path,QList<QByteArray> lines);
    static void add_collection_record_to_file(QString path,QStringList record_data);
    static void add_deployment_record_to_file(QString path,QStringList deployment_data);

};

#endif // FILE_SAVING_H
