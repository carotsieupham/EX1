/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QRadioButton *rd_boys;
    QRadioButton *rd_girl;
    QLabel *lb_gender;
    QPushButton *btn_check;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(361, 183);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(100, 30, 120, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        rd_boys = new QRadioButton(frame);
        rd_boys->setObjectName("rd_boys");
        rd_boys->setGeometry(QRect(20, 20, 69, 18));
        rd_girl = new QRadioButton(frame);
        rd_girl->setObjectName("rd_girl");
        rd_girl->setGeometry(QRect(20, 50, 69, 18));
        lb_gender = new QLabel(centralwidget);
        lb_gender->setObjectName("lb_gender");
        lb_gender->setGeometry(QRect(120, 0, 111, 31));
        QFont font;
        font.setPointSize(20);
        lb_gender->setFont(font);
        btn_check = new QPushButton(centralwidget);
        btn_check->setObjectName("btn_check");
        btn_check->setGeometry(QRect(120, 120, 80, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 361, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rd_boys->setText(QCoreApplication::translate("MainWindow", "Nam", nullptr));
        rd_girl->setText(QCoreApplication::translate("MainWindow", "N\341\273\257", nullptr));
        lb_gender->setText(QCoreApplication::translate("MainWindow", "Gi\341\273\233i t\303\255nh", nullptr));
        btn_check->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
