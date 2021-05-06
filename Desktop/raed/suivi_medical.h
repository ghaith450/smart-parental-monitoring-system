#ifndef SUIVI_MEDICAL_H
#define SUIVI_MEDICAL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class suivi_medical
{
public:
    suivi_medical();
    suivi_medical(int,float,float,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherRech(int);
    QSqlQueryModel * tri();
    QSqlQueryModel * tritaille();
    QSqlQueryModel * stat();
    bool supprimer(int);
    bool rechercher(int);
    bool modifier(int);
private:
    int id;
    float poids;
    float taille;
    QString rendez_vous;
    QString description;
};

#endif // SUIVI_MEDICAL_H
