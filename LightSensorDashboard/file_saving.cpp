#include "file_saving.h"
//#include "ui_mainwindow.h"
#include "QDebug"
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include "helper_functions.h"
#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>


file_saving::file_saving()
{

}
int file_saving::get_largest_data_index(QString filename) {

    qDebug()<<"Function: file_saving::get_largest_data_index()";

    QFile file(filename);

    // Check if file already exists
    if(!file.open(QIODevice:: ReadOnly)) {
        qDebug() << "Cannot Open File";
        return 0;
    }

    file.open(QIODevice:: ReadOnly);

    QTextStream in(&file);

    int largest_index = 0;

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> parsed = line.split(',');
        largest_index = parsed[1].toInt();
    }
    file.close();
    qDebug()<< "Largest index found in file: "<< largest_index;
    return largest_index;
}

void file_saving::save_sensor_data_logs_to_file(QString path, QList<QByteArray> lines){
    qDebug()<<"Function: file_saving::save_to_file";
    QString filename = path;

    qDebug() << " Filename: "<< filename;
    QFile file(filename);

    // Get largest existing index in file
    int largest_index = file_saving::get_largest_data_index(filename);

    file.open(QIODevice::Append);

    // Save any unsaved entries
    QTextStream out(&file);
    QList<QByteArray> temp_line;
    int temp_index = 0;

//    int num_lines = lines.count();

    for(int i = 1; i<lines.count()-2; i++) {
        temp_line = lines[i].split(',');
        temp_index = temp_line[1].toInt();

        if(temp_index < largest_index)
            continue;
        else if (temp_index == largest_index) {
            qDebug()<<"No new entries to write to file";
            file.close();
            return ;
        }
        else {
            out<<lines[i];
        }

          //  qDebug() << lines[i];
    }
    qDebug() << "LARGEST INDEX "<< largest_index;
    out.flush();


    file.close();
}


void file_saving::add_collection_record_to_file(QString path, QStringList record_data) {
    qDebug()<<"Function: file_saving::save_to_file";
    QString filename = path;

    qDebug() << " Filename: "<< filename;
    QFile file(filename);

    file.open(QIODevice::Append);

    QTextStream out(&file);

    file.open(QIODevice::Append);

    // record_data << current_date << current_time << latitude<< longitude << user_note;
    out<<"Record Type: DATA COLLECTION\n";
    out<<"Collection Date: " << record_data[0] << "\n";
    out<<"Collection Time: " << record_data[1] << "\n";
    out<<"Location: "<< record_data[2] << ", " << record_data[3]<< "\n";
    out<<"Note: "<<record_data[4] << "\n";
    out<<"-------------------------------------------------------------\n\n";

    out.flush();
    file.close();
}

void file_saving::add_deployment_record_to_file(QString path, QStringList deployment_data) {
    qDebug()<<"Function: file_saving::save_to_file";
    QString filename = path;

    qDebug() << " Filename: "<< filename;
    QFile file(filename);

    file.open(QIODevice::Append);

    QTextStream out(&file);

    file.open(QIODevice::Append);

    // deployment_info << contact_name << contact_phone << deploy_lat << deploy_long;
    out<<"Record Type: SENSOR DEPLOYMENT\n";
    out<<"Name: " << deployment_data[0] << "\n";
    out<<"Phone #: " << deployment_data[1] << "\n";
    out<<"Location: "<< deployment_data[2] << ", " <<deployment_data[3]<< "\n";
    out<<"Time Delta: "<< deployment_data[4] << "\n";
    out<<"-------------------------------------------------------------\n\n";

    out.flush();
    file.close();
}
