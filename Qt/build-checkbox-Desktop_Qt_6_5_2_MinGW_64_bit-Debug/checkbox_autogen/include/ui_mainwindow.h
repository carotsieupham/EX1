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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_ok;
    QCheckBox *cb_option_2;
    QCheckBox *cb_option_1;
    QPlainTextEdit *Edit;
    QLabel *lb_food;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(468, 201);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn_ok = new QPushButton(centralwidget);
        btn_ok->setObjectName("btn_ok");
        btn_ok->setGeometry(QRect(110, 110, 80, 18));
        cb_option_2 = new QCheckBox(centralwidget);
        cb_option_2->setObjectName("cb_option_2");
        cb_option_2->setGeometry(QRect(120, 80, 101, 18));
        cb_option_1 = new QCheckBox(centralwidget);
        cb_option_1->setObjectName("cb_option_1");
        cb_option_1->setGeometry(QRect(120, 60, 91, 18));
        Edit = new QPlainTextEdit(centralwidget);
        Edit->setObjectName("Edit");
        Edit->setGeometry(QRect(100, 30, 111, 20));
        lb_food = new QLabel(centralwidget);
        lb_food->setObjectName("lb_food");
        lb_food->setGeometry(QRect(100, 10, 331, 20));
        QFont font;
        font.setPointSize(13);
        lb_food->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 468, 17));
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
        btn_ok->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
        cb_option_2->setText(QCoreApplication::translate("MainWindow", "Th\341\272\241ch ph\303\264 mai", nullptr));
        cb_option_1->setText(QCoreApplication::translate("MainWindow", "Tr\303\242n ch\303\242u", nullptr));
        lb_food->setText(QCoreApplication::translate("MainWindow", "M\303\263n c\341\273\247a b\341\272\241n ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
