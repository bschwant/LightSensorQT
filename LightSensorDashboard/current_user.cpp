#include "current_user.h"

current_user::current_user()
{
    QString users_name = "";
    QString users_phone = "";
    QString def_path = "";

}
void current_user::set_users_name(QString name){
    users_name = name;
}
void current_user::set_users_phone(QString phone){
    users_phone = phone;
}
void current_user::set_def_path(QString path){
    def_path = path;
}
QString current_user::get_users_name(){
    return users_name;
}
QString current_user::get_users_phone(){
    return users_phone;
}
QString current_user::get_def_path(){
    return def_path;
}
