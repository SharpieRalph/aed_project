#ifndef AED_H
#define AED_H
#include "patient.h"

class aed
{
public:
    aed(); //init aed
    void setPatient(patient *newPatient);
    patient *getPatient();
    int getShocks();
    void updateShocks();
    void setPower(bool newPower);
    bool getPower();
    void setCPR(bool newCPR);
    bool getCPR();
    void setPad(bool newPads);
    bool getPad();

private:
    bool hasPower; //AED has power
    bool hasPatient; //AED has Patient
    bool correctPadPlacement; //AED has Pads correctly placed on patient
    bool patientShockable; //Patient has shockable conditions
    bool activeCPR; //Patient has on going CPR
    int numShocks; //Number of shocks the AED has administered so far
    int statusECG; //status of ECG
    patient *currPatient; //Object representing patient currently connected by the AED's pads
};

#endif // AED_H
