#include "examen.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include "connection.h"
examen::examen()
{
id_examen=0;
nomMatiere="";
coefficient=0;
session="";
date="";
id_enfant=0;
classe="";
}
examen::examen(int id_examen,QString nomMatiere,float coefficient,QString session,QString  date,int id_enfant,QString classe)
{
    this->id_examen=id_examen;
    this->nomMatiere=nomMatiere;
    this->coefficient=coefficient;
    this->session=session;
    this->date= date;
    this->id_enfant= id_enfant;
    this->classe=classe;
}

int examen::getId_examen(){return id_examen;}
QString examen::getNomMatiere(){return nomMatiere;}
float examen::getCoefficient(){return  coefficient;}
QString examen::getSession(){return session;}
QString examen::getDate(){return date;}
int examen::getId_enfant(){return id_enfant;}
QString examen::getClasse(){return classe;}


void examen::setId_examen(int id_examen){this->id_examen=id_examen;}
void examen::setNomMatiere(QString nomMatiere){this->nomMatiere=nomMatiere;}
void examen::setCoefficient(float coefficient){this->coefficient=coefficient;}
void examen::setSession(QString session){this->session=session;}
void examen::setDate(QString date) {this->date=date;}
void examen::setId_enfant(int id_enfant){this->id_enfant=id_enfant;}
void examen::setClasse(QString classe){this->classe=classe;}

bool examen::ajouter()
{
    QSqlQuery query;//requete sql s'execute a partir du QT
    QString id_string =QString::number(id_examen);
    QString coefficient_string =QString::number(coefficient);
    QString idEnfant_string =QString::number(id_enfant);

    query.prepare("INSERT INTO examen (id_examen, nomMatiere,coefficient,session_,date_,id_enfant,classe) "
                       "VALUES (:id_examen,:nomMatiere,:coefficient,:session,:date ,:id_enfant ,:classe )");

         query.bindValue(":id_examen",id_string);//injection SQL (securité)
         query.bindValue(":nomMatiere",nomMatiere);
         query.bindValue(":coefficient",coefficient_string);
         query.bindValue(":session",session);
          query.bindValue(":date",date);
         query.bindValue(":id_enfant",idEnfant_string);
         query.bindValue(":classe",classe);
     return query.exec();

}
QSqlQueryModel* examen::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM examen");


    return model;
}

QSqlQueryModel* examen::afficherRech3(int id)
{
    QString id_string=QString::number(id);
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT* FROM examen where id_examen like '"+id_string+"%'");
          return model;
}
QSqlQueryModel* examen::afficherRech4(QString nom_matiere2)
{
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT* FROM examen where nomMatiere like '"+nom_matiere2+"%'");
          return model;
}
QSqlQueryModel* examen::afficherRech5(int id2)
{
    QString id_string2=QString::number(id2);
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT* FROM examen where id_enfant like '"+id_string2+"%'");
          return model;
}
bool examen::modifier(int id)
{
    QSqlQuery query;

    QString coefficient_string =QString::number(coefficient);
 QString id_enfant_string =QString::number(id_enfant);

    query.prepare("update examen set nomMatiere=:nomMatiere,coefficient=:coefficient,session_=:session_,date_=:date_,id_enfant=:id_enfant,classe=:classe where id_examen=:id");
    query.bindValue(":id",id);//injection SQL (securité)
    query.bindValue(":nomMatiere",nomMatiere);
    query.bindValue(":coefficient",coefficient_string);
    query.bindValue(":session_",session);
    query.bindValue(":date_",date);
    query.bindValue(":id_enfant",id_enfant_string);
    query.bindValue(":classe",classe);
return query.exec();
}
bool examen::supprimer(QString nomMatiere)
{
    QSqlQuery q;
    q.prepare("delete from examen where noMmatiere=:nomMatiere");
    q.bindValue(":nomMatiere",nomMatiere);
    return q.exec();
}

QSqlQueryModel* examen::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM examen order by coefficient");


    return model;
}
QSqlQueryModel* examen::tri1()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM examen order by id_enfant");


    return model;
}
QSqlQueryModel* examen::tri2()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM examen order by classe");


    return model;
}
QSqlQueryModel* examen::stat()
{
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT nomMatiere,count(*) as nombre FROM examen group by nomMatiere");


    return model;
}
