#include "cours.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include "connection.h"
Cours::Cours()
{
 id_Cours=0;
 nom_matiere="";
 nom_proffeseur="";
 prenom_proffeseur="";
 telephone_proffeseur=0;
 prix=0;
 type="";

}

Cours::Cours(int id_Cours,QString nom_matiere ,QString nom_proffeseur ,QString prenom_proffeseur ,int telephone_proffeseur ,float prix,QString type)
{
     this->id_Cours=id_Cours;
     this->nom_matiere=nom_matiere;
     this->nom_proffeseur=nom_proffeseur;
     this->prenom_proffeseur=prenom_proffeseur;
     this->telephone_proffeseur= telephone_proffeseur;
     this->prix=prix;
     this->type=type;
}
int Cours::getId_Cours(){return id_Cours;}
QString Cours::getNom_matiere(){return nom_matiere;}
QString Cours::getNom_proffeseur(){return nom_proffeseur;}
QString Cours::getPrenom_proffeseur(){return prenom_proffeseur;}
int Cours::getTelephone_proffeseur(){return telephone_proffeseur;}
float Cours::getPrix(){return prix;}
QString Cours::getType(){return type;}


void Cours::setId(int id_Cours){this->id_Cours=id_Cours;}
void Cours::setNom_matiere(QString nom_matiere ){this->nom_matiere=nom_matiere;}
void Cours::setNom_proffeseur(QString nom_proffeseur){this->nom_proffeseur=nom_proffeseur;}
void Cours::setPrenom_proffeseur(QString prenom_proffeseur){this->prenom_proffeseur=prenom_proffeseur;}
void Cours::setTelephone_proffeseur(int telephone_proffeseur){this->telephone_proffeseur=telephone_proffeseur;}
void Cours::setPrix(float prix){this->prix=prix;}
void Cours::setType(QString type){this->type=type;}

bool Cours::ajouter()
{
    bool test=false ;
    QSqlQuery query;
    QString id_string =QString::number(id_Cours);
    QString telephone_string =QString::number(telephone_proffeseur);
    QString prix_string =QString::number(prix);

    query.prepare("INSERT INTO COURS (id_Cours,nom_matiere,nom_proffeseur,prenom_proffeseur,telephone_proffeseur,prix,type) "
                       "VALUES (:id_Cours,:nom_matiere,:nom_proffeseur,:prenom_proffeseur,:telephone_proffeseur ,:prix ,:type )");

         query.bindValue(":id_Cours",id_string);
         query.bindValue(":nom_matiere",nom_matiere);
         query.bindValue(":nom_proffeseur",nom_proffeseur);
         query.bindValue(":prenom_proffeseur",prenom_proffeseur);
         query.bindValue(":telephone_proffeseur",telephone_string);
         query.bindValue(":prix",prix_string);
         query.bindValue(":type",type);
     query.exec();
     return test ;
}
QSqlQueryModel* Cours::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM cours");


    return model;
}
