#include "location_manager.h"
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QtCore>
#include <QDialog>
#include <QFileSystemModel>

/**
 * @brief location_manager - handles all functionality related to getting locations based on subdirectories in given data folder,
 * storing these locations for later use, adding and removing location subdirectories
 */

location_manager::location_manager()
{
    QStringList locations;
    QString currentLocation;
    int currentLocationIndex;
}

/**
 * @brief Sets locations StringList to the location subdirectories contained in the provided path
 * @param locations_directory
 */
void location_manager::set_locations(QString locations_directory) {
    qDebug()<<"Function: location_manager::set_locations()\nInput Path: "<<locations_directory;

    QDir base_dir(locations_directory);

    if(! base_dir.exists()) {
        qDebug()<<"Error: location_manager::set_locations()     Provided Directory Does Not Exsist";
        return;
    }

    locations = base_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Dirs);

    qDebug()<< "location_manager::set_locations()   Locations found:"<< locations;
}

 /**
 * @brief location_manager::get_locations()
 * @return QStringList of locations
 */
QStringList location_manager::get_locations() {
    qDebug()<<"Function: location_manager::get_locations()";
    return locations;
}

void add_location(QString location) {

}
void remove_location(QString location){

}
