#include "chambre.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
// test
chambre::chambre()
{
    this->id="";
    this->etage=0;
    this->numero_chambre=0;
    this->type="";
}
chambre::chambre(QString id ,int etage,int numero_chambre,QString type )
{

    this->id=id;
    this->etage=etage;
    this->numero_chambre=numero_chambre;
    this->type=type;
}
bool chambre::ajouter()
{
QSqlQuery query;
query.prepare("Insert into chambre (id,etage,numero_chambre,type)"
              " Values(:id,:etage,:numero_chambre,:type)");

query.bindValue(":id",id);
query.bindValue(":etage",etage);
query.bindValue(":numero_chambre",numero_chambre);
query.bindValue(":type",type);

 return query.exec();
}
QSqlQueryModel * chambre::afficher()
{
   QSqlQueryModel * model =new QSqlQueryModel();
   model->setQuery("select * from chambre");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")); 
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("etage"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero_chambre"));


return model;
}
bool chambre::supprimer(QString id)
{

    QSqlQuery query;

    query.prepare("delete from chambre where id = :id");
    query.bindValue(":id",id);
    return query.exec();

}
bool chambre::update(QString id ,int etage ,int numero_chambre,QString type)
{
    QSqlQuery query;
    query.prepare("UPDATE chambre SET id= :id,etage=:etage,numero_chambre=:numero_chambre,type= :type WHERE id = :id");


    query.bindValue(":id",id);
    query.bindValue(":etage",etage);
    query.bindValue(":numero_chambre",numero_chambre);
    query.bindValue(":type",type);

    return    query.exec();
}
