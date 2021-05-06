#include "gestion_exam.h"
#include "ui_gestion_exam.h"
#include"cours.h"
#include"examen.h"
#include"qcustomplot.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QSystemTrayIcon>
#include<QPixmap>
#include<QLabel>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QApplication>
#include<QtWidgets/QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include <QSqlTableModel>
#include "accueil.h"


QT_CHARTS_USE_NAMESPACE
gestion_exam::gestion_exam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_exam)
{
    /*QBarSet *set0 = new QBarSet("Altuve");
        QBarSet *set1 = new QBarSet("martinez");
        QBarSet *set2 = new QBarSet("segura");
        QBarSet *set3 = new QBarSet("simoons");
        QBarSet *set4 = new QBarSet("trout");
        *set0 << 283 << 341 << 313 << 338 << 346 <<335 ;
         *set1 << 283 << 341 << 313 << 338 << 346 <<335 ;
         *set2 << 283 << 341 << 313 << 338 << 346 <<335 ;
         *set3 << 283 << 341 << 313 << 338 << 346 <<335 ;
         *set4 << 283 << 341 << 313 << 338 << 346 <<335 ;
          QBarSeries *series =new QBarSeries();
          series->append(set0);
           series->append(set1);
            series->append(set2);
             series->append(set3);
              series->append(set4);
          QChart *chart =new QChart();
          chart->addSeries(series);
          chart->setTitle("batting avg year");
          chart->setAnimationOptions(QChart::AllAnimations);
          QStringList categories ;
          categories << "2013" << "2014" << "2015" << "2016" <<"2017" <<"2018";
          QBarCategoryAxis *axis = new QBarCategoryAxis();

          axis->append(categories);
          chart->createDefaultAxes();
          chart->setAxisX(axis , series);
          chart->legend()->setVisible(true);
          chart->legend()->setAlignment(Qt::AlignBottom);
          QChartView *chartView = new QChartView(chart);
          chartView->setRenderHint(QPainter::Antialiasing);
          QPalette pal = qApp->palette();
          pal.setColor(QPalette::Window,QRgb(0xffffff));
           pal.setColor(QPalette::WindowText,QRgb(0x404040));
           qApp->setPalette(pal); */



        ui->setupUi(this);
        ui->le_id_Cours->setValidator(new QIntValidator(001, 999999, this));
        ui->tab_cours->setModel(tmpc.afficher());
        ui->tableView_2->setModel(tmpe.afficher());
        ui->tableView->setModel(tmpc.stat());
        ui->comboBox->addItem("ID");
        ui->comboBox->addItem("matiere");
        ui->comboBox->addItem("type");
        ui->customPlot->addGraph();
       QSqlQueryModel * model= new QSqlQueryModel;
       model->setQuery("SELECT nom_matiere FROM cours");
      ui->comboBox_3->setModel(model);
       QPixmap pix1("C:/Users/LENOVO/Desktop/Atelier_Connexion/images/mm.png");
       ui->label_15->setPixmap(pix1);
       setFixedSize(750,600); //fixe la taille de la fenêtre
       gestion_exam::makePlot();


    }

    gestion_exam::~gestion_exam()
    {
        delete ui;
    }

    void gestion_exam::on_pb_ajouter_clicked()
    {

          int id_Cours=ui->le_id_Cours->text().toInt();
          QString nom_matiere=ui->le_nom_matiere->text();
          QString nom_proffeseur=ui->le_nom_proffeseur->text();
          QString prenom_proffeseur=ui->le_prenom_proffeseur->text();
          int telephone_proffeseur=ui->telephone_proffeseur->text().toInt();
         float prix=ui->le_prix->text().toFloat();
         QString type=ui->le_type->text();
         Cours C(id_Cours,nom_matiere,nom_proffeseur,prenom_proffeseur,telephone_proffeseur,prix,type) ;
        if(nom_matiere.isEmpty() || nom_proffeseur.isEmpty() || prenom_proffeseur.isEmpty()  || type.isEmpty() )
                             {
                                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                             }
        else{
          C.ajouter();

     QMessageBox::information(0,qApp->tr("infos"),qApp->tr(" Le cours a été ajouter."),QMessageBox::Yes);
        ui->tab_cours->setModel(tmpc.afficher());
        QSqlQueryModel * model= new QSqlQueryModel;
        model->setQuery("SELECT nom_matiere FROM cours");
        ui->comboBox_3->setModel(model);
        ui->tableView->setModel(tmpc.stat());

    }
    }

    void gestion_exam::on_pushButton_clicked()
    {

      //  int id=ui->lineEdit->text().toInt();
       // QString id_string=QString::number(id);
        QString nom_matiere = ui->comboBox_3->currentText();
         bool test =tmpc.supprimer(nom_matiere);

         if(test)
           {

                QMessageBox::critical(0,qApp->tr("attention"),
                                     qApp->tr("voulez vous supprimer ce cours?"),QMessageBox::Yes,QMessageBox::No);
               if(QMessageBox::Yes)
                   {
                   //bool test=tmpc.supprimer(nom_matiere);
                   if (test)
                   {
                     tmpc.supprimer(nom_matiere);
                     QSqlQueryModel * model= new QSqlQueryModel;
                      model->setQuery("SELECT nom_matiere FROM cours");
                      ui->comboBox_3->setModel(model);
                    ui->tab_cours->setModel(tmpc.afficher());
                   }
                   }

              else{

               QMessageBox::critical(0, qApp->tr("Suppression"),
               qApp->tr("vehicule non trouvé"), QMessageBox::Cancel);

                   }
               //   tmpc.supprimer(nom_matiere);
               // ui->tab_cours->setModel(tmpc.afficher());
               }


        }

    void gestion_exam::on_pushButton_2_clicked()
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
     QMessageBox::information(0,qApp->tr("infos"),qApp->tr(" Le cours a été modifié."),QMessageBox::Yes);
     ui->tab_cours->setModel(tmpc.afficher());

    }

    void gestion_exam::on_pushButton_3_clicked()
    {
        ui->tab_cours->setModel(tmpc.tri());
    }

    void gestion_exam::on_pushButton_4_clicked()
    {
        int id=ui->lineEdit_2->text().toInt();
        QString nom_matiere1=ui->lineEdit_2->text();
         QString type1=ui->lineEdit_2->text();
        ui->tab_cours->setModel(tmpc.afficherRech(id));
        ui->tab_cours->setModel(tmpc.afficherRech1(nom_matiere1));
         ui->tab_cours->setModel(tmpc.afficherRech2(type1));
    }

    void gestion_exam::on_pushButton_5_clicked()
    {
        ui->tab_cours->setModel(tmpc.afficher());
    }

    void gestion_exam::on_pushButton_6_clicked()
    {
        ui->tableView->setModel(tmpc.stat());


    }

    void gestion_exam::on_pushButton_7_clicked()
    {
        int id_examen=ui->le_id_examen->text().toInt();
        QString nomMatiere=ui->le_nom_matiere_2->text();
       float coefficient=ui->le_coefficient->text().toFloat();
        QString session=ui->le_session->text();
         QString date=ui->le_date->text();
        int id_enfant =ui->le_id_enfant->text().toInt();
     QString classe=ui->le_classe->text();

      examen E(id_examen,nomMatiere,coefficient,session,date,id_enfant,classe) ;
          if(nomMatiere.isEmpty() ||session.isEmpty() || date.isEmpty()  || classe.isEmpty() )
                           {
                               QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                           }
          else{

     E.ajouter();
     QMessageBox::information(0,qApp->tr("infos"),qApp->tr(" Le cours a été ajouter."),QMessageBox::Yes);
      ui->tableView_2->setModel(tmpe.afficher());
          }
    }

    void gestion_exam::on_radioButton_clicked()
    {
         ui->tab_cours->setModel(tmpc.tri());
    }


    void gestion_exam::on_radioButton_2_clicked()
    {
         ui->tab_cours->setModel(tmpc.tri1());
    }

    void gestion_exam::on_radioButton_3_clicked()
    {
         ui->tab_cours->setModel(tmpc.tri2());
    }

    void gestion_exam::on_actionnouveau_triggered()
    {
        QMessageBox::information(this,"title","NEW");
    }

    void gestion_exam::on_actionouvrir_triggered()
    {
            QMessageBox::information(this,"title","open");
    }

    void gestion_exam::on_actionfermer_triggered()
    {
          QApplication::quit();
    }

    void gestion_exam::makePlot()
    {
        QSqlTableModel *model=new QSqlTableModel;
        model->setTable("cours");
        model->select();
      //ui->tableView->setModel(model);
        ui->customPlot->xAxis->setLabel("matiere");
        ui->customPlot->yAxis->setLabel("nombre de cours");
        QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
        dateTicker->setDateTimeFormat(" hh:mm");
        ui->customPlot->xAxis->setTicker(dateTicker);

        // generate some data:
      QVector<QCPGraphData> timeData(model->rowCount()); // initialize with entries 0..100
      for(int i=0; i< model->rowCount(); ++i){
          timeData[i].key =
                  QDateTime(QDate::currentDate(),
                            model->index(i, model->fieldIndex("matiere")).data().toTime())
                      .toTime_t();
              timeData[i].value =
                  model->index(i, model->fieldIndex("nombre de cours")).data().toInt(); }
      double Tmin =
           (*std::min_element(timeData.begin(), timeData.end(),
                              [](const QCPGraphData &x, const QCPGraphData &y) {
                                return x.key < y.key;
                              }))
               .key;
      double Tmax =
           (*std::max_element(timeData.begin(), timeData.end(),
                              [](const QCPGraphData &x, const QCPGraphData &y) {
                                return x.key < y.key;
                              }))
               .key;

       double Ymin =
           (*std::min_element(timeData.begin(), timeData.end(),
                              [](const QCPGraphData &x, const QCPGraphData &y) {
                                return x.value < y.value;
                              }))
               .value;

       double Ymax =
           (*std::max_element(timeData.begin(), timeData.end(),
                              [](const QCPGraphData &x, const QCPGraphData &y) {
                                return x.value < y.value;
                              }))
               .value;
        // create graph and assign data to it:
         ui->customPlot->xAxis->setRange(Tmin, Tmax);
         ui->customPlot->yAxis->setRange(Ymin, Ymax);
         ui->customPlot->graph(0)->data()->set(timeData);
         ui->customPlot->replot();
         ui->customPlot->setSizePolicy(ui->tableView->sizePolicy());
    }
         // prepare data:
        /*
          QVector<double> x1(20), y1(20);
          QVector<double> x2(100), y2(100);
          QVector<double> x3(20), y3(20);
          QVector<double> x4(20), y4(20);
          for (int i=0; i<x1.size(); ++i)
          {
            x1[i] = i/(double)(x1.size()-1)*10;
            y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
          }
          for (int i=0; i<x2.size(); ++i)
          {
            x2[i] = i/(double)(x2.size()-1)*10;
            y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
          }
          for (int i=0; i<x3.size(); ++i)
          {
            x3[i] = i/(double)(x3.size()-1)*10;
            y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
          }
          for (int i=0; i<x4.size(); ++i)
          {
            x4[i] = x3[i];
            y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
          }
          // create and configure plottables:
          QCPGraph *graph1=ui->customPlot->addGraph();
          graph1->setData(x1, y1);
          graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
          graph1->setPen(QPen(QColor(120, 120, 120), 2));
          QCPGraph *graph2 =ui->customPlot->addGraph();
          graph2->setData(x2, y2);
          graph2->setPen(Qt::NoPen);
          graph2->setBrush(QColor(200, 200, 200, 20));
          graph2->setChannelFillGraph(graph1);
          QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          bars1->setWidth(9/(double)x3.size());
          bars1->setData(x3, y3);
          bars1->setPen(Qt::NoPen);
          bars1->setBrush(QColor(10, 140, 70, 160));
          QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          bars2->setWidth(9/(double)x4.size());
          bars2->setData(x4, y4);
          bars2->setPen(Qt::NoPen);
          bars2->setBrush(QColor(10, 100, 50, 70));
          bars2->moveAbove(bars1);
          // move bars above graphs and grid below bars:
          ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
         ui-> customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
          graph1->setLayer("abovemain");
          ui->customPlot->xAxis->grid()->setLayer("belowmain");
          ui->customPlot->yAxis->grid()->setLayer("belowmain");
          // set some pens, brushes and backgrounds:
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
          ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
         ui-> customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
         ui-> customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
          ui->customPlot->xAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
         ui-> customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
          ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
          ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
         ui-> customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
          QLinearGradient plotGradient;
          plotGradient.setStart(0, 0);
          plotGradient.setFinalStop(0, 350);
          plotGradient.setColorAt(0, QColor(80, 80, 80));
          plotGradient.setColorAt(1, QColor(50, 50, 50));
         ui-> customPlot->setBackground(plotGradient);
          QLinearGradient axisRectGradient;
          axisRectGradient.setStart(0, 0);
          axisRectGradient.setFinalStop(0, 350);
          axisRectGradient.setColorAt(0, QColor(80, 80, 80));
          axisRectGradient.setColorAt(1, QColor(30, 30, 30));
         ui-> customPlot->axisRect()->setBackground(axisRectGradient);
         ui-> customPlot->rescaleAxes();
         ui-> customPlot->yAxis->setRange(0, 2);}
         */

    /*void MainWindow::on_actionimprimer_triggered()
    {
        QPrinter print;
            print.setPrinterName("imprmer");
            QPrintDialog dialog(&print,this);
            if(dialog.exec()==QDialog ::Rejected) return;
            ui->Qcustomplot->render(&print);
    }*/

    void gestion_exam::on_pushButton_8_clicked()
    {
        int id=ui->lineEdit_3->text().toInt();
        QString nom_matiere2=ui->lineEdit_3->text();
         QString id2=ui->lineEdit_3->text();
        ui->tableView_2->setModel(tmpe.afficherRech3(id));
        ui->tableView_2->setModel(tmpe.afficherRech4(nom_matiere2));
       // ui->tableView_2->setModel(tmpe.afficherRech5(id2));
    }

    void gestion_exam::on_pushButton_11_clicked()
    {
         ui->tableView_3->setModel(tmpe.stat());
    }

    void gestion_exam::on_pushButton_12_clicked()
    {
        int id_examen=ui->le_id_examen->text().toInt();
        QString nomMatiere=ui->le_nom_matiere_2->text();
        float coefficient=ui->le_coefficient->text().toFloat();
        QString session=ui->le_session->text();
      QString date=ui->le_date->text();
    int id_enfant=ui->le_id_enfant->text().toInt();
        QString classe=ui->le_classe->text();
     examen E(id_examen,nomMatiere,coefficient,session,date,id_enfant,classe) ;

     if(nomMatiere.isEmpty()  || session.isEmpty()  || date.isEmpty()  || classe.isEmpty())
      {
          QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
      }
     else {
          E.modifier(id_examen);

        QMessageBox::information(0,qApp->tr("infos"),qApp->tr(" L'examen a été modifié."),QMessageBox::Yes);
      ui->tableView_2->setModel(tmpe.afficher());
    }
    }

    void gestion_exam::on_pushButton_13_clicked()
    {
        QString nomMatiere=ui->lineEdit_4->text();
         if(nomMatiere.isEmpty())
                {
                    QMessageBox::critical(0,qApp->tr("attention"),
                                          qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
                }
            else
            {

                QMessageBox::critical(0,qApp->tr("attention"),
                                      qApp->tr("voulez vous supprimer ce cours?"),QMessageBox::Yes,QMessageBox::No);
                if(QMessageBox::Yes)
                       {
                    bool test=tmpe.supprimer(nomMatiere);
                    if (test)
                    {
                        tmpe.supprimer(nomMatiere);
                     ui->tableView_2->setModel(tmpe.afficher());
                    }
                    }
                 ui->tableView_2->setModel(tmpe.afficher());
                }

    }

    void gestion_exam::on_pushButton_9_clicked()
    {
           ui->tableView_2->setModel(tmpe.afficher());
    }



    void gestion_exam::on_radioButton_4_clicked()
    {
          ui->tableView_2->setModel(tmpe.tri());
    }

    void gestion_exam::on_radioButton_5_clicked()
    {
          ui->tableView_2->setModel(tmpe.tri1());
    }

    void gestion_exam::on_radioButton_6_clicked()
    {
        ui->tableView_2->setModel(tmpe.tri2());
    }

    void gestion_exam::on_comboBox_3_activated(const QString &arg1)
    {
        QString nom_matiere =ui->comboBox_3->currentText();
         QSqlQuery query;

         query.prepare("SELECT * FROM cours where nom_matiere =:nom_matiere");
         query.bindValue(":nom_matiere",nom_matiere);
         query.exec();
         while (query.next())
            {
                ui->lineEdit->setText(query.value(1).toString());
                ui->lineEdit_5->setText(query.value(2).toString());
            }

    }

void gestion_exam::on_pushButton_10_clicked()
{
    accueil *y = new accueil;

        y->show();
        this->hide();
}


void gestion_exam::on_Mode_jour_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/az.png");


    ui->label_mask->setPixmap(pix.scaled(215,215,Qt::KeepAspectRatio));
}

void gestion_exam::on_Mode_nuit_clicked()
{
    QPixmap pix("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/mask.png");


    ui->label_mask->setPixmap(pix.scaled(1800,1800,Qt::KeepAspectRatio));
}
void gestion_exam::on_pushButton_14_clicked()
{
    on_Mode_jour_clicked();
}

void gestion_exam::on_pushButton_15_clicked()
{
    on_Mode_nuit_clicked();
}
