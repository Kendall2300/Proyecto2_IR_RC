#include "rent_car.h"
#include "ui_rent_car.h"
#include "QMessageBox"
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


void Rent_Car::on_pushButton_aceptar_Cciudades_clicked()
{
    QString ingreso_ciudades=ui->lineEdit_ciudades->text();
    int cantidad_ciudades=ingreso_ciudades.toInt();
    if(cantidad_ciudades<=15){
        QMessageBox::information(this,"Ciudades ingresadas","Se ingreso un total de ciudades igual a: "+ingreso_ciudades);
        hide();
        Lista_Adyacencia = new graph_view(this);
        Lista_Adyacencia->show();
    }else{
        QMessageBox::information(this,"Ciudades Ingresadas", "Se ingreso un numero incorrecto o superior a 15, intentelo de nuevo");
    }

}

