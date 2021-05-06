#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "medicament.h"
#include "suivi_medical.h"
#include"utilisateur.h"
QT_BEGIN_NAMESPACE
namespace Ui { class accueil; }
QT_END_NAMESPACE

class accueil : public QMainWindow
{
    Q_OBJECT

public:
    accueil(QWidget *parent = nullptr);
    ~accueil();

private slots:
    void on_pushButton_A1_clicked();
    void on_pushButton_22_clicked();



    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
    void on_button_profil_clicked();

    void on_button_employe_clicked();

    void on_button_equipement_clicked();

    void on_pushButton_clicked();

    void on_button_client_clicked();

    void on_button_produit_clicked();

    void on_button_fournisseurs_clicked();

    void on_button_evenement_clicked();

    void on_button_recette_clicked();

    void on_button_quitter_clicked();

    void on_aj_clicked();


    void on_button_recette_2_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    //void on_email_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
    void on_Mode_jour_clicked();


    void on_Mode_nuit_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::accueil *ui;
    medicament tmpm;
    suivi_medical tpm;
    utilisateur tp;
};
#endif // ACCUEIL_H
