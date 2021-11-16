#ifndef LOCATION_MANAGER_H
#define LOCATION_MANAGER_H

# include "mainwindow.h"


class location_manager : public QObject
{
    Q_OBJECT

private:
    QStringList locations;
    QString currentLocation;
    int currentLocationIndex;

public:
    location_manager();
    Ui::MainWindow *ui;

    void set_locations(QString locations_directory);
    QStringList get_locations();

    void add_location(QString location);
    void remove_location(QString location);
};

#endif // LOCATION_MANAGER_H
