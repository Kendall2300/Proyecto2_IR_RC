#include "rent_car.h"
#include "ui_rent_car.h"
#include "stdlib.h"
#include "string.h"

Rent_Car::Rent_Car(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rent_Car)
{
    ui->setupUi(this);
}

Rent_Car::~Rent_Car()
{
    delete ui;
}


void Rent_Car::on_pushButton_clicked()
{

}

