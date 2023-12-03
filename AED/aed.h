#ifndef AED_H
#define AED_H
#include "patient.h"

#include <QObject>

class aed : public QObject
{
    Q_OBJECT

public:
    explicit aed(QObject *parent = nullptr); //init aed

    patient *getPatient();
    int getShocks();
    bool getPower();
    bool getCPR();
    bool getPadPlacement();     // True = placed correctly, false = placed incorrectly
    bool getOK();
    patient* getCurrPatient();
    int getTimeOn();
    int getPadType();
    bool getPatientShockable();

    void setPatient(patient *newPatient);
    void setPower(bool newPower);
    void setCPR(bool newCPR);
    void setPadPlacement(bool newPads);
    void setOK(bool);
    void setTimeOn(int);
    void setPadType(int);
    void setPatientShockable(bool);

    void updateShocks();
    void delay(int);
    void POSelfTest();
    void beginProc(int); //Begins running AED procedure
    void incrTimeOn();
    void analysis();

signals:

    void lightOn(int lightNum);
    void lightOff(int lightNum);
    void updateText(int textNum);
    void updateLCDImg(int diag);

private:
    bool hasPower; //AED has power
    bool hasPatient; //AED has Patient
    int padType;   // Adult or Pediatric Pads - adult = 0, child = 1, not choice = -1
    bool correctPadPlacement; //AED has Pads correctly placed on patient
    bool patientShockable; //Patient has shockable conditions
    bool isOK; //Stores wether the AED is functional or not for the NOK Indicator
    bool activeCPR; //Patient has on going CPR
    static int timeOn;
    int numShocks; //Number of shocks the AED has administered so far
    int statusECG; //status of ECG
    patient *currPatient; //Object representing patient currently connected by the AED's pads


};

#endif // AED_H
