/********************************************************************************
** Form generated from reading UI file 'rent_car.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENT_CAR_H
#define UI_RENT_CAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rent_Car
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Rent_Car)
    {
        if (Rent_Car->objectName().isEmpty())
            Rent_Car->setObjectName(QString::fromUtf8("Rent_Car"));
        Rent_Car->resize(800, 600);
        centralwidget = new QWidget(Rent_Car);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Rent_Car->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Rent_Car);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Rent_Car->setMenuBar(menubar);
        statusbar = new QStatusBar(Rent_Car);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Rent_Car->setStatusBar(statusbar);

        retranslateUi(Rent_Car);

        QMetaObject::connectSlotsByName(Rent_Car);
    } // setupUi

    void retranslateUi(QMainWindow *Rent_Car)
    {
        Rent_Car->setWindowTitle(QCoreApplication::translate("Rent_Car", "Rent_Car", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rent_Car: public Ui_Rent_Car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENT_CAR_H
