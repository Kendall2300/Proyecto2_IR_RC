#include "rent_car.h"
#include "ui_rent_car.h"
#include "QMessageBox"
#include "Grafo.h"
#include "iostream"
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

int Vertices=0;
void Rent_Car::on_pushButton_aceptar_Cciudades_clicked()
{  
    QString ingreso_ciudades=ui->lineEdit_ciudades->text();
    int Vertices=ingreso_ciudades.toInt();
        string ciudades[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
        Grafo GR;
        GR.Inicializa();
        for (int c = 0; c < Vertices; c++)
        {
            if (Vertices > 15){
                cout<<"El numero de vertices brindado excede el maximo posible"<<endl;
                break;
            }
            GR.InsertaVertice(ciudades[c]);
        }


        srand((unsigned int)time(NULL));

        int a = 0;
        int i, j, cap;
        while(a < (Vertices*2)-2)
        {
            i = rand()%Vertices;
            j = rand()%Vertices;
            cap = (rand()%30)+1;

            if(i == j)
            {
                continue;
            }
            GR.InsertaArista(GR.GetVertice(ciudades[i]), GR.GetVertice(ciudades[j]), cap);
            a++;
        }
    if(Vertices<=15){
        QString lavel_message=QString::fromStdString(GR.ListaAdyacencia());
        QMessageBox::information(this,"Ciudades ingresadas","Se ingreso un total de ciudades igual a: "+ingreso_ciudades);
        ui->label_adyacencia->setText(lavel_message);
    }else if (Vertices>15){
        QMessageBox::information(this,"Ciudades Ingresadas", "Se ingreso un numero incorrecto o superior a 15, intentelo de nuevo");
    }

}



