/********************************************************************************
** Form generated from reading UI file 'graph_view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_VIEW_H
#define UI_GRAPH_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_graph_view
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_listad_adyacencia;

    void setupUi(QDialog *graph_view)
    {
        if (graph_view->objectName().isEmpty())
            graph_view->setObjectName(QString::fromUtf8("graph_view"));
        graph_view->resize(400, 300);
        groupBox = new QGroupBox(graph_view);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 381, 281));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_listad_adyacencia = new QLabel(groupBox);
        label_listad_adyacencia->setObjectName(QString::fromUtf8("label_listad_adyacencia"));

        verticalLayout->addWidget(label_listad_adyacencia);


        retranslateUi(graph_view);

        QMetaObject::connectSlotsByName(graph_view);
    } // setupUi

    void retranslateUi(QDialog *graph_view)
    {
        graph_view->setWindowTitle(QCoreApplication::translate("graph_view", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("graph_view", "Lista adyacencia", nullptr));
        label_listad_adyacencia->setText(QCoreApplication::translate("graph_view", "Aqui_va_la_adyacencia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_view: public Ui_graph_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_VIEW_H
