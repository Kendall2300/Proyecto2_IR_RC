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
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_ciudad_origen;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_ciudad_destino;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_algoritmo_result;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_algoritmo_view;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Rent_Car)
    {
        if (Rent_Car->objectName().isEmpty())
            Rent_Car->setObjectName(QString::fromUtf8("Rent_Car"));
        Rent_Car->resize(945, 458);
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

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 0, 271, 131));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_ciudad_origen = new QLineEdit(groupBox_3);
        lineEdit_ciudad_origen->setObjectName(QString::fromUtf8("lineEdit_ciudad_origen"));

        horizontalLayout_3->addWidget(lineEdit_ciudad_origen);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_ciudad_destino = new QLineEdit(groupBox_3);
        lineEdit_ciudad_destino->setObjectName(QString::fromUtf8("lineEdit_ciudad_destino"));

        horizontalLayout_2->addWidget(lineEdit_ciudad_destino);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(540, 140, 351, 101));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_algoritmo_result = new QLabel(groupBox_4);
        label_algoritmo_result->setObjectName(QString::fromUtf8("label_algoritmo_result"));

        verticalLayout_4->addWidget(label_algoritmo_result);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(540, 250, 351, 161));
        horizontalLayout_6 = new QHBoxLayout(groupBox_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_algoritmo_view = new QLabel(groupBox_5);
        label_algoritmo_view->setObjectName(QString::fromUtf8("label_algoritmo_view"));

        horizontalLayout_6->addWidget(label_algoritmo_view);

        Rent_Car->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Rent_Car);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 945, 22));
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
        groupBox_3->setTitle(QCoreApplication::translate("Rent_Car", "Elige las ciudades", nullptr));
        label->setText(QCoreApplication::translate("Rent_Car", "Ciudad partida:", nullptr));
        label_2->setText(QCoreApplication::translate("Rent_Car", "Ciudad destino:", nullptr));
        pushButton->setText(QCoreApplication::translate("Rent_Car", "Buscar", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Rent_Car", "Mejor camino", nullptr));
        label_algoritmo_result->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("Rent_Car", "Preview del algoritmo", nullptr));
        label_algoritmo_view->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rent_Car: public Ui_Rent_Car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENT_CAR_H
