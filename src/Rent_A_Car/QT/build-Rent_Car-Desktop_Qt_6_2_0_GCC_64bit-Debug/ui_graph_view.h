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

QT_BEGIN_NAMESPACE

class Ui_graph_view
{
public:

    void setupUi(QDialog *graph_view)
    {
        if (graph_view->objectName().isEmpty())
            graph_view->setObjectName(QString::fromUtf8("graph_view"));
        graph_view->resize(400, 300);

        retranslateUi(graph_view);

        QMetaObject::connectSlotsByName(graph_view);
    } // setupUi

    void retranslateUi(QDialog *graph_view)
    {
        graph_view->setWindowTitle(QCoreApplication::translate("graph_view", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_view: public Ui_graph_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_VIEW_H
