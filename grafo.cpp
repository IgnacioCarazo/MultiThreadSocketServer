#include "grafo.h"

Grafo::Grafo()
{
    head = NULL;
}


bool Grafo::isVacio(){
    if (head == NULL){
        return true;
    } else {
        return false;
    }
}

int Grafo::getSize(){
    Vertice *aux;
    aux = head;
    int cont = 0;
    while (aux != NULL){
        aux = aux->siguiente;
        cont += 1;
    }
    return cont;
}

Vertice *Grafo::getVertice(string nombre){
    Vertice *aux;
    aux = head;
    while (aux != NULL){
        if (aux->nombre == nombre){
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

string Grafo::getVerticeFromID(int num){
    Vertice *aux;
    aux = head;
    while (aux != NULL){
        if (aux->ID == num){
            return aux->nombre;
        }
        aux = aux->siguiente;
    }
    return "No existe vertice ";
}

void Grafo::insertarVertice(string nombre){
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->siguiente = NULL;
    nuevo->adyacente = NULL;
    nuevo->ID = contador;
    contador++;
    if (isVacio()){
        head = nuevo;
    } else {
        Vertice *aux;
        aux = head;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}


void Grafo::insertarArista(Vertice *origen, Vertice *destino, int peso){
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->siguiente = NULL;
    nueva->adyacente = NULL;
    nueva->IDdestino = destino->ID;
    Arista *aux;
    aux = origen->adyacente;

    if (aux == NULL){
        origen->adyacente = nueva;
        nueva->adyacente = destino;
    } else {
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
         aux->siguiente = nueva;
         nueva->adyacente = destino;
    }
}




void Grafo::dijsktra(int size){
    Vertice *Vaux;
    Arista *Aaux;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    Vaux = head;
    int grafo[size][size];
    while (Vaux != NULL){
        grafo[0][0] = 0;
        int auxArray[size];
        while (cont2 <= size) {
            auxArray[cont2] = cont2;
            cont2++;
        }

        Aaux = Vaux->adyacente;
        while (Aaux != NULL) {
            grafo[cont1][Aaux->IDdestino] = Aaux->peso;
            auxArray[Aaux->IDdestino] = -1;

            Aaux = Aaux->siguiente;
        }
        for ( int i = 0; i < size; i++ ){
            if (!(auxArray[i] < 0)){
                grafo[cont1][i] = 0;
            }
        }
        for ( int i = 0; i < size; i++ ){
            auxArray[i] = 0;
        }
        cont1 ++;
        Vaux = Vaux->siguiente;

    }
    for (int i=0; i<sizeof grafo/sizeof grafo[0]; ++i)
      {
        for (int j=0; j<sizeof grafo[0] /sizeof grafo[0][0]; ++j)
          printf("%03d ", grafo[i][j]);
        cout << '\n';
      }
    while (cont3 < contador){
        int dist[size];
        bool Dset[size];
        for(int i=0;i<size;i++)
        {
            dist[i]=INT_MAX;
            Dset[i]=false;
        }
        dist[cont3]=0;
        for(int c=0;c<size;c++)
        {
            int u=minimumDist(dist, Dset, size);
            Dset[u]=true;
            for(int v=0;v<size;v++)

            {
                if(!Dset[v] && grafo[u][v] && dist[u]!=INT_MAX && dist[u]+grafo[u][v]<dist[v])
                dist[v]=dist[u]+grafo[u][v];
            }
        }
        cout<< ""<<endl;
        cout<< "Vertice" <<"\t\tDistancia mas corta desde: " << getVerticeFromID(cont3)<<endl;
        cout<< ""<<endl;
        for(int i=0;i<size;i++)
        {

            string c=getVerticeFromID(i);
            cout<<c<<"\t\t"<<dist[i]<<endl;
        }

        cont3 ++;
    }
}


int Grafo::minimumDist(int *dist, bool *Dset, int size){
    int min=INT_MAX,index;
        for(int v=0;v<size;v++)
        {
            if(Dset[v]==false && dist[v]<=min)
            {
                min=dist[v];
                index=v;
            }
        }
        return index;
}


void Grafo::eliminarGrafo(){
    Vertice *aux;

    while (head != NULL) {
        aux = head;
        head = head->siguiente;
        delete(aux);
    }
}

void Grafo::eliminarArista(Vertice *origen, Vertice *destino){
    int flag = 0;
    Arista *actual, *anterior;
    actual = origen->adyacente;

    if (actual == NULL) {
        cout << "El vertice no tiene aristas"<< endl;
    } else if (actual->adyacente == destino){
        origen->adyacente = actual->siguiente;
        delete(actual);
    } else {
        while (actual != NULL){
            if (actual->adyacente == destino){
                flag = 1;
                anterior->siguiente = actual->siguiente;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        if (flag == 0){
            cout << "Estos vertices no estan conectados" << endl;
        }
    }
}

void Grafo::eliminarVertice(Vertice *vertice){
    Vertice *actual, *anterior;
    Arista *aux;

    actual = head;
    while (actual != NULL){
        aux = actual->adyacente;
        while (aux != NULL) {
            if (aux->adyacente == vertice){
                eliminarArista(actual, aux->adyacente);
                break;
            }
            aux = aux->siguiente;
        }
        actual = actual->siguiente;
    }

    actual = head;
    if (head == vertice){
        head = head->siguiente;
        delete(actual);
    } else {
        while (actual != vertice) {
            anterior = actual;
            actual = actual->siguiente;
        }
        anterior->siguiente = actual->siguiente;
        delete(actual);
    }
}
