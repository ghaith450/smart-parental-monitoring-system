#ifndef GESTION_EXAM_H
#define GESTION_EXAM_H

#include <QWidget>
#include"cours.h"
#include<examen.h>
#include <QSystemTrayIcon>
#include<QLabel>

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

namespace Ui {
class gestion_exam;
}

class gestion_exam : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_exam(QWidget *parent = nullptr);
    ~gestion_exam();


private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



    void on_comboBox_activated(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_actionnouveau_triggered();

    void on_actionouvrir_triggered();

    void on_actionfermer_triggered();

    void on_actionimprimer_triggered();

    void makePlot();

    void on_pushButton_8_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_10_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();


    void on_Mode_jour_clicked();


    void on_Mode_nuit_clicked();

private:
    Ui::gestion_exam *ui;
   Cours tmpc ;
   examen tmpe;
  QSystemTrayIcon icon;

};

#endif // GESTION_EXAM_H
