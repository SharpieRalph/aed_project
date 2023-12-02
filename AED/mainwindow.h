#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aed.h"
#include "patient.h"
#include <QProgressBar>

#define TOTAL_PATIENTS 4

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, patient *newPatients = nullptr);
    ~MainWindow();

    void setAED(aed *newAED);

    void updateShocks();
    void configurePatients();

private:
    Ui::MainWindow *ui;
    patient *listOfPatients;
    aed *AED;

    QTimer* timer;
    QProgressBar* batteryBar ;
    void nokOn();
    void nokOff();
    void toggleTimer();

    void updateProgressBar();

private slots:
    void updatePatient(int newPatient);
    void updatePower(bool newPower);
    void updateCPR(bool newCPR);
    void updatePads(int newPads);
    void lightOn(int lightNum);
    void lightOff(int lightNum);
    void updateText(int textNum);
};
#endif // MAINWINDOW_H
