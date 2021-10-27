#include "Grafo.h"

void Grafo::Inicializa()
{
    h = NULL;
}

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
            cout<<ArisAux->ady->nombre<<"->";
            ArisAux = ArisAux->sig;
        }
        VertAux = VertAux->sig;
        cout<<endl;
    }
}

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

void Grafo::PrimeroProfundidad(Vertice *origen, Vertice *destino) {
    Vertice *VerticeActual, *DestinoActual;
    typedef pair<Vertice*, Vertice*> ParVertices;
    int band,band2,band3=0;
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
                break;
            }
            lista.push_back(VerticeActual);
            aux=VerticeActual->ady;
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
        cout <<"Nop hay ruta entre los vertices"<< endl;
    }
}