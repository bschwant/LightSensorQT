#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_centralwidget_customContextMenuRequested(const QPoint &pos);

    void on_about_button_clicked();

    void on_instruct_button_clicked();

    void on_setup_button_clicked();

    void on_collect_button_clicked();

    void on_back_2_clicked();

    void on_back_1_clicked();

    void on_back_3_clicked();

    void on_back_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
