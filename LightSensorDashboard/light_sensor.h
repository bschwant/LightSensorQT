#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "mainwindow.h"

//public QObject
class LightSensor : public QObject
{
     Q_OBJECT
     //LightSensor *light_sensor = new LightSensor;
private:
    QString serial_num;
    QString uid;
    QString default_path;
    QString base_path;
    QString device_dir;
    QString data_path;
    QString log_path;
    QString record_path;
    QString current_location;
    QString dev_latitude;
    QString dev_longitude;
    QString device_info_path;
    int location_index;
    int num_records;
    int collection_complete;
public:
    LightSensor();

    void new_device();

    void set_uid(QString uid);
    QString get_uid();

    void set_serial_num(QString ser_num);
    QString get_serial_num();

    void init_paths(QString path);

    void update_paths(QString path);
    void update_paths_with_location();
    void set_device_directory();
    void set_data_path();
    void set_log_path();
    void set_record_path();
    void set_current_location(QString location);
    void set_location_index(int index);
    void set_device_lat_long(QStringList location);
    void set_device_info_path();
    void set_num_records(int num_rec);
    int get_num_records();

    QString get_device_serial_num();
    QString get_device_uid();
    QString get_device_info_path();
    QStringList get_device_lat_long();
    QString get_base_path();
    QString get_device_directory();
    QString get_data_path();
    QString get_log_path();
    QString get_record_path();
    QString get_current_location();
    QString get_def_path();
    int get_location_index();
};

#endif // LIGHT_SENSOR_H
