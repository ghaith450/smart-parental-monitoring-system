#ifndef EXAMEN_H
#define EXAMEN_H

#include<QString>
#include<QtSql>
#include<QSqlQueryModel>
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
