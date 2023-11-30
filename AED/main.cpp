#include "mainwindow.h"
#include "aed.h"
#include "patient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    int numPatients = 4;
    aed *newAed = new aed();
    patient *newListOfPatients = new patient[numPatients];

    QApplication a(argc, argv);
    MainWindow w;
    w.setPatients(newListOfPatients);
    w.setAED(newAed);
    w.show();
    return a.exec();

    delete newAed;
    delete [] newListOfPatients;
}
