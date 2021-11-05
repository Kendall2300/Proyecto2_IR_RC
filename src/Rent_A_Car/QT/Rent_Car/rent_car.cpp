/**
 * @file rent_car.cpp
 * @authors Kendall Martinez Carvajal (kendallmc@estudiantec.cr) && Jose Umana Rivera
 * @brief Este codigo contiene la declaracion de los metodos, funciones necesarias para construir,
 * modificar y mostrar el proyecto de forma grafica
 *
 * @version 1.0
 *
 * @copyright Copyright (c) 2021
 */
#include "rent_car.h"
#include "ui_rent_car.h"
#include "QMessageBox"
#include "Grafo.h"
#include "iostream"
#include "QString"
/**
 * @brief Rent_Car::Rent_Car
 * @param parent
 */
Rent_Car::Rent_Car(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rent_Car)
{
    ui->setupUi(this);
}
/**
 * @brief Rent_Car::~Rent_Car
 */
Rent_Car::~Rent_Car()
{
    delete ui;
}

int Vertices=0;
Grafo GR;

/**
 * @brief Rent_Car::on_pushButton_aceptar_Cciudades_clicked EL metodo permite aceptar un texto y llevar
 * a cabo la creacion aleatoria del grafo para el proyecto, asi como mostrar la lista de adyacencia
 * correspondiente con el grafo generado
 */
void Rent_Car::on_pushButton_aceptar_Cciudades_clicked()
{  
    QString ingreso_ciudades=ui->lineEdit_ciudades->text();
    int Vertices=ingreso_ciudades.toInt();
        string ciudades[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
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

/**
 * @brief Rent_Car::on_pushButton_clicked Se encarga de mostrar los resultados del analisis realizado por el algoritmo de backtraking
 */
void Rent_Car::on_pushButton_clicked()
{
    QString ciudad_origen=ui->lineEdit_ciudad_origen->text();
    QString ciudad_destino=ui->lineEdit_ciudad_destino->text();
    string algoritmo_resultado=GR.PrimeroMejor(GR.GetVertice(ciudad_origen.toStdString()),GR.GetVertice(ciudad_destino.toStdString()));
    QString label_message=QString::fromStdString(algoritmo_resultado);
    ui->label_algoritmo_result->setText(label_message);

}

