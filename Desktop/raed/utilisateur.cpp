#include "utilisateur.h"

utilisateur::utilisateur()
{



}
utilisateur::utilisateur(int id,QString NOM, QString PRENOM,QString EMAIL,QString PASSWORD,QString TEL)
{
    this->id=id;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
     this->EMAIL=EMAIL;
    this->PASSWORD=PASSWORD;
    this->TEL=TEL;
}
bool utilisateur::ajouter()
{
    QSqlQuery q;
    q.prepare("INSERT INTO utilisateur values(:id,:NOM,:PRENOM,:EMAIL,:PASSWORD,:TEL)");

    q.bindValue(":id",id);
    q.bindValue(":NOM",NOM);// associer une variable applicatives
    q.bindValue(":PRENOM",PRENOM);
    q.bindValue(":EMAIL",EMAIL);
    q.bindValue(":PASSWORD",PASSWORD);
    q.bindValue(":TEL",TEL);
    return q.exec();

}
QSqlQueryModel * utilisateur::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from utilisateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("PASSWORD"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("TEL"));
        return model;
}
bool utilisateur::supprimer(int a)
{
    bool test=rechercher(a);
    QSqlQuery q;
    q.prepare("delete from utilisateur where id=:id");
    q.bindValue(":id",a);
    q.exec();
    return test;
}
bool utilisateur::rechercher(int d)
{
    QSqlQuery q;
q.prepare("select id from utilisateur where id_us=:id");
q.bindValue(":id",d);//injection SQL securité
q.exec();
return q.next();
}
bool utilisateur::modifier(int d)
{
    QSqlQuery q;
    bool test=rechercher(d);
    q.prepare("update utilisateur set NOM=:NOM, PRENOM=:PRENOM , EMAIL=:EMAIL , PASSWORD=:PASSWORD , where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":NOM",NOM);
    q.bindValue(":PRENOM",PRENOM);
    q.bindValue(":EMAIL",EMAIL);
    q.bindValue(":PASSWORD",PASSWORD);
    q.bindValue(":TEL",TEL);
    q.exec();
    return test;
}
