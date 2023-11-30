#include "aed.h"
#include <QTime>
#include <QCoreApplication>

aed::aed(QObject *parent)
    : QObject{parent}
{
    hasPower = false;
    hasPatient = false;
    correctPadPlacement = false;
    patientShockable = false;
    activeCPR = false;
    numShocks = 0;
    statusECG = 0;
    currPatient = nullptr;
    isOK = true;
}

// ---------------------------- GETTERS ----------------------------

patient *aed::getPatient()
{
    return currPatient;
}

int aed::getShocks()
{
    return numShocks;
}

bool aed::getPower()
{
   return hasPower;
}

bool aed::getCPR()
{
    return activeCPR;
}

bool aed::getPad()
{
    return correctPadPlacement;
}

bool aed::getOK()
{
    return isOK;
}

// ---------------------------- SETTERS ----------------------------

void aed::setPatient(patient *newPatient)
{
    currPatient = newPatient;
}

void aed::setPower(bool newPower)
{
   hasPower = newPower;

   //If AED is turning on then start running aed program
//   if (hasPower){
//       beginProc();
//   }
}

void aed::setCPR(bool newCPR)
{
    activeCPR = newCPR;
}

void aed::setPad(bool newPads)
{
    correctPadPlacement = newPads;
}

void aed::setOK(bool newOK)
{
    isOK = newOK;
}

// ---------------------------- OTHERS ----------------------------

void aed::updateShocks()
{
    numShocks++;
}

// Helper function to allow the user to easily change how much time in seconds to wait
void aed::delay(int s) {
    QTime eTime = QTime::currentTime().addSecs(s);
    while(QTime::currentTime() < eTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void aed::POSelfTest()
{
    // NEED TO IMPLEMENT
    qInfo("Administering self test");
    delay(1);
    qInfo("A/V Output: Test Complete - Unit Okay");
    delay(1);
}

void aed::beginProc(int i)
{

    switch (i) {
        case 0:
            POSelfTest();
            qInfo("A/V Output: Stay Calm");
            delay(2);
            break;
        case 1:
            qInfo("A/V Output: Check Reponsiveness");
            delay(2);
            break;
        case 2:
            qInfo("A/V Output: Call For Help");
            delay(2);
            break;
        case 3:
            qInfo("A/V Output: Attach Defib Pads To Patients Bare Chest");
            delay(2);
            break;
        case 4:
            qInfo("A/V Output: Dont Touch Patient. Analyzing");
            delay(2);
            break;
        case 5:
            qInfo("A/V Output: Start CPR");
            delay(2);
            while(getPower() && !getCPR()){
                qInfo("Push Harder");
                delay(2);
            }
            if(getPower()) {
                qInfo("2 Minutes goes by while CPR is consistently administered");
                delay(1);
                qInfo("A/V Output: Stop CPR");
                delay(1);
            }
            break;
    }



}
