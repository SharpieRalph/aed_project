#include "aed.h"
#include <QTime>
#include <QCoreApplication>

int aed::timeOn = 0;

aed::aed(QObject *parent)
    : QObject{parent}
{
    hasPower = false;
    hasPatient = false;
    padType = -1;
    correctPadPlacement = false;
    patientShockable = false;
    activeCPR = false;
    numShocks = 0;
    statusECG = 0;
    currPatient = nullptr;
    isOK = true;
    showECG = false;
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

bool aed::getPadPlacement()
{
    return correctPadPlacement;
}

bool aed::getOK()
{
    return isOK;
}

patient* aed::getCurrPatient() {
    return currPatient;
}

int aed::getTimeOn() {
    return timeOn;
}

int aed::getPadType() {
   return padType;
}

bool aed::getPatientShockable() {
    return patientShockable;
}

bool aed::getShowECG() {
    return showECG;
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

void aed::setPadPlacement(bool newPads)
{
    correctPadPlacement = newPads;
}

void aed::setOK(bool newOK)
{
    isOK = newOK;
}

void aed::setTimeOn(int s) {
    timeOn = s;
}

void aed::setPadType(int t) {
    padType = t;
}

void aed::setPatientShockable(bool s) {
    patientShockable = s;
}

void aed::setShowECG(bool newShowECG) {
    showECG = newShowECG;
}

// ---------------------------- FUNCTIONS ----------------------------

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
            qInfo("Audio Output: Stay Calm");
            emit(updateText(0));
            delay(2);
            break;
        case 1:
            qInfo("Audio Output: Check Reponsiveness");
            emit(updateText(1));
            delay(2);
            break;
        case 2:
            qInfo("Audio Output: Call For Help");
            emit(updateText(2));
            delay(2);
            break;
        case 3:
            qInfo("Audio Output: Attach Defib Pads To Patients Bare Chest");
            emit(updateText(3));
            delay(2);
            while((getPadType() < 0 || !getPadPlacement()) && getPower()) {
                if(getPadType() < 0) {
                             qInfo("Audio Output: Plug In Cable.");
                             emit(updateText(4));
                             delay(2);
                }
                if(!getPadPlacement()) {
                    qInfo("Audio Output: Check Electrode Pads");
                    emit(updateText(5));
                    delay(2);
                }
            }
            if(getPadType() == 0) {
                qInfo("Audio Output: Adult Pads");
                emit(updateText(6));
                delay(2);
            } else {
                qInfo("Audio Output: Pediatric Pads");
                emit(updateText(7));
                delay(2);
            }
            break;
        case 4:
            qInfo("Audio Output: Dont Touch Patient. Analyzing");
            emit(updateText(8));
            delay(2);
            analysis();
            break;

        case 5:
            qInfo("Audio Output: Stand Clear. Do Not Touch The Patient. Shock Will Be Delivered In Three..Two..One..");
            emit(updateText(9));
            qInfo("Audio Output: Shock Delivered.");
            //Give 0 to 4 so 1 in 5 chances that patient returns to normal
            if(rand() % 5 == 0) {
                qInfo("Patient has been resuscitated.");
                //Check if patient is Adult or Child
                if(getCurrPatient()->getPatientType()==0){
                    emit(updatePatient(0));
                } else {
                    emit(updatePatient(3));
                }
            }
            delay(2);
        break;
        case 6:
            qInfo("Audio Output: Start CPR");
            emit(updateText(10));
            delay(2);
            while(getPower() && !getCPR()){
                qInfo("Audio Output: Push Harder");
                emit(updateText(11));
                delay(2);
            }
            if(getPower()) {
                qInfo("2 Minutes goes by while CPR is consistently administered");
                delay(1);
                qInfo("Audio Output: Stop CPR");
                emit(updateText(12));
                delay(1);
            }
            break;
    }
}

void aed::incrTimeOn() {
    timeOn++;
}

void aed::analysis() {

    if(getCurrPatient()->getHeartRate() >= 300) {
        // V-Fib
        patientShockable = true;
        emit(updateLCDImg(0));
    } else if (getCurrPatient()->getHeartRate() > 120 && getCurrPatient()->getHeartRate() < 300) {
        // V-Tach
        patientShockable = true;
        emit(updateLCDImg(1));
        emit(updateText(1));
    } else if (getCurrPatient()->getHeartRate() == 0) {
        // Flatline
        emit(updateLCDImg(2));
        emit(updateText(2));
    } else {
        // Within normal ranges
        emit(updateLCDImg(3));
        emit(updateText(3));
    }
}
