#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QLabel>

#include "mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    PlusMinus window;

    window.resize(400, 250);
    window.setWindowTitle("Image Recovery");
    window.show();

    return app.exec();
}