#ifndef PATIENT_H
#define PATIENT_H

//This class enables us to have a list of possible patient scenario's.
//current list is:
//pid 0 = regular patient
//pid 1 = patient with ventricular fibrillation
//pid 2 = patient with ventricular tachycardia
//pid 3 = dead patient
class patient
{
public:
    patient(); //init patient
    ~patient(); //delete patient

    int getPid();
    int getHeartRate();
    void setHeartRate(int);

private:
    int heartRate; //patient heart rhythm status, note this may not be needed as pid might function as both status and id
    int pid; //patient id
    int patientType; //patient child or adult
    static int nextPid; //used to set patient id for each created patient object
};

#endif // PATIENT_H
