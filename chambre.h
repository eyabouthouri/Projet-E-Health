#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class chambre
{
        public:
            chambre();
            chambre(QString,int,int ,QString);
            QString getid(){return id;}
            int getetage(){return etage;}
            int getnumero_chambre(){return numero_chambre;}
            QString gettype() {return type;}
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool update(QString ,int,int ,QString);

        private:
            QString id;
            int numero_chambre;
            int etage;
            QString type;
        };

#endif // CHAMBRE_H
