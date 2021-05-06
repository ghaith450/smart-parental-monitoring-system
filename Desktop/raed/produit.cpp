#include "produit.h"
#include <QtCore/QString>


prod::prod()
{
    idprod=0;
    nomprod="";
    prix="";
    categorie="";
    nbpoints="";




}


prod::prod(int idprod ,QString nomprod, QDate dateeprod, QString prix,QString categorie,QString  nbpoints )
{
    this->idprod=idprod;
    this->nomprod=nomprod;
    this->dateeprod=dateeprod;
    this->prix=prix;
    this->categorie=categorie;
    this->nbpoints=nbpoints;

}




QString prod::get_nomprod(){return  nomprod;}
QDate prod::get_dateeprod(){return  dateeprod;}
QString prod::get_prix(){return  prix;}
QString prod::get_categorie(){return  categorie;}
QString prod::get_nbpoints(){return  nbpoints;}
int prod::get_idprod(){return  idprod;}

bool prod::ajouter_2()
{
    QSqlQuery query;
    QString res= QString::number(idprod);
    query.prepare("INSERT INTO prod (IDPROD, NOMPROD, DATEEPROD,PRIX,CATEGORIE,NBPOINTS) "
                  "VALUES (:idprod, :nomprod, :dateeprod, :prix, :categorie, :nbpoints)");
    query.bindValue(":idprod", res);
    query.bindValue(":nomprod", nomprod);
    query.bindValue(":dateeprod", dateeprod);
    query.bindValue(":prix", prix);
    query.bindValue(":categorie", categorie);
    query.bindValue(":nbpoints", nbpoints);


    return    query.exec();
}

QSqlQueryModel * prod::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from prod");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idprod"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomprod"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateeprod"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbpoints"));

    return model;
}

bool prod::supprimer_2(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from prod where IDPROD = :idprod ");
    query.bindValue(":idprod", res);
    return    query.exec();
}

bool prod::modifier_4(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE prod SET NOMPROD=:nomprod,  DATEEPROD=:dateeprod, PRIX=:prix , CATEGORIE=:categorie , NBPOINTS=:nbpoints  WHERE IDPROD=:idprod");
    query.bindValue(":idprod", res);
    query.bindValue(":nomprod", nomprod);
    query.bindValue(":dateeprod", dateeprod);
    query.bindValue(":prix", prix);
    query.bindValue(":categorie", categorie);
    query.bindValue(":nbpoints", nbpoints);


    return    query.exec();
}

QSqlQueryModel * prod::modifier_5(const QString &idprod,const QString &nomprod,const QString &prix)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from prod where IDPROD LIKE '"+idprod+"' or NOMPROD LIKE '"+nomprod+"' or PRIX LIKE '"+prix+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idprod"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomprod"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateeprod"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbpoints"));

    return model;
}
