#include "argent.h"
#include <QDebug>
argent::argent()
{

    idar=0;
    budge="";
    nomprod="";


}

argent::argent(int idar,QString budge,QDate dateed,QDate dateef,QString nomprod)
{
    this->idar=idar;
    this->budge=budge;
    this->dateed=dateed;
    this->dateef=dateef;
    this->nomprod=nomprod;



}



QString argent::get_budge(){return  budge;}
QString argent::get_nomprod(){return  nomprod;}
QDate argent::get_dateed(){return dateed;}
QDate argent::get_dateef(){return  dateef;}


int argent::get_idar(){return  idar;}




bool argent::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idar);
    query.prepare("INSERT INTO argent (IDAR,BUDGE,DATEED,DATEEF,NOMPROD) "
                  "VALUES (:idar, :budge, :dateed, :dateef, :nomprod)");
    query.bindValue(":idar", res);
    query.bindValue(":budge", budge);
    query.bindValue(":dateed", dateed);
    query.bindValue(":dateef", dateef);
    query.bindValue(":nomprod", nomprod);



    return    query.exec();
}

QSqlQueryModel * argent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from argent");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idar"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("budge"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateed"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateef"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nomprod"));


    return model;
}

bool argent::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from argent where IDAR = :idar ");
    query.bindValue(":idar", res);
    return    query.exec();
}

bool argent::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);


    query.prepare("UPDATE argent SET BUDGE=:budge,  DATEED=:dateed, DATEEF=:dateef, NOMPROD=:nomprod WHERE IDAR=:idar");
    query.bindValue(":idar", res);
    query.bindValue(":budge", budge);
    query.bindValue(":dateed", dateed);
    query.bindValue(":dateef", dateef);
    query.bindValue(":nomprod", nomprod);



    return    query.exec();
}

QSqlQueryModel * argent::recherche(const QString &idar,const QString &budge)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from argent where IDAR LIKE '"+idar+"' or BUDGE LIKE '"+budge+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idar"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("budge"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateed"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateef"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nomprod"));




    return model;
}

