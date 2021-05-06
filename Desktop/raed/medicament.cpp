#include "medicament.h"

medicament::medicament()
{

}
medicament::medicament(int id,QString type,float prix,QString niveau)
{
    this->id=id;
    this->type=type;
    this->prix=prix;
    this->niveau=niveau;
}
bool medicament::ajouter()
{
    QSqlQuery q;
    QString res=QString::number(prix);
    q.prepare("INSERT INTO medicament values(:id,:type,:prix,:niveau)");

    q.bindValue(":id",id);
    q.bindValue(":type",type);// associer une variable applicatives
    q.bindValue(":prix",res);
    q.bindValue(":niveau",niveau);
    return q.exec();

}
QSqlQueryModel * medicament::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from medicament");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("NIVEAU"));
        return model;
}
bool medicament::supprimer(int a)
{
    bool test=rechercher(a);
    QSqlQuery q;
    q.prepare("delete from medicament where id_med=:id");
    q.bindValue(":id",a);
    q.exec();
    return test;
}
bool medicament::rechercher(int d)
{
    QSqlQuery q;
q.prepare("select id_med from medicament where id_med=:id");
q.bindValue(":id",d);//injection SQL securité
q.exec();
return q.next();
}
bool medicament::modifier(int d)
{
    QSqlQuery q;
    bool test=rechercher(d);
    q.prepare("update medicament set type=:type, prix=:prix , niveau=:niveau where id_med=:id");
    q.bindValue(":id",d);
    q.bindValue(":type",type);
    q.bindValue(":prix",prix);
    q.bindValue(":niveau",niveau);
    q.exec();
    return test;
}
QSqlQueryModel * medicament::afficherRech(int id)
{
    QString id_string=QString::number(id);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from medicament where id like '"+id_string+"%'");
    return model;
}
QSqlQueryModel * medicament::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from medicament order by poids");
    return model;
}
QSqlQueryModel * medicament::stat()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select TYPE,count(*) as nombre from medicament group by TYPE");
    return model;
}
