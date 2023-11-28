#include "patient.h"

int patient::nextPid = 0;

patient::patient()
{
    status = 0;
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
