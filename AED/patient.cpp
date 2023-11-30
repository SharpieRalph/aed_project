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

int patient::getPid()
{
    return pid;
}

int patient::getHeartRate() {
    return heartRate;
}

void patient::setHeartRate(int hr)
{
    heartRate = hr;
}
