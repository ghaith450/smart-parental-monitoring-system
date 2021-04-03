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

