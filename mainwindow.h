#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "patient.h"
#include "chambre.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    patient tmpPatient;
    chambre tmpChambre;
};
#endif // MAINWINDOW_H
