/**
 * @file main.cpp
 * @authors Kendall Martinez Carvajal (kendallmc@estudiantec.cr) && Jose Umana Rivera
 * @brief Este codigo contiene los metodos y funciones necesarias para ejecutar el codigo
 *
 * @version 1.0
 *
 * @copyright Copyright (c) 2021
 */
#include "iostream"
#include "stdlib.h"
#include "Grafo.h"

using namespace std;

int main (){
    int Vertices;
    string ciudades[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};

    Grafo GR;
    GR.Inicializa();

    cout<<"Ingrese la cantidad de vertices(max 15):";
    cin >> Vertices;

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

    GR.ListaAdyacencia();
    cout<<endl;
    string Origen, Destino;
    cout<<"Ingrese la ciudad de origen: ";
    cin >> Origen;
    cout<<"Ingrese la ciudad destino: ";
    cin >> Destino;
    cout<<endl;
    if (GR.GetVertice(Origen) == NULL || GR.GetVertice(Destino) == NULL)
    {
        cout<<"Ciudades no validas"<<endl;
    }
    else
    {
        GR.PrimeroMejor(GR.GetVertice(Origen),GR.GetVertice(Destino));
    }

    return 0;
}
