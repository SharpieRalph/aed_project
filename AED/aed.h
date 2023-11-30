#ifndef AED_H
#define AED_H
#include "patient.h"

#include <QObject>

class aed : public QObject
{
    Q_OBJECT

public:
    explicit aed(QObject *parent = nullptr); //init aed
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
    bool getOK();
    void setOK(bool);

    void beginProc(); //Begins running AED procedure

signals:
    void lightOn(int lightNum);
    void lightOff(int lightNum);

private:
    bool hasPower; //AED has power
    bool hasPatient; //AED has Patient
    bool correctPadPlacement; //AED has Pads correctly placed on patient
    bool patientShockable; //Patient has shockable conditions
    bool isOK; //Stores wether the AED is functional or not for the NOK Indicator
    bool activeCPR; //Patient has on going CPR
    int numShocks; //Number of shocks the AED has administered so far
    int statusECG; //status of ECG
    patient *currPatient; //Object representing patient currently connected by the AED's pads


};

#endif // AED_H
