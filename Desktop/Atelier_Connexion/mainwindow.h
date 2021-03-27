#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cours.h"
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

private:
    Ui::MainWindow *ui;
   Cours C ;
};

#endif // MAINWINDOW_H
