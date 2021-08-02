#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_about_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_instruct_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_setup_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_collect_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_back_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

