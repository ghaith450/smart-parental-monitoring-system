#include "gestion_argent.h"
#include "ui_gestion_argent.h"
#include "argent.h"
#include "smtp.h"
#include "accueil.h"
#include "statistiques.h"
#include <QMessageBox>
#include <QtCore/QString>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

gestion_argent::gestion_argent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_argent)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    QSqlQuery query;

    QSqlQueryModel * modal3=new QSqlQueryModel();


    //---------------CLE ETRANGERE---------------//
    query.prepare("select nomprod from prod");
    query.exec();
    modal3->setQuery(query);
    ui->comboBox->setModel(modal3);

    //-------------------------//





    ui->tabchambre->setModel(tmpchambre.afficher());
    ui->tabservicech->setModel(tmpservicech.afficher());



    }




    void gestion_argent::sendMail()
    {
        QString mail = ui->rcpt->text();
        Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

        if(    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)))
    )
        {
            QMessageBox::critical(this, "envoyer un mail", "Message non Envoyé (probleme de connexion)");
        }
        else
        {
            QMessageBox::information(this, "envoyer un mail", "Message envoyé avec succès.");
        }

        ui->server->setPlaceholderText("smtp.gmail.com");
        ui->port->setPlaceholderText("465");
    }


    void gestion_argent::on_pb_ajouter_clicked()
    {
        int idar = ui->lineEdit_num->text().toInt();
        QString budge= ui->lineEdit_num_3->text();
        QDate dateed= ui->dateEdit->date();
        QDate dateef= ui->dateEdit_2->date();
        QString nomprod= ui->comboBox->currentText();




      argent l(idar,budge,dateed,dateef,nomprod);
      if ((idar != 0) && (budge != "") ){

      bool test=l.ajouter();
      if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un offre"),
                      QObject::tr("Offre ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }

       else if (idar == 0){
          // ui->label_12->setText("*Numero de Chambre INVALIDE!!");
          ui->lineEdit_num->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
          QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/image2.png");


      }
      else if (budge == ""){
         // ui->label_12->setText("*Numero de Chambre INVALIDE!!");
         ui->lineEdit_num_3->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
         QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/image2.png");


     }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Offre"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

    void gestion_argent::on_pb_supprimer_clicked()
    {



        int idar = ui->lineEdit_num->text().toInt();


    bool test=tmpchambre.supprimer(idar);
    if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Interview supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

    void gestion_argent::on_pb_ajouter_2_clicked()
    {




        int idprod = ui->lineEdit_id_3->text().toInt();
        QString nomprod= ui->lineEdit_prix_3->text();
        QDate dateeprod= ui->dateEdit_3->date();
        QString prix = ui->lineEdit_prix_5->text();
        QString categorie= ui->lineEdit_prix_7->text();
        QString nbpoints= ui->lineEdit_prix_8->text();


      prod e(idprod,nomprod,dateeprod,prix,categorie,nbpoints);
      if ((idprod != 0) && (nomprod != "") &&  (prix != "") && (categorie != "")&& (nbpoints != "") ){

      bool test=e.ajouter_2();
      if(test)
    {QSqlQuery query;



          ui->tabservicech->setModel(tmpservicech.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une mission"),
                      QObject::tr("Invite ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }
      else if (idprod == 0)
        {
            // ui->label_12->setText("*Numero de Chambre INVALIDE!!");
            ui->lineEdit_id_3->setStyleSheet(" border-radius:9px; border: 2px solid #b50000;  background:red");
            QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/image2.png");


        }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une mission"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }

    void gestion_argent::on_pb_supprimer_2_clicked()
    {

        int idprod = ui->lineEdit_id_3->text().toInt();



        bool test=tmpservicech.supprimer_2(idprod);
        if(test)
        {ui->tabservicech->setModel(tmpservicech.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une mission"),
                        QObject::tr("Service_chambre supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une mission"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

    void gestion_argent::on_pb_modifier_clicked()
    {
        int idar = ui->lineEdit_num->text().toInt();
        QString budge= ui->lineEdit_num_3->text();
        QDate dateed= ui->dateEdit->date();
        QDate dateef= ui->dateEdit_2->date();
        QString nomprod= ui->comboBox->currentText();




      argent l(idar,budge,dateed,dateef,nomprod);
      bool test=l.modifier(idar);
      if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un employe"),
                      QObject::tr("employe modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }


    void gestion_argent::on_pb_modifier_4_clicked()
    {

        int idprod = ui->lineEdit_id_3->text().toInt();
        QString nomprod= ui->lineEdit_prix_3->text();
        QDate dateeprod= ui->dateEdit_3->date();
        QString prix = ui->lineEdit_prix_5->text();
        QString categorie= ui->lineEdit_prix_7->text();
        QString nbpoints= ui->lineEdit_prix_8->text();


      prod e(idprod,nomprod,dateeprod,prix,categorie,nbpoints);


      bool test=e.modifier_4(idprod);
      if(test)
    {ui->tabservicech->setModel(tmpservicech.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un invite"),
                      QObject::tr("invite modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un invite"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

    void gestion_argent::on_pb_rechercher_clicked()
    {

        QString str=ui->lineEdit_num->text();
        QString str2=ui->lineEdit_num_3->text();

        ui->tabchambre->setModel(tmpchambre.recherche(str,str2));
    }






    void gestion_argent::on_tabchambre_activated(const QModelIndex &index)
    {
        QString val=ui->tabchambre->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from argent where IDAR='"+val+"' or BUDGE='"+val+"' or DATEED='"+val+"' or DATEEF='"+val+"' or NOMPROD='"+val+"' ");

         if (qry.exec())
            {

            while (qry.next())
            {



                      ui->lineEdit_num->setText(qry.value(0).toString());
                      ui->lineEdit_num_3->setText(qry.value(1).toString());
                      ui->dateEdit->setDate(qry.value(2).toDate());
                      ui->dateEdit_2->setDate(qry.value(3).toDate());
                      ui->comboBox->setCurrentText(qry.value(4).toString());







            }
        }
        else
        {
           // QMessageBox::critical(this,tr("error"),qry.lastError().text());
        }
          }


    void gestion_argent::on_lineEdit_prix_cursorPositionChanged(int arg1, int arg2)
    {

    }

    void gestion_argent::on_lineEdit_num_cursorPositionChanged(int arg1, int arg2)
    {

    }





    void gestion_argent::on_tabservicech_activated(const QModelIndex &index)
    {

        QString val=ui->tabservicech->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from prod where IDPROD='"+val+"' or NOMPROD='"+val+"' or DATEEPROD='"+val+"' or PRIX='"+val+"' or CATEGORIE='"+val+"' or NBPOINTS='"+val+"'  ");

         if (qry.exec())
            {

            while (qry.next())
            {

                      ui->lineEdit_id_3->setText(qry.value(0).toString());
                      ui->lineEdit_prix_3->setText(qry.value(1).toString());
                      ui->dateEdit_3->setDate(qry.value(1).toDate());
                      ui->lineEdit_prix_5->setText(qry.value(3).toString());
                      ui->lineEdit_prix_7->setText(qry.value(4).toString());
                      ui->lineEdit_prix_8->setText(qry.value(5).toString());













            }
        }
        else
        {
           // QMessageBox::critical(this,tr("error"),qry.lastError().text());
        }

    }

    void gestion_argent::on_radioMale_2_clicked()
    {
         ui->lineEdit_dispo->setText("oui");
    }

    void gestion_argent::on_radioFemelle_2_clicked()
    {
         ui->lineEdit_dispo->setText("non");
    }

    void gestion_argent::on_pushButton_clicked()
    {

            QString str=ui->lineEdit_id_3->text();
            QString str1=ui->lineEdit_prix_3->text();
             QString str2=ui->lineEdit_prix_5->text();

            ui->tabservicech->setModel(tmpservicech.modifier_5(str,str1,str2));

    }

    void gestion_argent::on_comboBox_2_activated(const QString &arg1)
    {

    }

    void gestion_argent::on_comboBox_activated(const QString &arg1)
    {
        QSqlQuery query;


    }



    void gestion_argent::on_pushButton_2_clicked()
    {
        /*  QPrinter printer;
              QString doc;

              printer.setPrinterName("printer1");
              QPrintDialog print_dialog(&printer,this);
             if(print_dialog.exec()== QDialog::Rejected) return ;

               ui->text_id-> */


        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabservicech->model()->rowCount();
        const int columnCount = ui->tabservicech->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"

             <<  QString("<title>%1</title>\n").arg("col1")
              <<  "</head>\n"
                  "  <h1>Produit PDF</h1>"
                  "<body bgcolor=#ac9976  link=#5000A0>\n"
                  "<table border=1 cellspacing=0 cellpadding=2 >\n";

        // headers
        out << "<thead><tr bgcolor=#aa0000>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabservicech->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabservicech->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabservicech->isColumnHidden(column)) {
                    QString data = ui->tabservicech->model()->data(ui->tabservicech->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
    }

    void gestion_argent::on_pushButton_3_clicked()
    {
        statistiques *x = new statistiques;

            x->show();
            //this->hide();
    }

    void gestion_argent::on_radioButton_clicked()
    {
        QSqlQueryModel * model = new QSqlQueryModel();

        model->setQuery("SELECT * FROM argent ORDER BY IDAR ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idar"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("budge"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateed"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateef"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("nomprod"));

        ui->tabchambre->setModel(model);
        ui->tabchambre->show();



    }

    void gestion_argent::on_radioButton_2_clicked()
    {
        QSqlQueryModel * model = new QSqlQueryModel();

        model->setQuery("SELECT * FROM argent ORDER BY budge ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idar"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("budge"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateed"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateef"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("nomprod"));

        ui->tabchambre->setModel(model);
        ui->tabchambre->show();
    }

    void gestion_argent::on_radioButton_3_clicked()
    {
        QSqlQueryModel * model = new QSqlQueryModel();

        model->setQuery("SELECT * FROM argent ORDER BY nomprod ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idar"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("budge"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateed"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateef"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("nomprod"));

        ui->tabchambre->setModel(model);
        ui->tabchambre->show();
    }

    void gestion_argent::on_pushButton_4_clicked()
    {
        //Play Video
        QMediaPlayer* player = new QMediaPlayer;
        QVideoWidget* vw= new QVideoWidget;
        player->setVideoOutput(vw);
        player->setMedia(QUrl::fromLocalFile("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/abccc.mpg"));
        vw->setGeometry(234,38,788,788);


        vw->show();
        player->play();
        qDebug() <<player->state();

    }

gestion_argent::~gestion_argent()
{
    delete ui;
}

void gestion_argent::on_pushButton_5_clicked()
{
    accueil *x = new accueil;

        x->show();
        this->hide();
}

void gestion_argent::on_Mode_jour_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/az.png");


    ui->label_mask->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));
}

void gestion_argent::on_Mode_nuit_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/mask.png");


    ui->label_mask->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));
}

void gestion_argent::on_pushButton_6_clicked()
{
    on_Mode_jour_clicked();
}

void gestion_argent::on_pushButton_7_clicked()
{
    on_Mode_nuit_clicked();
}
