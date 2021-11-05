//
// Created by gabriel on 3/11/21.
//

#ifndef PROVE_MAINWINDOW_H
#define PROVE_MAINWINDOW_H

#endif //PROVE_MAINWINDOW_H
#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class PlusMinus : public QWidget {

Q_OBJECT

public:

    PlusMinus(QWidget *parent = nullptr);

private slots:
    void OnPlus();
    void genetic();

private:
    QLabel *lbl;
};