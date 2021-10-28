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

    cout<<"Ingrese la cantidad de vertices(max 15):"<<endl;
    cin >> Vertices;

    for (int c = 0; c < Vertices; c++)
    {
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

    //int random = rand()%3;
    //cout<<random<<endl;
    /*Grafo GR=Grafo();
    GR.InsertaVertice("A");
    GR.InsertaVertice("B");
    GR.InsertaVertice("C");
    GR.InsertaVertice("D");
    GR.InsertaVertice("E");
    GR.InsertaArista(GR.GetVertice("A"),GR.GetVertice("E"),3);
    GR.InsertaArista(GR.GetVertice("A"),GR.GetVertice("D"),1);
    GR.InsertaArista(GR.GetVertice("B"),GR.GetVertice("A"),2);
    GR.InsertaArista(GR.GetVertice("B"),GR.GetVertice("D"),2);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("A"),3);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("E"),1);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("C"),2);
    GR.InsertaArista(GR.GetVertice("E"),GR.GetVertice("D"),1);*/
    //GR.RecorridoProfundidad(GR.GetVertice("B"));
    GR.ListaAdyacencia();
    GR.PrimeroProfundidad(GR.GetVertice("B"),GR.GetVertice("A"));
    //cout<<GR.Tamano();
    //GR.EliminarVertice(GR.GetVertice("B"));

    return 0;
}
