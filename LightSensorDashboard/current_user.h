#ifndef CURRENT_USER_H
#define CURRENT_USER_H

#include "mainwindow.h"
class current_user : public QObject
{
    Q_OBJECT
private:
    QString users_name;
    QString users_phone;
    QString def_path;

public:
    current_user();
    void set_users_name(QString name);
    void set_users_phone(QString phone);
    void set_def_path(QString path);

    QString get_users_name();
    QString get_users_phone();
    QString get_def_path();
};

#endif // CURRENT_USER_H
