#include "patient.h"

int patient::nextPid = 0;

patient::patient()
{
    heartRate = 0;
    pid = nextPid;
    nextPid++;
    patientType = 0;
}

patient::~patient()
{

}

// ---------------------------- GETTERS ----------------------------

int patient::getPid()
{
    return pid;
}

int patient::getHeartRate() {
    return heartRate;
}

int patient::getPatientType() {
    return patientType;
}

// ---------------------------- SETTERS ----------------------------

void patient::setHeartRate(int hr)
{
    heartRate = hr;
}

void patient::setPatientType(int t) {
    patientType = t;
}
