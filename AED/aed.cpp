#include "aed.h"

aed::aed()
{
    hasPower = false;
    hasPatient = false;
    correctPadPlacement = false;
    patientShockable = false;
    activeCPR = false;
    numShocks = 0;
    statusECG = 0;
    currPatient = nullptr;
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
