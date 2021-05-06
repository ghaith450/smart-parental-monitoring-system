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
    QSqlQuery query;//requete sql s'execute a partir du QT
    QString id_string =QString::number(id_Cours);
    QString telephone_string =QString::number(telephone_proffeseur);
    QString prix_string =QString::number(prix);

    query.prepare("INSERT INTO COURS (id_Cours,nom_matiere,nom_proffeseur,prenom_proffeseur,telephone_proffeseur,prix,type) "
                       "VALUES (:id_Cours,:nom_matiere,:nom_proffeseur,:prenom_proffeseur,:telephone_proffeseur ,:prix ,:type )");

         query.bindValue(":id_Cours",id_string);//injection SQL (securité)
         query.bindValue(":nom_matiere",nom_matiere);
         query.bindValue(":nom_proffeseur",nom_proffeseur);
         query.bindValue(":prenom_proffeseur",prenom_proffeseur);
         query.bindValue(":telephone_proffeseur",telephone_string);
         query.bindValue(":prix",prix_string);
         query.bindValue(":type",type);
     return query.exec();

}
bool Cours::verif(QString id_cours)
{
    int i=0;

    QSqlQuery query;
    query.prepare("select * from cours where id_cours= ? ");
   query.addBindValue(id_cours);
    if(query.exec())
    {while(query.next())
        {
            i++;

        }}

    if(i!=0)
        return true ;
    else
        return false;

}
QSqlQueryModel* Cours::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM cours");
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_matiere"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_proffeseur"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom_proffeseur"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("telephone_proffeseur"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
          model->setHeaderData(6,Qt::Horizontal, QObject::tr("type"));

    return model;
}
bool Cours::supprimer(QString nom_matiere)
{
    QSqlQuery q;
    q.prepare("delete from cours where nom_matiere=:nom_matiere");
    q.bindValue(":nom_matiere",nom_matiere);
    return q.exec();
}

bool Cours::modifier(int id)
{
    QSqlQuery query;

    QString telephone_string =QString::number(telephone_proffeseur);
    QString prix_string =QString::number(prix);
    query.prepare("update cours set nom_matiere=:nom_matiere,nom_proffeseur=:nom_proffeseur,prenom_proffeseur=:prenom_proffeseur,telephone_proffeseur=:telephone_proffeseur,prix=:prix,type=:type where id_cours=:id");
    query.bindValue(":id",id);//injection SQL (securité)
    query.bindValue(":nom_matiere",nom_matiere);
    query.bindValue(":nom_proffeseur",nom_proffeseur);
    query.bindValue(":prenom_proffeseur",prenom_proffeseur);
    query.bindValue(":telephone_proffeseur",telephone_string);
    query.bindValue(":prix",prix_string);
    query.bindValue(":type",type);
return query.exec();
}
QSqlQueryModel* Cours::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM cours order by prix");


    return model;
}
QSqlQueryModel* Cours::tri1()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM cours order by id_cours");


    return model;
}
QSqlQueryModel* Cours::tri2()
{
    QSqlQueryModel* model = new QSqlQueryModel();


          model->setQuery("SELECT* FROM cours order by nom_proffeseur");


    return model;
}
QSqlQueryModel* Cours::afficherRech(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
QString id_string=QString::number(id);
          model->setQuery("SELECT* FROM cours where id_cours like '"+id_string+"%'");


    return model;
}
QSqlQueryModel* Cours::stat()
{
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT nom_matiere,count(*) as nombre FROM cours group by nom_matiere");


    return model;
}

QSqlQueryModel* Cours::afficherRech1(QString nom_matiere1)
{
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT* FROM cours where nom_matiere like '"+nom_matiere1+"%'");
          return model;
}
QSqlQueryModel* Cours::afficherRech2(QString type1)
{
    QSqlQueryModel* model = new QSqlQueryModel();

          model->setQuery("SELECT* FROM cours where type like '"+type1+"%'");
          return model;
}

