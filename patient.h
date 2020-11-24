#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class patient
{
public:
    patient();
    patient(int ,QString,int , int ,QDate, QString ,QString);
    int getcin(){return cin;}
    QString getid(){return id;}
    int getage(){return age;}
    int getduree(){return duree;}
    QDate getdate_entrer(){return Date_entrer;}
    QString getnom() {return nom;}
    QString getprenom() {return prenom;}
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool update(int ,QString,int,int, QDate  ,QString ,QString);
private:
    int cin;
    QString id;
    int age;
    int duree;
    QDate Date_entrer;
    QString nom, prenom;
};

#endif // PATIENT_H
