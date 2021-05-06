#ifndef EXAMEN_H
#define EXAMEN_H

#include<QString>
#include<QtSql>
#include<QSqlQueryModel>
#include<string>
using namespace std ;
class examen
{

public:
    examen();
    examen(int id_examen,QString nomMatiere,float coefficient,QString session,QString date,int id_enfant,QString classe);
    int getId_examen();
    QString getNomMatiere();
    float getCoefficient();
    QString getSession();
    QString getDate();
    int getId_enfant();
    QString getClasse();


    void setId_examen(int);
    void setNomMatiere(QString);
    void setCoefficient(float);
    void setSession(QString);
    void setDate(QString);
    void setId_enfant(int);
    void setClasse(QString);
    bool ajouter();
      QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(int);
    QSqlQueryModel* tri();
        QSqlQueryModel* tri1();
         QSqlQueryModel* tri2();
    QSqlQueryModel* afficherRech(int);
      QSqlQueryModel* stat();
QSqlQueryModel* afficherRech3(int);
QSqlQueryModel* afficherRech4(QString);
QSqlQueryModel* afficherRech5(int);

 private:
    int id_examen;
    QString nomMatiere;
    float coefficient ;
    QString session ;
    QString  date ;
    int id_enfant ;
    QString classe;
};

#endif // EXAMEN_H
