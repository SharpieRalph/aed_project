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
#include <QtWidgets/QGroupBox>
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
    QLabel *light6;
    QLabel *light5;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QPushButton *toggleCPR;
    QLabel *label_2;
    QPushButton *shallowCPRBtn;
    QLabel *label;
    QPushButton *adequateCPRBtn;
    QGroupBox *LCD;
    QLabel *shocksLabel;
    QLabel *shockCounter;
    QLabel *timerLabel;
    QProgressBar *CPRDepthBar;
    QFrame *minCPRLine;
    QFrame *maxCPRLine;
    QLabel *LCD_text;
    QProgressBar *batteryBar;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *padsGood;
    QPushButton *padsBad;
    QPushButton *adultPadBtn;
    QPushButton *pedPadBtn;
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
        line->setGeometry(QRect(887, -30, 20, 801));
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
        NOKindicator->setStyleSheet(QString::fromUtf8(""));
        light1 = new QLabel(centralwidget);
        light1->setObjectName(QString::fromUtf8("light1"));
        light1->setEnabled(false);
        light1->setGeometry(QRect(298, 368, 31, 31));
        light1->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light1->setScaledContents(true);
        Loop = new QLabel(centralwidget);
        Loop->setObjectName(QString::fromUtf8("Loop"));
        Loop->setEnabled(true);
        Loop->setGeometry(QRect(110, 80, 761, 681));
        Loop->setPixmap(QPixmap(QString::fromUtf8(":/res/bkg")));
        Loop->setScaledContents(true);
        light2 = new QLabel(centralwidget);
        light2->setObjectName(QString::fromUtf8("light2"));
        light2->setEnabled(false);
        light2->setGeometry(QRect(429, 202, 31, 31));
        light2->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light2->setScaledContents(true);
        light3 = new QLabel(centralwidget);
        light3->setObjectName(QString::fromUtf8("light3"));
        light3->setEnabled(false);
        light3->setGeometry(QRect(645, 438, 31, 31));
        light3->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light3->setScaledContents(true);
        light4 = new QLabel(centralwidget);
        light4->setObjectName(QString::fromUtf8("light4"));
        light4->setEnabled(false);
        light4->setGeometry(QRect(645, 599, 41, 41));
        light4->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light4->setScaledContents(true);
        light6 = new QLabel(centralwidget);
        light6->setObjectName(QString::fromUtf8("light6"));
        light6->setEnabled(false);
        light6->setGeometry(QRect(316, 618, 31, 31));
        light6->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light6->setScaledContents(true);
        light5 = new QLabel(centralwidget);
        light5->setObjectName(QString::fromUtf8("light5"));
        light5->setEnabled(false);
        light5->setGeometry(QRect(471, 475, 31, 31));
        light5->setPixmap(QPixmap(QString::fromUtf8(":/res/light2")));
        light5->setScaledContents(true);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 30, 181, 25));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(910, 250, 285, 161));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        toggleCPR = new QPushButton(groupBox);
        toggleCPR->setObjectName(QString::fromUtf8("toggleCPR"));
        toggleCPR->setGeometry(QRect(77, 40, 130, 31));
        toggleCPR->setCheckable(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(67, 10, 150, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        shallowCPRBtn = new QPushButton(groupBox);
        shallowCPRBtn->setObjectName(QString::fromUtf8("shallowCPRBtn"));
        shallowCPRBtn->setEnabled(false);
        shallowCPRBtn->setGeometry(QRect(150, 117, 120, 31));
        shallowCPRBtn->setCheckable(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(67, 84, 150, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        adequateCPRBtn = new QPushButton(groupBox);
        adequateCPRBtn->setObjectName(QString::fromUtf8("adequateCPRBtn"));
        adequateCPRBtn->setEnabled(false);
        adequateCPRBtn->setGeometry(QRect(15, 120, 120, 31));
        adequateCPRBtn->setCheckable(true);
        LCD = new QGroupBox(centralwidget);
        LCD->setObjectName(QString::fromUtf8("LCD"));
        LCD->setGeometry(QRect(368, 260, 241, 151));
        LCD->setStyleSheet(QString::fromUtf8("background: #b0b0b0;\n"
"border-radius: 5px;\n"
""));
        shocksLabel = new QLabel(LCD);
        shocksLabel->setObjectName(QString::fromUtf8("shocksLabel"));
        shocksLabel->setGeometry(QRect(8, 6, 62, 17));
        shockCounter = new QLabel(LCD);
        shockCounter->setObjectName(QString::fromUtf8("shockCounter"));
        shockCounter->setGeometry(QRect(71, 6, 16, 17));
        timerLabel = new QLabel(LCD);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        timerLabel->setGeometry(QRect(171, 6, 62, 17));
        timerLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CPRDepthBar = new QProgressBar(LCD);
        CPRDepthBar->setObjectName(QString::fromUtf8("CPRDepthBar"));
        CPRDepthBar->setGeometry(QRect(203, 30, 25, 71));
        CPRDepthBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	border: 2px solid rgb(61,56,70);\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(61, 56, 70)\n"
"}"));
        CPRDepthBar->setValue(0);
        CPRDepthBar->setOrientation(Qt::Vertical);
        CPRDepthBar->setInvertedAppearance(true);
        minCPRLine = new QFrame(LCD);
        minCPRLine->setObjectName(QString::fromUtf8("minCPRLine"));
        minCPRLine->setGeometry(QRect(203, 76, 25, 3));
        minCPRLine->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 56, 70);"));
        minCPRLine->setFrameShape(QFrame::HLine);
        minCPRLine->setFrameShadow(QFrame::Sunken);
        maxCPRLine = new QFrame(LCD);
        maxCPRLine->setObjectName(QString::fromUtf8("maxCPRLine"));
        maxCPRLine->setGeometry(QRect(203, 90, 25, 3));
        maxCPRLine->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 56, 70);"));
        maxCPRLine->setFrameShape(QFrame::HLine);
        maxCPRLine->setFrameShadow(QFrame::Sunken);
        LCD_text = new QLabel(LCD);
        LCD_text->setObjectName(QString::fromUtf8("LCD_text"));
        LCD_text->setGeometry(QRect(15, 30, 181, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        LCD_text->setFont(font2);
        LCD_text->setAlignment(Qt::AlignCenter);
        LCD_text->setWordWrap(true);
        batteryBar = new QProgressBar(LCD);
        batteryBar->setObjectName(QString::fromUtf8("batteryBar"));
        batteryBar->setGeometry(QRect(104, 5, 71, 16));
        batteryBar->setValue(95);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(910, 80, 285, 160));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(32, 10, 220, 17));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(87, 84, 110, 20));
        label_6->setFont(font1);
        padsGood = new QPushButton(groupBox_2);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(padsGood);
        padsGood->setObjectName(QString::fromUtf8("padsGood"));
        padsGood->setGeometry(QRect(15, 115, 120, 30));
        padsGood->setCheckable(true);
        padsBad = new QPushButton(groupBox_2);
        buttonGroup->addButton(padsBad);
        padsBad->setObjectName(QString::fromUtf8("padsBad"));
        padsBad->setGeometry(QRect(150, 115, 120, 30));
        padsBad->setCheckable(true);
        adultPadBtn = new QPushButton(groupBox_2);
        adultPadBtn->setObjectName(QString::fromUtf8("adultPadBtn"));
        adultPadBtn->setGeometry(QRect(20, 40, 110, 25));
        adultPadBtn->setCheckable(true);
        pedPadBtn = new QPushButton(groupBox_2);
        pedPadBtn->setObjectName(QString::fromUtf8("pedPadBtn"));
        pedPadBtn->setGeometry(QRect(155, 40, 110, 25));
        pedPadBtn->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);
        line->raise();
        pwrBtn->raise();
        NOKindicator->raise();
        Loop->raise();
        light1->raise();
        light2->raise();
        light3->raise();
        light4->raise();
        light6->raise();
        light5->raise();
        comboBox->raise();
        groupBox->raise();
        LCD->raise();
        groupBox_2->raise();
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
        light6->setText(QString());
        light5->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Normal - Adult", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Ventricular Fibrillation - Adult", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Ventricular Tachycardia - Adult", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Normal - Child", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Ventricular Fibrillation - Child", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Ventricular Tachycardia - Child", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Flatline", nullptr));

        groupBox->setTitle(QString());
        toggleCPR->setText(QCoreApplication::translate("MainWindow", "Toggle Giving CPR", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CPR TESTING", nullptr));
        shallowCPRBtn->setText(QCoreApplication::translate("MainWindow", "Toggle Shallow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Compression Depth", nullptr));
        adequateCPRBtn->setText(QCoreApplication::translate("MainWindow", "Toggle Adequate", nullptr));
        LCD->setTitle(QString());
        shocksLabel->setText(QCoreApplication::translate("MainWindow", "SHOCKS:", nullptr));
        shockCounter->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        timerLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        CPRDepthBar->setFormat(QString());
        LCD_text->setText(QString());
        groupBox_2->setTitle(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "DEFIB PAD TESTING", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Pad Placement", nullptr));
        padsGood->setText(QCoreApplication::translate("MainWindow", "Place Correctly", nullptr));
        padsBad->setText(QCoreApplication::translate("MainWindow", "Placed Incorrectly", nullptr));
        adultPadBtn->setText(QCoreApplication::translate("MainWindow", "Adult Pads", nullptr));
        pedPadBtn->setText(QCoreApplication::translate("MainWindow", "Pediatric Pads", nullptr));
        menuAED->setTitle(QCoreApplication::translate("MainWindow", "AED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
