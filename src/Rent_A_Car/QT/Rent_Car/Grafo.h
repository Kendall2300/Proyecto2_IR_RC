/**
 * @file Grafo.h
 * @authors Kendall Martinez Carvajal (kendallmc@estudiantec.cr) && Jose Umana Rivera
 * @brief ESte codigo contiene la definicion de las clases con sus atributos y metodos para manejar el Grafo
 *
 * @version 1.01
 *
 * @copyright Copyright (c) 2021
 */
#ifndef GRAFO_H
#define GRAFO_H
#include "iostream"
#include "stdlib.h"
#include "queue"
#include "list"
#include "stack"
#include <QString>
using namespace std;

class Arista;

class Vertice{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;
};

class Arista{
    Arista *sig;
    Vertice *ady;
    int peso;
    friend class Grafo;
};

class Grafo {
    Vertice *h;
public:
    void Inicializa();
    bool Vacio();
    int Tamano();
    Vertice *GetVertice (string nombre);
    void InsertaArista(Vertice *origen, Vertice *destino, int peso);
    void InsertaVertice(string nombre);
    string ListaAdyacencia();
    void EliminarArista(Vertice *origen, Vertice *destino);
    void Anular();
    void EliminarVertice(Vertice *vert);
    void RecorridoProfundidad(Vertice *origen);
    void PrimeroProfundidad(Vertice *origen, Vertice *destino);
    void PrimeroMejor(Vertice *origen, Vertice *destino);
    string lavel;
};
#endif // GRAFO_H
