#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class utilisateur
{
public:
    utilisateur();
    utilisateur(int,QString,QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rechercher(int);
    bool modifier(int);
private:
    int id;
    QString NOM;
    QString PRENOM;
    QString EMAIL;
    QString PASSWORD;
    QString TEL;

};

#endif // UTILISATEUR_H
