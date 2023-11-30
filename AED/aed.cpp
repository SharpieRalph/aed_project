#include "aed.h"

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

void aed::setPatient(patient *newPatient)
{
    currPatient = newPatient;
}

patient *aed::getPatient()
{
    return currPatient;
}

int aed::getShocks()
{
    return numShocks;
}

void aed::updateShocks()
{
    numShocks++;
}

void aed::setPower(bool newPower)
{
   hasPower = newPower;

   //If AED is turning on then start running aed program
   if (hasPower){
       beginProc();
   }
}

bool aed::getPower()
{
   return hasPower;
}

void aed::setCPR(bool newCPR)
{
    activeCPR = newCPR;
}

bool aed::getCPR()
{
    return activeCPR;
}

void aed::setPad(bool newPads)
{
    correctPadPlacement = newPads;
}

bool aed::getPad()
{
    return correctPadPlacement;
}

bool aed::getOK()
{
    return isOK;
}

void aed::setOK(bool newOK)
{
    isOK = newOK;
}

void aed::beginProc()
{
    //Flesh this out
}
