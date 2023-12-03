#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent, patient *newPatients)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), listOfPatients(newPatients)
{
    ui->setupUi(this);

    AED = new aed();    // Initializes AED
    listOfPatients = new patient[TOTAL_PATIENTS];   // Initializes listOfPatients
    AED->setPatient(&listOfPatients[0]);    // Sets the AED's current patient to the first patient in the "listOfPatients" list

    timer = new QTimer(this);
    LCDTimer = new QTimer(this);
    batteryBar = ui->batteryBar;

    connect( ui->pwrBtn, &QPushButton::clicked, this, &MainWindow::toggleTimer);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    connect(LCDTimer, &QTimer::timeout, this, &MainWindow::updateLCDTimer);


//    //Shows that null ptr was set
//    qInfo("%p",listOfPatients);
//    qInfo("%p",AED);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT (updatePatient(int)));
    connect(ui->pwrBtn, SIGNAL(clicked(bool)), this, SLOT (updatePower(bool)));
    connect(ui->toggleCPR, SIGNAL(clicked(bool)), this, SLOT (toggleActiveCPR(bool)));
    connect(ui->buttonGroup, SIGNAL(idClicked(int)), this, SLOT (updatePads(int)));
    ui->buttonGroup->setId(ui->padsGood, 0);
    ui->buttonGroup->setId(ui->padsBad, 1);

    //Connecting light signals/slots
    connect(AED, SIGNAL(lightOn(int)), this, SLOT (lightOn(int)));
    connect(AED, SIGNAL(lightOff(int)), this, SLOT (lightOff(int)));


    connect(AED, SIGNAL(updateText(int)), this, SLOT (updateText(int)));
    connect(AED, SIGNAL(updateLCDImg(int)), this, SLOT (updateLCDImg(int)));

    configurePatients();

}

MainWindow::~MainWindow()
{
    delete AED;
    delete ui;
}


// ---------------------------- FUNCTIONS ----------------------------


// Overrides the event where the "x" button at the top of the screen is clicked and the application is closed. Without this override, if the AED was switched on, the loop will continued indefinitely.
void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "Application closing...";
    AED->setPower(false);
    event->accept();
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

// Controls the starting and stopping of the timer used in the updatePower function
void MainWindow::toggleTimer()
{
    if (timer->isActive()) {
        // If the timer is active, stop it
        timer->stop();
    } else {
        // If the timer is not active, start it
        timer->start(1000); // Set the timer interval as needed (e.g., 1000 ms for 1 second)
    }
}

//Updates number of shocks in AED and on the ui by 1.
void MainWindow::updateShocks()
{
    AED->updateShocks();
    QString newShocks = QString("%1").arg(AED->getShocks());
    ui->shockCounter->setText(newShocks);
}

void MainWindow::updateProgressBar()
{
    int decrementValue = 1;
    int newValue =batteryBar->value() - decrementValue;

    if (newValue < 0){
        newValue = 0;
    }

    batteryBar->setValue(newValue);


    if (newValue == 0) {
        timer->stop();
    }
}

//Takes the list of patients from main and puts it into mainwindows patients list
void MainWindow::configurePatients()
{
    // Setting up adult patients
    listOfPatients[0].setHeartRate(80);     // adult - normal heart rate for adults is between 60bpm and 100bpm
    listOfPatients[1].setHeartRate(350);    // adult - vfib heart rate for adults is anything sbove 300bpm
    listOfPatients[2].setHeartRate(150);    // adult - vtach heart rate for adults is anything above 120bpm

    // Setting up child patients - patientType=0 is adult and automatically set in the constructor. We set patientType to 1 for child.
    listOfPatients[3].setHeartRate(100);    // child - normal heart rates are largely based on varying ages. 100bpm seems to be within normal range for all children ages 1 - 8
    listOfPatients[3].setPatientType(1);
    listOfPatients[4].setHeartRate(350);     // child - vfib; could not find any useful information for vfib in children, so using the same bpm as used for adults
    listOfPatients[4].setPatientType(1);
    listOfPatients[5].setHeartRate(190);    // child - vtach; sources differ on starting point between 180bpm and 200bpm.
    listOfPatients[5].setPatientType(1);
    listOfPatients[6].setHeartRate(0);      // flatline, age is meaningless for the device in this case

}


// ---------------------------- SLOTS ----------------------------


//Receives signial from ui and updates mainwindow accordingly
void MainWindow::updatePatient(int newPatient)
{
    //qInfo("ComboBox sent: %i", newPatient);
    AED->setPatient(&listOfPatients[newPatient]);
}

// Handles turning on the device as well as the loop that initates the entire functionality of the program
void MainWindow::updatePower(bool newPower)
{

    // Power on, AED functionality begins
    if(newPower){
        LCDTimer->start(1000);
        int stage = 0;  // Initial stage sent to "beginProc()"
        AED->setPower(true);
        nokOn();
        while(AED->getPower()) {
            if(stage != 0) {
                lightOff(stage-1);
                lightOn(stage);
            }
            AED->beginProc(stage);

            if(stage == 6) {
                lightOff(stage);
                stage = 4;

            } else {
                if(stage == 4 && !AED->getPatientShockable()) {
                    lightOff(stage);
                    stage++;
                }
                stage++;
            }
        }
    // Power off
    } else {
        AED->setPower(false);
        LCDTimer->stop();
        AED->setTimeOn(0);
        nokOff();
    }
}

