/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QPushButton *pwrBtn;
    QTextBrowser *NOKindicator;
    QLabel *light1;
    QLabel *Loop;
    QLabel *light2;
    QLabel *light3;
    QLabel *light4;
    QLabel *light5;
    QLabel *light0;
    QLabel *LCD_text;
    QLabel *shocksLabel;
    QLabel *shockCounter;
    QLabel *label;
    QLabel *placementLabel;
    QLabel *placementIndicator;
    QProgressBar *batteryBar;
    QPushButton *padsGood;
    QPushButton *padsBad;
    QPushButton *toggleCPR;
    QComboBox *comboBox;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAED;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1355, 810);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(940, -30, 20, 801));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pwrBtn = new QPushButton(centralwidget);
        pwrBtn->setObjectName(QString::fromUtf8("pwrBtn"));
        pwrBtn->setGeometry(QRect(320, 20, 121, 51));
        pwrBtn->setCheckable(true);
        NOKindicator = new QTextBrowser(centralwidget);
        NOKindicator->setObjectName(QString::fromUtf8("NOKindicator"));
        NOKindicator->setEnabled(false);
        NOKindicator->setGeometry(QRect(450, 20, 91, 51));
        light1 = new QLabel(centralwidget);
        light1->setObjectName(QString::fromUtf8("light1"));
        light1->setEnabled(false);
        light1->setGeometry(QRect(320, 370, 31, 31));
        light1->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light1->setScaledContents(true);
        Loop = new QLabel(centralwidget);
        Loop->setObjectName(QString::fromUtf8("Loop"));
        Loop->setEnabled(true);
        Loop->setGeometry(QRect(130, 80, 761, 681));
        Loop->setPixmap(QPixmap(QString::fromUtf8(":/res/bkg")));
        Loop->setScaledContents(true);
        light2 = new QLabel(centralwidget);
        light2->setObjectName(QString::fromUtf8("light2"));
        light2->setEnabled(false);
        light2->setGeometry(QRect(450, 200, 31, 31));
        light2->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light2->setScaledContents(true);
        light3 = new QLabel(centralwidget);
        light3->setObjectName(QString::fromUtf8("light3"));
        light3->setEnabled(false);
        light3->setGeometry(QRect(660, 440, 31, 31));
        light3->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light3->setScaledContents(true);
        light4 = new QLabel(centralwidget);
        light4->setObjectName(QString::fromUtf8("light4"));
        light4->setEnabled(false);
        light4->setGeometry(QRect(670, 600, 41, 41));
        light4->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light4->setScaledContents(true);
        light5 = new QLabel(centralwidget);
        light5->setObjectName(QString::fromUtf8("light5"));
        light5->setEnabled(false);
        light5->setGeometry(QRect(340, 620, 31, 31));
        light5->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light5->setScaledContents(true);
        light0 = new QLabel(centralwidget);
        light0->setObjectName(QString::fromUtf8("light0"));
        light0->setEnabled(false);
        light0->setGeometry(QRect(490, 480, 31, 31));
        light0->setPixmap(QPixmap(QString::fromUtf8(":/res/light")));
        light0->setScaledContents(true);
        LCD_text = new QLabel(centralwidget);
        LCD_text->setObjectName(QString::fromUtf8("LCD_text"));
        LCD_text->setGeometry(QRect(440, 310, 121, 17));
        LCD_text->setAlignment(Qt::AlignCenter);
        shocksLabel = new QLabel(centralwidget);
        shocksLabel->setObjectName(QString::fromUtf8("shocksLabel"));
        shocksLabel->setGeometry(QRect(390, 290, 62, 17));
        shockCounter = new QLabel(centralwidget);
        shockCounter->setObjectName(QString::fromUtf8("shockCounter"));
        shockCounter->setGeometry(QRect(440, 290, 62, 17));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 290, 62, 17));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        placementLabel = new QLabel(centralwidget);
        placementLabel->setObjectName(QString::fromUtf8("placementLabel"));
        placementLabel->setGeometry(QRect(390, 390, 81, 17));
        placementIndicator = new QLabel(centralwidget);
        placementIndicator->setObjectName(QString::fromUtf8("placementIndicator"));
        placementIndicator->setGeometry(QRect(470, 390, 62, 17));
        batteryBar = new QProgressBar(centralwidget);
        batteryBar->setObjectName(QString::fromUtf8("batteryBar"));
        batteryBar->setGeometry(QRect(560, 390, 71, 16));
        batteryBar->setValue(95);
        padsGood = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(padsGood);
        padsGood->setObjectName(QString::fromUtf8("padsGood"));
        padsGood->setGeometry(QRect(960, 10, 191, 81));
        padsGood->setCheckable(true);
        padsBad = new QPushButton(centralwidget);
        buttonGroup->addButton(padsBad);
        padsBad->setObjectName(QString::fromUtf8("padsBad"));
        padsBad->setGeometry(QRect(1160, 10, 191, 81));
        padsBad->setCheckable(true);
        toggleCPR = new QPushButton(centralwidget);
        toggleCPR->setObjectName(QString::fromUtf8("toggleCPR"));
        toggleCPR->setGeometry(QRect(1050, 640, 231, 111));
        toggleCPR->setCheckable(true);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 30, 181, 25));
        MainWindow->setCentralWidget(centralwidget);
        line->raise();
        pwrBtn->raise();
        NOKindicator->raise();
        Loop->raise();
        light1->raise();
        light2->raise();
        light3->raise();
        light4->raise();
        light5->raise();
        light0->raise();
        LCD_text->raise();
        shocksLabel->raise();
        shockCounter->raise();
        label->raise();
        placementLabel->raise();
        placementIndicator->raise();
        batteryBar->raise();
        padsGood->raise();
        padsBad->raise();
        toggleCPR->raise();
        comboBox->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1355, 22));
        menuAED = new QMenu(menubar);
        menuAED->setObjectName(QString::fromUtf8("menuAED"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAED->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pwrBtn->setText(QCoreApplication::translate("MainWindow", "ON / OFF", nullptr));
        NOKindicator->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; color:#5e5c64;\">OFF</span></p></body></html>", nullptr));
        light1->setText(QString());
        Loop->setText(QString());
        light2->setText(QString());
        light3->setText(QString());
        light4->setText(QString());
        light5->setText(QString());
        light0->setText(QString());
        LCD_text->setText(QCoreApplication::translate("MainWindow", "MAIN_TEXT", nullptr));
        shocksLabel->setText(QCoreApplication::translate("MainWindow", "Shocks:", nullptr));
        shockCounter->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        placementLabel->setText(QCoreApplication::translate("MainWindow", "Placement:", nullptr));
        placementIndicator->setText(QCoreApplication::translate("MainWindow", "OKAY", nullptr));
        padsGood->setText(QCoreApplication::translate("MainWindow", "Place Pads Correctly", nullptr));
        padsBad->setText(QCoreApplication::translate("MainWindow", "Place Pads Incorrectly", nullptr));
        toggleCPR->setText(QCoreApplication::translate("MainWindow", "Toggle Giving CPR", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Ventricular Fibrillation", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Ventricular Tachycardia", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Dead", nullptr));

        menuAED->setTitle(QCoreApplication::translate("MainWindow", "AED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
