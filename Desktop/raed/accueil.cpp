#include "accueil.h"
#include "ui_accueil.h"
#include "statacceuil.h"
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include<QFileDialog>
#include"smtp.h"
#include "gestion_argent.h"
#include "gestion_exam.h"
#include<qthread.h>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDesktopServices>
#include<QUrl>

accueil::accueil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accueil)
{
    ui->setupUi(this);
    ui->tableView_3->setModel(tpm.afficher());
    ui->tableView->setModel(tpm.stat());
    ui->button_profil->setFocus();
    ui->stackedWidget->setCurrentIndex(0);
}

accueil::~accueil()
{
    delete ui;
}
void accueil::on_pushButton_A1_clicked()
{

  int id=ui->R1->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
  QString NOM=ui->K1->text();
  QString PRENOM=ui->K2->text();
  QString EMAIL=ui->K3->text();
  QString PASSWORD=ui->K4->text();
  QString TEL=ui->K5->text();
  utilisateur m(id,NOM,PRENOM,EMAIL,PASSWORD,TEL);
  bool test=m.ajouter();
  if(test)
  {
      ui->tableView_3->setModel(tp.afficher());

      QMessageBox::information(nullptr, QObject::tr("utilisateur ajouté"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("utilisateur non ajouté"),
                  QObject::tr("failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void accueil::on_pushButton_22_clicked()
{
    int id=ui->R7->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
    QString NOM=ui->K1_2->text();
    QString PRENOM=ui->K2_2->text();
    QString EMAIL=ui->K3_2->text();
    QString PASSWORD=ui->K4_2->text();
    QString TEL=ui->K5_2->text();
    utilisateur m(id,NOM,PRENOM,EMAIL,PASSWORD,TEL);
    bool test=m.modifier(id);
    if(test)
    {
        ui->tableView_3->setModel(tp.afficher());

        QMessageBox::information(nullptr, QObject::tr("utilisateur modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("utilisateur non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void accueil::on_pushButton_0_clicked()
{

  int id=ui->R1->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
  float poids=ui->R2->value();
  float taille=ui->R3->value();
  QString rendez_vous=ui->calendarWidget->selectedDate().toString();
  QString description=ui->R4->text();
  suivi_medical m(id,poids,taille,rendez_vous,description);
  bool test=m.ajouter();
  if(test)
  {
      ui->tableView_3->setModel(tpm.afficher());

      QMessageBox::information(nullptr, QObject::tr("suivi_medical ajouté"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("suivi_medical non ajouté"),
                  QObject::tr("failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void accueil::on_pushButton_1_clicked()
{
    int id=ui->R6->text().toInt();
    bool test=tpm.supprimer(id);
    if(test)
    {
        ui->tableView_3->setModel(tpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("suivi_medical supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("suivi_medical non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void accueil::on_pushButton_2_clicked()
{
    int id=ui->R7->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
    float poids=ui->R8->text().toFloat();
    float taille=ui->R9->text().toFloat();
    QString description=ui->R10->text();
    QString rendez_vous=ui->R11->text();
    suivi_medical m(id,poids,taille,description,rendez_vous);
    bool test=m.modifier(id);
    if(test)
    {
        ui->tableView_3->setModel(tpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("suivi_medical modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("matiere premiere non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void accueil::on_pushButton_3_clicked()
{

  int id=ui->A1->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
  QString type=ui->A2->text();
  float prix=ui->A3->text().toFloat();
  QString niveau=ui->A4->text();
  medicament m(id,type,prix,niveau);
  bool test=m.ajouter();
  if(test)
  {
      ui->tableView_2->setModel(tmpm.afficher());

      QMessageBox::information(nullptr, QObject::tr("medicament ajouté"),
                  QObject::tr("successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("medicament non ajouté"),
                  QObject::tr("failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void accueil::on_pushButton_5_clicked()
{
    int id=ui->A5->text().toInt();
    bool test=tmpm.supprimer(id);
    if(test)
    {
        ui->tableView_2->setModel(tmpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("medicament supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("medicament non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void accueil::on_pushButton_4_clicked()
{
    int id=ui->A10->text().toInt();//convertir la chaine saisir en un entier car l'attribut est entier
    QString type=ui->A11->text();
    float prix=ui->A12->text().toFloat();
    QString niveau=ui->A13->text();
    medicament m(id,type,prix,niveau);
    bool test=m.modifier(id);
    if(test)
    {
        ui->tableView_2->setModel(tmpm.afficher());

        QMessageBox::information(nullptr, QObject::tr("matiere premiere modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("matiere premiere non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void accueil::on_button_profil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->button_client->setEnabled(1);
}

void accueil::on_button_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
    gestion_exam *y = new gestion_exam;

        y->show();
        this->hide();
}

void accueil::on_button_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(2);
}

void accueil::on_button_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(3);
    gestion_argent *x = new gestion_argent;

        x->show();
        this->hide();
}

void accueil::on_button_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget_2->setCurrentIndex(4);
}

void accueil::on_button_fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(5);
}

void accueil::on_button_evenement_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->stackedWidget_2->setCurrentIndex(6);
}



void accueil::on_pushButton_clicked()
{


    ui->tableView_3->setModel(tpm.tri());

}







void accueil::on_button_recette_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->stackedWidget_2->setCurrentIndex(7);
}

void accueil::on_button_quitter_clicked()
{
    close();
}

void accueil::on_aj_clicked()
{
    /* QSqlQuery qry;
     int id_equipement;
     QString nom;
     int prix;
     QString marque;
     QString caracteristique;
     QString date_achat_1 ;
     QString etat;

     id_equipement=ui->id_line->text().toInt();
     nom=ui->nom_line->text();
     date_achat_1 = ui->date_l->text();
     prix=ui->prix_l->text().toInt();
     marque=ui->marque_l->text();
     caracteristique=ui->caracteristique_l->text();
     etat=ui->etat_l->text();
     date_achat_1=ui->date_l->text();
    equipement c (id_equipement,nom,prix,marque,caracteristique,date_achat_1,etat);
    bool test=c.ajouterequipement();
 if (test)
     {
     QMessageBox::information(nullptr,QObject::tr("Ajouter un Bloc"),
                                      QObject::tr("Client ajouté .\n"
                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
      }
 else
 {
     QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                      QObject::tr("Erreur.\n"
                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
 }*/

}

void accueil::on_button_recette_2_clicked()
{

}

void accueil::on_tableWidget_cellClicked(int row, int column)
{

}

void accueil::on_pushButton_6_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ui->tableView_3->setModel(tpm.afficherRech(id));
}

void accueil::on_pushButton_7_clicked()
{
    ui->tableView_3->setModel(tpm.afficher());
}

void accueil::on_pushButton_8_clicked()
{
    {QTableView *table;
        table = ui->tableView_3;

           QString filters("CSV files (.csv);;All files (.*)");
           QString defaultFilter("CSV files (*.csv)");
           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                              filters, &defaultFilter);
           QFile file(fileName);

           QAbstractItemModel *model =  table->model();
           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
               QTextStream data(&file);
               QStringList strList;
               for (int i = 0; i < model->columnCount(); i++) {
                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                   else
                       strList.append("");
               }
               data << strList.join(";") << "\n";
               for (int i = 0; i < model->rowCount(); i++) {
                   strList.clear();
                   for (int j = 0; j < model->columnCount(); j++) {

                       if (model->data(model->index(i, j)).toString().length() > 0)
                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") + "\n";
               }
               file.close();
               QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
           }
}
}

void accueil::on_Mode_jour_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/az.png");


    ui->label_mask->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

    ui->label_57->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

    ui->label_58->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

    ui->label_59->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

    ui->label_60->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

    ui->label_61->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));

}

void accueil::on_Mode_nuit_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/mask.png");


    ui->label_mask->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));

    ui->label_57->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));

    ui->label_58->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));

    ui->label_59->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));

    ui->label_60->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));

    ui->label_61->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));


    //ui->label_57->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));
}


void accueil::on_pushButton_9_clicked()
{
    on_Mode_jour_clicked();
}

void accueil::on_pushButton_10_clicked()
{
    on_Mode_nuit_clicked();
}

void accueil::on_pushButton_13_clicked()
{
    //Play Video
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw= new QVideoWidget;
    player->setVideoOutput(vw);

    //Path video
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/aa.mpg"));
    vw->setGeometry(234,38,788,788);


    vw->show();
    player->play();
    qDebug() <<player->state();
}

void accueil::on_pushButton_14_clicked()
{
    //houni lien page web
    QString link="www.facebook.com";
    QDesktopServices::openUrl(QUrl(link));
}

void accueil::on_pushButton_15_clicked()
{
    statAcceuil *x = new statAcceuil;

        x->show();
        //this->hide();
}



void accueil::on_radioButton_clicked()
{
    ui->tableView_3->setModel(tpm.tri());

}

void accueil::on_radioButton_2_clicked()
{
    ui->tableView_3->setModel(tpm.tritaille());

}

void accueil::on_pushButton_16_clicked()
{
    QString link="http://www.santetunisie.rns.tn/fr/toutes-les-actualites";
    QDesktopServices::openUrl(QUrl(link));
}


