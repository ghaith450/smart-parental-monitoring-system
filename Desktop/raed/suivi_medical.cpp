#include "suivi_medical.h"

suivi_medical::suivi_medical()
{

}
suivi_medical::suivi_medical(int id,float poids, float taille,QString rendez_vous,QString description)
{
    this->id=id;
    this->poids=poids;
    this->taille=taille;
     this->rendez_vous=rendez_vous;
    this->description=description;
}
bool suivi_medical::ajouter()
{
    QSqlQuery q;
    q.prepare("INSERT INTO suivi_medical values(:id,:poids,:taille,:rendez_vous,:description)");
    QString p=QString::number(poids);
    QString t=QString::number(taille);
    q.bindValue(":id",id);
    q.bindValue(":poids",p);// associer une variable applicatives
    q.bindValue(":taille",t);
    q.bindValue(":rendez_vous",rendez_vous);
    q.bindValue(":description",description);
    return q.exec();

}
QSqlQueryModel * suivi_medical::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from suivi_medical");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("POIDS"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("TAILLE"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("RENEZ_VOUS"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIPTION"));
        return model;
}
bool suivi_medical::supprimer(int a)
{
    bool test=rechercher(a);
    QSqlQuery q;
    q.prepare("delete from suivi_medical where id=:id");
    q.bindValue(":id",a);
    q.exec();
    return test;
}
bool suivi_medical::rechercher(int d)
{
    QSqlQuery q;
q.prepare("select id from suivi_medical where id=:id");
q.bindValue(":id",d);//injection SQL securité
q.exec();
return q.next();
}
bool suivi_medical::modifier(int d)
{
    QSqlQuery q;
    bool test=rechercher(d);
    q.prepare("update suivi_medical set poids=:poids, taille=:taille , rendez_vous=:rendez_vous , description=:description , where id=:id");
    QString p=QString::number(poids);
    QString t=QString::number(taille);
    q.bindValue(":id",id);
    q.bindValue(":poids",p);
    q.bindValue(":taille",t);
    q.bindValue(":rendez_vous",rendez_vous);
    q.bindValue(":description",description);
    q.exec();
    return test;
}
QSqlQueryModel * suivi_medical::afficherRech(int id)
{
    QString id_string=QString::number(id);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from suivi_medical where id like '"+id_string+"%'");
    return model;
}
QSqlQueryModel * suivi_medical::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from suivi_medical order by poids");
    return model;
}
QSqlQueryModel * suivi_medical::tritaille()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from suivi_medical order by taille");
    return model;
}
QSqlQueryModel * suivi_medical::stat()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select rendez_vous,count(*) as nombre from suivi_medical group by rendez_vous");
    return model;
}
