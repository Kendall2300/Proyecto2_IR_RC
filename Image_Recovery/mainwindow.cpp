#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, tr("Chose"), "", tr("Images(*.png *.jpg *.jpeg *.gif)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool vallid = image.load(filename);
        if (vallid)        {
            image = image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
            ui->label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            // Error
        }
       }
}


