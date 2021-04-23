#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cours.h"
#include"examen.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QSystemTrayIcon>
#include<QPixmap>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id_Cours->setValidator(new QIntValidator(100, 999999, this));
    ui->tab_cours->setModel(tmpc.afficher());
    ui->tableView_2->setModel(tmpe.afficher());
    ui->tableView->setModel(tmpc.stat());
    ui->setupUi(this);

     QPixmap pix1("C:/Users/LENOVO/Desktop/Atelier_Connexion/images/mm.png");
     ui->label_15->setPixmap(pix1);
     setFixedSize(650,650);  //fixe la taille de la fenêtre

       /* setWindowFlags(Qt::CustomizeWindowHint); //supprime les paramétrages de fenêtre par défaut. Oblige donc de préciser les réglagess autorisés

        setWindowFlags(Qt::WindowTitleHint); //Autorise le titre de la fenêtre

        setWindowFlags(Qt::WindowSystemMenuHint);//autorise le bouton de fermeture dans le bandeau de fenêtre

        setWindowFlags(Qt::WindowMinimizeButtonHint);//autorise le bouton de réduction de fenêtre
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

      int id_Cours=ui->le_id_Cours->text().toInt();
      QString nom_matiere=ui->le_nom_matiere->text();
      QString nom_proffeseur=ui->le_nom_proffeseur->text();
      QString prenom_proffeseur=ui->le_prenom_proffeseur->text();
      int telephone_proffeseur=ui->telephone_proffeseur->text().toInt();
     float prix=ui->le_prix->text().toFloat();
    QString type=ui->le_type->text();
    Cours C(id_Cours,nom_matiere,nom_proffeseur,prenom_proffeseur,telephone_proffeseur,prix,type) ;
    C.ajouter();
    ui->tab_cours->setModel(tmpc.afficher());

}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    tmpc.supprimer(id);
    ui->tab_cours->setModel(tmpc.afficher());

}

void MainWindow::on_pushButton_2_clicked()
{
    int id_Cours=ui->le_id_Cours->text().toInt();
    QString nom_matiere=ui->le_nom_matiere->text();
    QString nom_proffeseur=ui->le_nom_proffeseur->text();
    QString prenom_proffeseur=ui->le_prenom_proffeseur->text();
    int telephone_proffeseur=ui->telephone_proffeseur->text().toInt();
    float prix=ui->le_prix->text().toFloat();
    QString type=ui->le_type->text();
  Cours C(id_Cours,nom_matiere,nom_proffeseur,prenom_proffeseur,telephone_proffeseur,prix,type) ;
  C.modifier(id_Cours);
  ui->tab_cours->setModel(tmpc.afficher());

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tab_cours->setModel(tmpc.tri());
}

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_2->text().toInt();
     ui->tab_cours->setModel(tmpc.afficherRech(id));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tab_cours->setModel(tmpc.afficher());
}

void MainWindow::on_pushButton_6_clicked()
{
      ui->tableView->setModel(tmpc.stat());
}

void MainWindow::on_pushButton_7_clicked()
{
    int id_examen=ui->le_id_examen->text().toInt();
    QString nom_matiere=ui->le_nom_matiere_2->text();
   float coefficient=ui->le_coefficient->text().toFloat();
    QString session=ui->le_session->text();
     QString date=ui->le_date->text();
    int id_enfant =ui->le_id_enfant->text().toInt();
 QString classe=ui->le_classe->text();

  examen E(id_examen,nom_matiere,coefficient,session,date,id_enfant,classe) ;
  E.ajouter();
  ui->tab_cours->setModel(tmpc.afficher());

}

void MainWindow::on_actionnew_triggered()
{
    QMessageBox::information(this,"title","new");
}

void MainWindow::on_actionopen_triggered()
{
   QMessageBox::information(this,"title","open");
}

void MainWindow::on_actionexit_triggered()
{
    QApplication::quit();
}
