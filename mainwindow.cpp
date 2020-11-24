#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "chambre.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Patient->setModel(tmpPatient.afficher());
    ui->tableView_chambre->setModel(tmpChambre.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int cin= ui->lineEdit_CIN->text().toInt();
    QString id= ui->lineEdit->text();
    int age= ui-> lineEdit_age->text().toInt();
    int duree= ui-> lineEdit_duree->text().toInt();
    QDate Date_entrer= ui-> dateEdit->date();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    patient p(cin,id,age,duree,Date_entrer,nom,prenom);
bool test=p.ajouter();
if(test)
   { ui->tableView_Patient->setModel(tmpPatient.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajouter Patient"),
                QObject::tr("Patient ajuter.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

else

{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter Patient"),
                QObject::tr("Ajout echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}
void MainWindow::on_pushButton_15_clicked()
{
    int cin = ui -> lineEdit_cin_supp->text().toInt();
    bool test=tmpPatient.supprimer(cin);

    if(test)
       { ui->tableView_Patient->setModel(tmpPatient.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer Patient"),
                    QObject::tr("Patient supprimer.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    else

    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer Patient"),
                    QObject::tr("suppression echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}

void MainWindow::on_pushButton_3_clicked()
{

    int cin= ui->lineEdit_cinp->text().toInt();
    QString id= ui->lineEdit_2->text();
    int age= ui->lineEdit_agep->text().toInt();
    int duree= ui->lineEdit_dureep->text().toInt();
    QDate Date_entrer=ui->dateEdit17->date();
    QString nom=ui->lineEdit_nomp->text();
    QString prenom=ui->lineEdit_prenomp->text();


        bool test = tmpPatient.update(cin,id,age,duree,Date_entrer,nom,prenom);

        if(test)

        {
            ui->tableView_Patient->setModel(tmpPatient.afficher());

            QMessageBox::information(nullptr, QObject::tr("update "),
                        QObject::tr("Patient modifie\n"
        "Click Cancel to exit."), QMessageBox::Cancel);}
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                widget->clear();
            }
}


void MainWindow::on_pushButton_9_clicked()
{
    int etage= ui-> lineEdit_etage->text().toInt();
    int numero_chambre= ui-> lineEdit_num->text().toInt();
    QString id= ui-> lineEdit_id->text();
    QString type=ui->comboBox->currentText();

    chambre ch(id ,etage,numero_chambre,type);
bool test=ch.ajouter();
if(test)
   { ui->tableView_chambre->setModel(tmpChambre.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajouter chambre"),
                QObject::tr("chambre ajouter.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

else

{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter chambre"),
                QObject::tr("Ajout echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    QString id = ui -> lineEdit_csupp->text();
    bool test=tmpChambre.supprimer(id);

    if(test)
       { ui->tableView_chambre->setModel(tmpChambre.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer Chambre"),
                    QObject::tr("Chambre supprimer.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    else

    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer Chambre"),
                    QObject::tr("suppression echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}




void MainWindow::on_pushButton_10_clicked()
{


    QString id= ui->lineEdit_2id->text();
    
    int numero_chambre= ui->lineEdit_2num->text().toInt();
    int etage=ui->dateEdit_4->text().toInt();
    QString type=ui->comboBox_2->currentText();
    


        bool test = tmpChambre.update(id,etage,numero_chambre,type);

        if(test)

        {
            ui->tableView_chambre->setModel(tmpChambre.afficher());

            QMessageBox::information(nullptr, QObject::tr("update "),
                        QObject::tr("Chambre modifie\n"
        "Click Cancel to exit."), QMessageBox::Cancel);}
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                widget->clear();
            }

}
