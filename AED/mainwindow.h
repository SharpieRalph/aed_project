#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "aed.h"
#include "patient.h"
#include <QProgressBar>
#include "qcustomplot.h"

#define TOTAL_PATIENTS 7

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, patient *newPatients = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;


private:

    Ui::MainWindow *ui;
    patient *listOfPatients;
    aed *AED;
    QTimer* timer;
    QTimer* LCDTimer;
    QProgressBar* batteryBar ;

    void nokOn();
    void nokOff();
    void toggleTimer();
    void updateShocks();
    void updateProgressBar();
    void configurePatients();
    void showECG();
    void hideECG();

private slots:

    void updatePatient(int newPatient);
    void updatePower(bool newPower);
    void toggleActiveCPR(bool newCPR);
    void toggleActiveECG(bool newECG);
    void updatePads(int newPads);
    void updateLCDTimer();
    void lightOn(int lightNum);
    void lightOff(int lightNum);
    void updateText(int textNum);
    void updateLCDImg(int diag);
    void on_shallowCPRBtn_clicked(bool checked);
    void on_adequateCPRBtn_clicked(bool checked);
    void on_adultPadBtn_clicked();
    void on_pedPadBtn_clicked();
};
#endif // MAINWINDOW_H
