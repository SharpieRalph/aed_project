#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, patient *newPatients)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), listOfPatients(newPatients)
{
    ui->setupUi(this);

    AED = new aed();    // Initializes AED
    listOfPatients = new patient[TOTAL_PATIENTS];   // Initializes listOfPatients

//    //Shows that null ptr was set
//    qInfo("%p",listOfPatients);
//    qInfo("%p",AED);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT (updatePatient(int)));
    connect(ui->pwrBtn, SIGNAL(clicked(bool)), this, SLOT (updatePower(bool)));
    connect(ui->toggleCPR, SIGNAL(clicked(bool)), this, SLOT (updateCPR(bool)));
    connect(ui->buttonGroup, SIGNAL(idClicked(int)), this, SLOT (updatePads(int)));
    ui->buttonGroup->setId(ui->padsGood, 0);
    ui->buttonGroup->setId(ui->padsBad, 1);

    //Connecting light signals/slots
    connect(AED, SIGNAL(lightOn(int)), this, SLOT (lightOn(int)));
    connect(AED, SIGNAL(lightOff(int)), this, SLOT (lightOff(int)));


}

MainWindow::~MainWindow()
{
    delete AED;
    delete ui;
}

//Takes the list of patients from main and puts it into mainwindows patients list
void MainWindow::configurePatients()
{
    listOfPatients[0].setHeartRate(80);
    listOfPatients[1].setHeartRate(350);
    listOfPatients[2].setHeartRate(150);
    listOfPatients[3].setHeartRate(0);

//    for(int i = 0; i < TOTAL_PATIENTS; i++) {
//        qInfo("%d", listOfPatients[i].getHeartRate());
//    }
}

//Updates number of shocks in AED and on the ui by 1.
void MainWindow::updateShocks()
{
    AED->updateShocks();
    QString newShocks = QString("%1").arg(AED->getShocks());
    ui->shockCounter->setText(newShocks);
}

//Turns NOK Indicator on and sets it to correct option
void MainWindow::nokOn()
{

    if (AED->getOK()){
        ui->NOKindicator->setTextColor("#72f542");
        ui->NOKindicator->setText("OK");

    }else {
        ui->NOKindicator->setTextColor("#f71919");
        ui->NOKindicator->setText("NOT OK");
    }
}

//Returns NOK Indicator to OFF
void MainWindow::nokOff()
{
    ui->NOKindicator->setTextColor("#3d3d3d");
    ui->NOKindicator->setText("OFF");
}

//Receives signial from ui and updates mainwindow accordingly
void MainWindow::updatePatient(int newPatient)
{
    //qInfo("ComboBox sent: %i", newPatient);
    AED->setPatient(&listOfPatients[newPatient]);
}

void MainWindow::updatePower(bool newPower)
{

    // Power on, AED functionality begins
    if(newPower){
        int stage = 0;  // Initial stage sent to "beingProc()"
        AED->setPower(true);
        nokOn();
        while(AED->getPower()) {
            if(stage != 0) {
                lightOff(stage-1);
                lightOn(stage);
            }
            AED->beginProc(stage);
            if(stage == 5) {
                lightOff(stage);
                stage--;
            } else {
                stage++;
            }

        }
    // Power off
    } else {
        AED->setPower(false);
        nokOff();
    }
}

void MainWindow::updateCPR(bool newCPR)
{
    AED->setCPR(newCPR);
}

void MainWindow::updatePads(int newPads)
{
//    qInfo("test: %i", newPads);
    if(newPads == 0){
        AED->setPad(true);
//        qInfo("correctPads: %i", AED->getPad());
    } else {
        AED->setPad(false);
//        qInfo("correctPads: %i", AED->getPad());
    }
}

void MainWindow::lightOn(int lightNum)
{

    switch (lightNum){
        case 0:
            ui->light0->setEnabled(true);
            break;
        case 1:
            ui->light1->setEnabled(true);
            break;
        case 2:
            ui->light2->setEnabled(true);
            break;
        case 3:
            ui->light3->setEnabled(true);
            break;
        case 4:
            ui->light4->setEnabled(true);
            break;
        case 5:
            ui->light5->setEnabled(true);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTON : %d", lightNum);

    }
}

void MainWindow::lightOff(int lightNum)
{
    switch (lightNum){
        case 0:
            ui->light0->setEnabled(false);
            break;
        case 1:
            ui->light1->setEnabled(false);
            break;
        case 2:
            ui->light2->setEnabled(false);
            break;
        case 3:
            ui->light3->setEnabled(false);
            break;
        case 4:
            ui->light4->setEnabled(false);
            break;
        case 5:
            ui->light5->setEnabled(false);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTOFF : %d", lightNum);

    }
}

