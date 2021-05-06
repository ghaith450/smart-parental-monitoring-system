#ifndef ARGENT_H
#define ARGENT_H

#include <QtCore/QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class argent
{public:
    argent();
    argent(int, QString, QDate,QDate,QString);
    QString get_budge();
    QDate get_dateed();
    QDate get_dateef();
    QString get_nomprod();
    int get_idar();




    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &idar,const QString &budge);
    QSqlQueryModel * afficher();

    bool supprimer(int);
private:
    QString budge,nomprod;
    int idar;
    QDate dateed,dateef;

};

#endif // ARGENT_H

