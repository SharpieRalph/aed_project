#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, patient *newPatients)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), listOfPatients(newPatients)
{
    ui->setupUi(this);
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
    delete ui;
}

//Takes the list of patients from main and puts it into mainwindows patients list
void MainWindow::setPatients(patient *newPatients)
{
    listOfPatients = newPatients;
//    //Tests that patients were sent to mainwindow
//    qInfo("%i", listOfPatients[0].getPid());
//    qInfo("%i", listOfPatients[2].getPid());
//    qInfo("%i", listOfPatients[1].getPid());
//    qInfo("%i", listOfPatients[3].getPid());
}

//Takes the AED from man and sets it as mainwindow's AED
void MainWindow::setAED(aed *newAED)
{
    AED = newAED;
//    //Check that this works
//    AED->setPatient(&listOfPatients[2]);
//    qInfo("%i", AED->getPatient()->getPid());
//    //checkUpdateShocks()
//    updateShocks();

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
    bool working = AED->getOK();

    if (working){
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
//    qInfo("ComboBox sent: %i", newPatient);
    AED->setPatient(&listOfPatients[newPatient]);
}

void MainWindow::updatePower(bool newPower)
{
    if(newPower){
        AED->setPower(true);
        nokOn();
//        qInfo("%d", AED->getPower());
    } else {
        AED->setPower(false);
        nokOff();
//        qInfo("%d", AED->getPower());
    }
}

void MainWindow::updateCPR(bool newCPR)
{
    if(newCPR){
        AED->setCPR(true);
//        qInfo("%d", AED->getCPR());
    } else {
        AED->setCPR(false);
//        qInfo("%d", AED->getCPR());
    }
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
    bool pwr = true;
    switch (lightNum){
        case 0:
            ui->light0->setEnabled(pwr);
            break;
        case 1:
            ui->light1->setEnabled(pwr);
            break;
        case 2:
            ui->light2->setEnabled(pwr);
            break;
        case 3:
            ui->light3->setEnabled(pwr);
            break;
        case 4:
            ui->light4->setEnabled(pwr);
            break;
        case 5:
            ui->light5->setEnabled(pwr);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTON : %d", lightNum);

    }
}

void MainWindow::lightOff(int lightNum)
{
    bool pwr = false;
    switch (lightNum){
        case 0:
            ui->light0->setEnabled(pwr);
            break;
        case 1:
            ui->light1->setEnabled(pwr);
            break;
        case 2:
            ui->light2->setEnabled(pwr);
            break;
        case 3:
            ui->light3->setEnabled(pwr);
            break;
        case 4:
            ui->light4->setEnabled(pwr);
            break;
        case 5:
            ui->light5->setEnabled(pwr);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTOFF : %d", lightNum);

    }
}

