#ifndef COURS_H
#define COURS_H

#include<QString>
#include<QtSql>
#include<QSqlQueryModel>
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
bool supprimer(int);
bool modifier(int);
QSqlQueryModel* tri();
QSqlQueryModel* afficherRech(int);
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
