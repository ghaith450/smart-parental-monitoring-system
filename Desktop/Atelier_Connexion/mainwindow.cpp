#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cours.h"
#include<QIntValidator>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id_Cours->setValidator(new QIntValidator(100, 999999, this));
    ui->tab_cours->setModel(C.afficher());
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

}
