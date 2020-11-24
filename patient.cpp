#include "patient.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
patient::patient()
{
    this->cin=0;
    this->id="";
    this->age=0;
    this->duree=0;
    this->nom="";
    this->prenom="";
    Date_entrer = QDate();
}
patient::patient(int cin ,QString id,int age , int duree,QDate Date_entrer  ,QString nom,QString prenom)
{

    this->cin=cin;
    this->id=id;
    this->age=age;
    this->duree=duree;
    this->nom=nom;
    this->prenom=prenom;
    this->Date_entrer = Date_entrer;

}
bool patient::ajouter()
{
QSqlQuery query;
query.prepare("Insert into patient (cin,id,age,duree,Date_entrer,nom,prenom)"
              " Values(:cin,:id,:age,:duree,:Date_entrer,:nom,:prenom)");

query.bindValue(":cin",cin);
query.bindValue(":id",id);
query.bindValue(":age",age);
query.bindValue(":duree",duree);
query.bindValue(":Date_entrer",Date_entrer);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);


 return query.exec();
}
QSqlQueryModel * patient::afficher()
{
   QSqlQueryModel * model =new QSqlQueryModel();
   model->setQuery("select * from patient");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("Duree"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_entrer"));
   model->setHeaderData(6,Qt::Horizontal,QObject::tr("id"));






return model;
}
bool patient::supprimer(int cin)
{

    QSqlQuery query;

    query.prepare("delete from patient where cin = :cin");
    query.bindValue(":cin",cin);
    return query.exec();

}
bool patient::update(int cin ,QString id,int age, int duree,QDate Date_entrer  ,QString nom,QString prenom)
{
    QSqlQuery query;
    query.prepare("UPDATE patient SET cin= :cin,id= :id,age= :age,duree=:duree,Date_entrer= :Date_entrer,nom=:nom,prenom=:prenom WHERE cin = :cin");


    query.bindValue(":cin",cin);
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":duree",duree);
    query.bindValue(":Date_entrer",Date_entrer);

    return    query.exec();
}




