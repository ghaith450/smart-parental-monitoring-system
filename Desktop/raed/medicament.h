#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class medicament
{
public:
    medicament();
    medicament(int,QString,float,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherRech(int);
    QSqlQueryModel * tri();
    QSqlQueryModel * stat();
    bool supprimer(int);
    bool rechercher(int);
    bool modifier(int);
private:
    int id;
    QString type;
    float prix;
    QString niveau;
};

#endif // MEDICAMENT_H
