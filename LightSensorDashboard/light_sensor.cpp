#include "light_sensor.h"
#include <QDir>

LightSensor::LightSensor()
{
    QString serial_num = "";
    QString uid = "";
    QString default_path = "";
    QString base_path = "";
    QString device_dir = "";
    QString data_path = "";
    QString log_path  = "";
    QString record_path = "";
    QString device_info_path = "";
    QString current_location = "";
    int num_records = 0;
    int collection_complete = 0;
}

// Clear all device variables when connecting to new device
void LightSensor::new_device() {
    QString serial_num = "";
    QString uid = "";
    QString default_path = "";
    QString base_path = "";
    QString data_path = "";
    QString log_path  = "";
    QString record_path = "";
    QString device_info_path = "";
    QString current_location = "";
    QString dev_latitude="";
    QString dev_longtitude = "";

    int location_index = 0;
    int num_records = 0;
    int collection_complete = 0;
}
// Set device UID
void LightSensor::set_uid(QString uid_input) {
    uid = uid_input;
}
void LightSensor::set_num_records(int num_rec) {
    num_records = num_rec;
}
int LightSensor::get_num_records() {
    return num_records;
}
// Return device UID
QString LightSensor::get_uid() {
    return uid;
}

QString LightSensor::get_device_serial_num(){
    return serial_num;
}
QString LightSensor::get_device_uid() {
    return uid;
}
// Set device serial number
void LightSensor::set_serial_num(QString ser_input) {
    serial_num = ser_input;
}

// Return serial number
QString LightSensor::get_serial_num() {
    return serial_num;
}

// Set base path, device directory, data path, log path and record path based on provided path
void LightSensor::init_paths(QString path) {
    base_path = path;
    default_path = path;
    set_device_directory();
    set_data_path();
    set_log_path();
    set_record_path();
    set_device_info_path();
}

// Update base path, data path, log path and record path based on provided path
void LightSensor::update_paths(QString path) {
    base_path = path;
//    d/*efault_path = path;*/
    set_device_directory();
    set_data_path();
    set_log_path();
    set_record_path();
    set_device_info_path();
}

// Update base path, data path, log path and record path based on provided path
void LightSensor::update_paths_with_location() {
    base_path = default_path + "/"+current_location;
    set_device_directory();
    set_data_path();
    set_log_path();
    set_record_path();
}

void LightSensor::set_device_directory() {
    device_dir = base_path+"/"+serial_num+"_"+uid;
    device_dir =  QDir::toNativeSeparators(device_dir);
}

void LightSensor::set_data_path() {
    data_path = device_dir+"/Data_"+serial_num+"_"+uid+".txt";
    data_path = QDir::toNativeSeparators(data_path);
}

void LightSensor::set_log_path() {
    log_path = device_dir+"/Logs_"+serial_num+"_"+uid+".txt";
    log_path = QDir::toNativeSeparators(log_path);
}

void LightSensor::set_record_path() {
    record_path = device_dir+"/Records_"+serial_num+"_"+uid+".txt";
    record_path = QDir::toNativeSeparators(record_path);
}

void LightSensor::set_current_location(QString location) {
    current_location = location;
}

void LightSensor::set_location_index(int index) {
    location_index = index;
}
void LightSensor::set_device_lat_long(QStringList location) {
    dev_latitude = location[0];
    dev_longitude = location[1];
}
void LightSensor::set_device_info_path() {
    device_info_path  = device_dir+"/device_info.txt";
    device_info_path = QDir::toNativeSeparators(device_info_path);
}
QString LightSensor::get_device_info_path() {
    return device_info_path;
}

QStringList LightSensor:: get_device_lat_long() {
    QStringList lat_long;
    lat_long << dev_latitude << dev_longitude;
    return lat_long;
}
QString LightSensor::get_base_path() {
    return base_path;
}
QString LightSensor::get_def_path() {
    return default_path;
}
QString LightSensor::get_device_directory() {
    return device_dir;
}
QString LightSensor::get_data_path() {
    return data_path;
}

QString LightSensor::get_log_path() {
    return log_path;
}

QString LightSensor::get_record_path() {
    return record_path;
}
QString LightSensor::get_current_location() {
    return current_location;
}
int LightSensor::get_location_index() {
    return location_index;
}
