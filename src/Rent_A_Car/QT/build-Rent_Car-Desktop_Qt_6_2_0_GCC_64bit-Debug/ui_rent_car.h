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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rent_Car
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ingCiudades;
    QLineEdit *lineEdit_ciudades;
    QPushButton *pushButton_aceptar_Cciudades;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_adyacencia;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Rent_Car)
    {
        if (Rent_Car->objectName().isEmpty())
            Rent_Car->setObjectName(QString::fromUtf8("Rent_Car"));
        Rent_Car->resize(760, 458);
        centralwidget = new QWidget(Rent_Car);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 449, 131));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ingCiudades = new QLabel(groupBox);
        label_ingCiudades->setObjectName(QString::fromUtf8("label_ingCiudades"));

        horizontalLayout->addWidget(label_ingCiudades);

        lineEdit_ciudades = new QLineEdit(groupBox);
        lineEdit_ciudades->setObjectName(QString::fromUtf8("lineEdit_ciudades"));

        horizontalLayout->addWidget(lineEdit_ciudades);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_aceptar_Cciudades = new QPushButton(groupBox);
        pushButton_aceptar_Cciudades->setObjectName(QString::fromUtf8("pushButton_aceptar_Cciudades"));

        verticalLayout->addWidget(pushButton_aceptar_Cciudades);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 140, 451, 271));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_adyacencia = new QLabel(groupBox_2);
        label_adyacencia->setObjectName(QString::fromUtf8("label_adyacencia"));
        label_adyacencia->setMinimumSize(QSize(427, 127));

        verticalLayout_2->addWidget(label_adyacencia);

        Rent_Car->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Rent_Car);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 760, 22));
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
        groupBox->setTitle(QCoreApplication::translate("Rent_Car", "Inicio de ciudades", nullptr));
        label_ingCiudades->setText(QCoreApplication::translate("Rent_Car", "Ingrese la cantidad de ciudades (Max 15)", nullptr));
        pushButton_aceptar_Cciudades->setText(QCoreApplication::translate("Rent_Car", "Aceptar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Rent_Car", "LIsta de adyacencia", nullptr));
        label_adyacencia->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rent_Car: public Ui_Rent_Car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENT_CAR_H
