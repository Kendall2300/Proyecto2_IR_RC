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
    Grafo GR;
    GR.Inicializa();
    GR.InsertaVertice("A");
    GR.InsertaVertice("B");
    GR.InsertaVertice("C");
    GR.InsertaVertice("D");
    GR.InsertaVertice("E");
    GR.InsertaArista(GR.GetVertice("A"),GR.GetVertice("E"),3);
    GR.InsertaArista(GR.GetVertice("A"),GR.GetVertice("D"),1);
    GR.InsertaArista(GR.GetVertice("B"),GR.GetVertice("A"),1);
    GR.InsertaArista(GR.GetVertice("B"),GR.GetVertice("D"),2);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("A"),1);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("E"),1);
    GR.InsertaArista(GR.GetVertice("D"),GR.GetVertice("C"),2);
    GR.InsertaArista(GR.GetVertice("E"),GR.GetVertice("D"),1);
    //GR.RecorridoProfundidad(GR.GetVertice("B"));
    //GR.PrimeroProfundidad(GR.GetVertice("B"),GR.GetVertice("A"));
    //GR.ListaAdyacencia();
    //cout<<GR.Tamano();
    //GR.EliminarVertice(GR.GetVertice("B"));

    return 0;
}
