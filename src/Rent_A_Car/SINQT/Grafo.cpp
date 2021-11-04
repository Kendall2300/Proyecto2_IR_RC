/**
 * @file Grafo.cpp
 * @authors Kendall Martinez Carvajal (kendallmc@estudiantec.cr) && Jose Umana Rivera
 * @brief Este codigo contiene la declaracion de los metodos, funciones y los algoritmos necesarios para construir,
 * modificar y analizar el grafo
 *
 * @version 1.0
 *
 * @copyright Copyright (c) 2021
 */
#include "Grafo.h"
int tanqueF = 50;

/**
 * @brief Este metodo se encarga de inicializar el grafo
 */
void Grafo::Inicializa()
{
    h = NULL;
}

/**
 * @brief Este metodo se encarga de revisar si el grafo se encuentra vacio
 * @return A boolean
 */
bool Grafo::Vacio()
{
    if(h == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Este metodo te devuelve la cantidad de Vertices que posee el grafo
 * @return An int que es el numero de vertices
 */
int Grafo::Tamano()
{
    int cont = 0;
    Vertice *aux;
    aux = h;
    while(aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}
/**
 * @brief Este metodo te recupera el nombre de un vertice
 * @param nombre A string que contiene el nombre de un vertice del grafo
 * @return A Null
 */
Vertice *Grafo::GetVertice(string nombre)
{
    Vertice *aux;
    aux = h;
    while(aux  != NULL)
    {
        if(aux->nombre == nombre)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

/**
 * @brief ESte metodo se encarga de insertar los vertices en el grafo
 * @param nombre A string que corresponde al nombre del vertice
 */
void Grafo::InsertaVertice(string nombre)
{
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    nuevo->ady = NULL;

    if(Vacio())
    {
        h = nuevo;
    }
    else
    {
        Vertice *aux;
        aux = h;
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

/**
 * @brief Este metodo se encarga de insertar las aristas entre los vertices
 * @param origen A Vertice una referencia al vertice del origen
 * @param destino A Vertice una referencia al vertice del destino
 * @param peso A int que corresponde al valor de la arista
 */
void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso)
{
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->sig = NULL;
    nueva->ady = NULL;

    Arista *aux;

    aux = origen->ady;

    if(aux == NULL)
    {
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else
    {
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
    }
}

/**
 * @brief Este metodo te imprime la lista de adyacencia correspodiente al grafo
 */
void Grafo::ListaAdyacencia()
{
    Vertice *VertAux;
    Arista *ArisAux;

    VertAux = h;
    while(VertAux != NULL)
    {
        cout<<VertAux->nombre<<"->";
        ArisAux = VertAux->ady;
        while(ArisAux != NULL)
        {
            cout<<ArisAux->ady->nombre<<":";
            cout<<ArisAux->peso<<"->";
            ArisAux = ArisAux->sig;
        }
        VertAux = VertAux->sig;
        cout<<endl;
    }
}

/**
 * @brief Este metodo se encarga de destruir el grafo
 */
void Grafo::Anular()
{
    Vertice *aux;

    while(h != NULL)
    {
        aux = h;
        h = h->sig;
        delete(aux);
    }
}

/**
 * @brief Este metodo se encarga de eliminar las aristas
 * @param origen Vertice que se corresponde al origen
 * @param destino Vertice que corresponde al destino
 */
void Grafo::EliminarArista(Vertice *origen, Vertice *destino)
{
    int band = 0;
    Arista *actual, *anterior;
    actual = origen->ady;

    if(actual == NULL)
    {
        cout<<"El vertice orgien no tiene aristas"<<endl;
    }
    else if(actual->ady == destino)
    {
        origen->ady = actual->sig;
        delete(actual);
    }
    else
    {
        while(actual != NULL)
        {
            if(actual->ady == destino)
            {
                band = 1;
                anterior->sig = actual->sig;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->sig;
        }
        if(band == 0)
        {
            cout<<"Esos dos vertices no estan conectados"<<endl;
        }
    }
}

/**
 * @brief ESte metodo se encarga de eliminar un vertice especificado
 * @param vert Un Vertice que corresponde al que se desea eliminar
 */
void Grafo::EliminarVertice(Vertice *vert)
{
    Vertice *actual, *anterior;
    Arista *aux;

    actual = h;
    while(actual != NULL)
    {
        aux = actual->ady;
        while(aux != NULL)
        {
            if(aux->ady == vert)
            {
                EliminarArista(actual, aux->ady);
                break;
            }
            aux = aux->sig;
        }
        actual = actual->sig;
    }
    actual = h;
    if(h == vert)
    {
        h = h->sig;
        delete(actual);
    }
    else
    {
        while(actual != vert)
        {
            anterior = actual;
            actual = actual->sig;
        }
        anterior->sig = actual->sig;
        delete(actual);
    }
}

/**
 * @brief ESte metodo encuentra todos los vertices que tengan conexion entre si
 * @param origen Un Vertice que corresponde al vertice del que partes a invertigar
 */
void Grafo::RecorridoProfundidad(Vertice *origen)
{
    int band, band2;
    Vertice *actual;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;

    pila.push(origen);

    while(!pila.empty())
    {
        band = 0;
        actual = pila.top();
        pila.pop();

        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if(*i == actual)
            {
                band = 1;
            }
        }
        if(band == 0)
        {
            cout<<actual->nombre<<", ";
            lista.push_back(actual);

            Arista *aux;
            aux = actual->ady;

            while(aux != NULL)
            {
                band2 = 0;
                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    if(*i == aux->ady)
                    {
                        band2 = 1;
                    }
                }
                if(band2 == 0)
                {
                    pila.push(aux->ady);
                }
                aux = aux->sig;
            }
        }
    }
}

/**
 * @brief Este metodo se encarga de Recorrer el grafo y de paso calcular la ruta que sera de menor costo de forma voraz
 * @param origen Un vertice que sera el punto de partida
 * @param destino Un vertice que corresponde al de llegada
 */
void Grafo::PrimeroProfundidad(Vertice *origen, Vertice *destino) {
    Vertice *VerticeActual, *DestinoActual;
    typedef pair<Vertice*, Vertice*> ParVertices;
    int band,band2,band3=0, tanque=origen->ady->peso;
    Arista *aux;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    stack <ParVertices> PilaPar;
    list<Vertice*>::iterator i;

    pila.push(origen);

    while (!pila.empty()){
        band=0;
        VerticeActual=pila.top();
        pila.pop();

        for(i=lista.begin();i!=lista.end();i++){
            if(VerticeActual==*i){
                band=1;
            }
        }
        if (band==0){
            if (VerticeActual==destino){
                band3=1;
                DestinoActual=destino;
                while(!PilaPar.empty()){
                    cout<<DestinoActual->nombre<<"<-";
                    while (!PilaPar.empty()&& PilaPar.top().second != DestinoActual){
                        PilaPar.pop();

                    }
                    if(!PilaPar.empty()){
                        DestinoActual=PilaPar.top().first;
                    }
                }
                cout<<"   El tamanio de tu tanque debe ser: "<<tanque<<endl;
                if (tanque <= tanqueF){
                    tanqueF = tanque;
                }
                //cout<<tanqueF<<endl;
                break;
            }
            lista.push_back(VerticeActual);
            aux=VerticeActual->ady;
            if(aux!=NULL){
                if (aux->peso!=NULL){
                    if (tanque <= aux->peso){
                        tanque=aux->peso;
                    }
                }
            }
            while(aux!=NULL){
                band2=0;
                for(i=lista.begin(); i!=lista.end(); i++){
                    if(aux->ady==*i){
                        band2=1;
                    }
                }
                if(band2==0){
                    pila.push(aux->ady);
                    PilaPar.push(ParVertices(VerticeActual,aux->ady));
                }
                aux=aux->sig;
            }
        }
    }
    if(band3==0){
        cout <<"No hay ruta entre los vertices"<< endl;
    }
}

bool Comparacion(pair <Vertice*, int> a, pair<Vertice*, int> b)
{
    return a.second < b.second;
}

/**
 * @brief Este metodo se encarga de recorrer el grafo y de paso calcular la ruta que sera de menor costo usando bactraking
 * @param origen Un vertice que sera el punto de partida
 * @param destino Un vertice que sera el punto de llegada
 */
void Grafo::PrimeroMejor(Vertice *origen, Vertice *destino)
{
    int CostoActual, band, band2, CostoAnterior;
    Vertice *VerticeActual, *DestinoActual;
    Arista *aux;
    typedef pair<Vertice*, int> VerticeCosto;
    typedef pair<Vertice*, Vertice*> VerticeVertice;
    list<VerticeCosto> ListaCostos;
    list<VerticeCosto> ListaOrdenada;
    stack<VerticeVertice> pila;
    list<VerticeCosto>::iterator i, j;

    ListaCostos.push_back(VerticeCosto(origen, 0));
    ListaOrdenada.push_back(VerticeCosto(origen,0));

    while(!ListaOrdenada.empty())
    {
        VerticeActual = ListaOrdenada.front().first;
        CostoActual = ListaOrdenada.front().second;
        ListaOrdenada.pop_front();

        if(VerticeActual == destino)
        {
            cout<<"Costo: "<<CostoActual<<endl;
            band2 = 1;
            DestinoActual = destino;

            while(!pila.empty())
            {
                cout<<DestinoActual->nombre<<"<-";

                while(!pila.empty() && pila.top().second != DestinoActual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    DestinoActual = pila.top().first;
                }
            }
            break;
        }

        aux = VerticeActual->ady;
        while(aux != NULL)
        {
            band = 0;
            CostoAnterior = CostoActual;
            if (CostoActual < aux->peso)
            {
                CostoActual = aux->peso;
            }
            //CostoActual = CostoActual + aux->peso;
            for(i=ListaCostos.begin(); i!=ListaCostos.end(); i++)
            {
                if(aux->ady == i->first)
                {
                    band = 1;
                    if(CostoActual < i->second)
                    {
                        (*i).second = CostoActual;

                        for(j=ListaOrdenada.begin(); j!=ListaOrdenada.end(); j++)
                        {
                            if(j->first == aux->ady)
                            {
                                (*j).second = CostoActual;
                            }
                        }
                        ListaOrdenada.sort(Comparacion);
                        pila.push(VerticeVertice(VerticeActual, aux->ady));
                        CostoActual = CostoAnterior;
                        //CostoActual = CostoActual - aux->peso;
                    }
                }
            }
            if(band == 0)
            {
                ListaCostos.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.sort(Comparacion);
                pila.push(VerticeVertice(VerticeActual, aux->ady));
                CostoActual = CostoAnterior;
                //CostoActual = CostoActual - aux->peso;
            }

            aux = aux->sig;
        }
    }
    if(band2 == 0)
    {
        cout<<"No hay una ruta entre esos dos vertices"<<endl;
    }
}