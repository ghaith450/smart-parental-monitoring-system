#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

void MainWindow::on_pushButton_3_clicked()
{

  int id=ui->lineEdit->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
  QString type=ui->lineEdit_2->text();
  float prix=ui->lineEdit_3->text().toFloat();
  QString niveau=ui->lineEdit_4->text();
  medicament m(id,type,prix,niveau);
  bool test=m.ajouter();
  if(test)
  {
      ui->tableView->setModel(tmpm.afficher());

      QMessageBox::information(nullptr, QObject::tr("medicament ajouté"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("medicament non ajouté"),
                  QObject::tr("failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_9->text().toInt();
    bool test=tmpm.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(tmpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("medicament supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("medicament non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_8->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
    QString type=ui->lineEdit_5->text();
    float prix=ui->lineEdit_7->text().toFloat();
    QString niveau=ui->lineEdit_6->text();
    medicament m(id,type,prix,niveau);
    bool test=m.modifier(id);
    if(test)
    {
        ui->tableView->setModel(tmpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("matiere premiere modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("matiere premiere non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    void MainWindow::on_button_profil_clicked()
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->button_client->setEnabled(1);
    }

    void MainWindow::on_button_employe_clicked()
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_2->setCurrentIndex(1);
    }

    void MainWindow::on_button_client_clicked()
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget_2->setCurrentIndex(2);
    }

    void MainWindow::on_button_produit_clicked()
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedWidget_2->setCurrentIndex(3);
    }

    void MainWindow::on_button_equipement_clicked()
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->stackedWidget_2->setCurrentIndex(4);
    }

    void MainWindow::on_button_fournisseurs_clicked()
    {
        ui->stackedWidget->setCurrentIndex(5);
        ui->stackedWidget_2->setCurrentIndex(5);
    }

    void MainWindow::on_button_evenement_clicked()
    {
        ui->stackedWidget->setCurrentIndex(6);
        ui->stackedWidget_2->setCurrentIndex(6);
    }



    void MainWindow::on_pushButton_clicked()
    {
    }

    void MainWindow::on_button_recette_clicked()
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->stackedWidget_2->setCurrentIndex(7);
    }

    void MainWindow::on_button_quitter_clicked()
    {
        close();
    }

    void MainWindow::on_aj_clicked()
    {
}

