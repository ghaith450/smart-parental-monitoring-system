#ifndef COURS_H
#define COURS_H

#include<QString>
#include<QtSql>
#include<QSqlQueryModel>
using namespace std ;
class Cours
{
public:
    Cours();
    Cours(int id_Cours, QString nom_matiere, QString nom_proffeseur, QString prenom_proffeseur, int telephone_proffeseur, float prix, QString type);
    int getId_Cours();
    QString getNom_matiere();
    QString getNom_proffeseur();
    QString getPrenom_proffeseur();
    int getTelephone_proffeseur();
    float getPrix();
    QString getType();


    void setId(int);
    void setNom_matiere(QString);
    void setNom_proffeseur(QString);
    void setPrenom_proffeseur(QString);
    void setTelephone_proffeseur(int);
    void setPrix(float);
    void setType(QString);
    bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(QString);
bool modifier(int);
bool verif(QString);
QSqlQueryModel* tri();
QSqlQueryModel* tri1();
QSqlQueryModel* tri2();
QSqlQueryModel* afficherRech(int);
QSqlQueryModel* afficherRech1(QString);
QSqlQueryModel* afficherRech2(QString);
QSqlQueryModel* stat();
private:
    int id_Cours;
    QString nom_matiere ;
    QString nom_proffeseur;
    QString prenom_proffeseur;
    int telephone_proffeseur;
    float prix ;
    QString type ;



};

#endif // COURS_H
