#ifndef PRODUIT_H
#define PRODUIT_H

#include <QtCore/QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class prod
{
public:
    prod();
    prod(int,QString ,QDate,QString,QString,QString );

    QString get_nomprod();
    QDate get_dateeprod();
    QString get_prix();
    QString get_categorie();
    QString get_nbpoints();
    int get_idprod();

    bool ajouter_2();
    bool modifier_4(int);
    QSqlQueryModel * modifier_5(const QString &idprod,const QString &nomprod,const QString &prix);
    QSqlQueryModel * afficher();
    bool supprimer_2(int);
private:
    QString nomprod,prix,categorie,nbpoints;
    int idprod;
    QDate dateeprod;


};

#endif // PRODUIT_H