// Handles the test that states whether or not CPR is being properly administered
void MainWindow::toggleActiveCPR(bool newCPR)
{
    if(newCPR) {
        ui->shallowCPRBtn->setEnabled(true);
        ui->adequateCPRBtn->setEnabled(true);
    } else {
        AED->setCPR(newCPR);
        ui->shallowCPRBtn->setEnabled(false);
        ui->adequateCPRBtn->setEnabled(false);
    }
}

// Handles the test to check if the pads are properly placed
void MainWindow::updatePads(int newPads)
{
//    qInfo("test: %i", newPads);
    if(newPads == 0){
        AED->setPadPlacement(true);
//        qInfo("correctPads: %i", AED->getPad());
    } else {
        AED->setPadPlacement(false);
//        qInfo("correctPads: %i", AED->getPad());
    }
}

// Function that handles updating the LCD timer
void MainWindow::updateLCDTimer() {

    // Calculates the minutes and seconds
    int min = AED->getTimeOn() / 60;
    int sec = AED->getTimeOn() % 60;

    ui->timerLabel->setText(QString("%1:%2").arg(min, 2, 10, QChar('0')).arg(sec, 2, 10, QChar('0')));

    AED->incrTimeOn();

}

// Switch case signal that handles which lights turn on
void MainWindow::lightOn(int lightNum)
{

    switch (lightNum){

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
        case 6:
            ui->light6->setEnabled(true);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTON : %d", lightNum);

    }
}

// Switch case signal that handles which lights turn off
void MainWindow::lightOff(int lightNum)
{
    switch (lightNum){

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
        case 6:
            ui->light6->setEnabled(false);
            break;
        default:
            qInfo("Invalid Light Arguement to MAINWINDOW::LIGHTOFF : %d", lightNum);

    }
}

// Switch case that handles what the visual instructions say on the LCD
void MainWindow::updateText(int textNum)
{
    switch(textNum){
        case 0:
            ui->LCD_text->setText("Stay Calm");
            break;
        case 1:
            ui->LCD_text->setText("Check Reponsiveness");
            break;
        case 2:
            ui->LCD_text->setText("Call For Help");
            break;
        case 3:
            ui->LCD_text->setText("Attach Defib Pads To Patients Bare Chest");
            break;
        case 4:
            ui->LCD_text->setText("Plug In Cable");
            break;
        case 5:
            ui->LCD_text->setText("Check Electrode Pads");
            break;
        case 6:
            ui->LCD_text->setText("Adult Pads");
            break;
        case 7:
            ui->LCD_text->setText("Pediatric Pads");
            break;
        case 8:
            ui->LCD_text->setText("Dont Touch Patient. Analyzing");
            break;
        case 9:
          ui->LCD_text->setText("Stand Clear. Do Not Touch The Patient. Shock Will Be Delivered In Three..Two..One..");
          AED->delay(3);
          ui->LCD_text->setText("Shock Delivered.");
          updateShocks();
          break;
        case 10:
            ui->LCD_text->setText("Start CPR");
            break;
        case 11:
            ui->LCD_text->setText("Push Harder");
            break;
        case 12:
            ui->LCD_text->setText("Stop CPR");
            break;
    }
}

// Switch case that handles what ECG Waveform is shown in the LCD
void MainWindow::updateLCDImg(int diag) {
    switch (diag) {
        //V-Fib
        case 0:
            // Update LCD to V-Fib ECG
            qInfo("Update LCD to V-Fib ECG");
            break;
        // V-Tach
        case 1:
            // Update LCD to V-Tach ECG
            qInfo("Update LCD to V-Tach ECG");
            break;
        case 2:
            // Update LCD to Flatline ECG
            qInfo("Update LCD to Flatline ECG");
            break;
        case 3:
            // Update LCD to Normal ECG
            qInfo("Update LCD to Normal ECG");
            break;
    }
}

// Updates the GUI and AED to "shallow CPR" being administered
void MainWindow::on_shallowCPRBtn_clicked(bool checked)
{
    ui->adequateCPRBtn->setChecked(!checked);

    std::srand(std::time(0));

    int randomNumber = std::rand() % 65 + 1;

    ui->CPRDepthBar->setValue(randomNumber);
    ui->minCPRLine->setStyleSheet("background: rgb(61, 56, 70)");
    AED->setCPR(!checked);
}

// Updates the GUI and AED to "adequate CPR" being administered
void MainWindow::on_adequateCPRBtn_clicked(bool checked)
{
    ui->shallowCPRBtn->setChecked(!checked);

    std::srand(std::time(0));
    int randomNumber = std::rand() % (86 - 67 + 1) + 67;

    ui->CPRDepthBar->setValue(randomNumber);
    ui->minCPRLine->setStyleSheet("background-color: #b0b0b0");

    AED->setCPR(checked);
}

// Updates the GUI and AED to "adult pads"
void MainWindow::on_adultPadBtn_clicked()
{
    AED->setPadType(0);
    ui->pedPadBtn->setChecked(false);
}

// Updates the GUI and AED to "Pediatric Pads"
void MainWindow::on_pedPadBtn_clicked()
{
    AED->setPadType(1);
    ui->adultPadBtn->setChecked(false );
}

