#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cours.h"
#include<examen.h>
#include <QSystemTrayIcon>
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



    void on_actionnew_triggered();

    void on_actionopen_triggered();

    void on_actionexit_triggered();

private:
    Ui::MainWindow *ui;
   Cours tmpc ;
   examen tmpe;
   QSystemTrayIcon icon;
   QLabel *label1 ;
};

#endif // MAINWINDOW_H
