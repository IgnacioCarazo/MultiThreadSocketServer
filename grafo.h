#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <QDebug>
#include<climits>


using namespace std;

static int contador;


class Arista;

/**
  Clase Vertice
  La clase vertice es basicamente los nodos del grafo o por si decirlo "destinos" u "origenes"
*/
class Vertice{
    Vertice *siguiente;
    Arista *adyacente;
    string nombre;
    int ID;
    friend class Grafo;
};

/**
  Clase Arista
  La clase arista o conocida tambien como "arcos" indica las rutas a otros vertices y el peso que tiene dicha ruta.
*/
class Arista{
    Arista *siguiente;
    Vertice *adyacente;
    int peso;
    int IDdestino;
    friend class Grafo;
};

class Grafo
{
    Vertice *head;

public:
    /**
      Constructor.
    */
    Grafo();
    /**
      Verifica si el grafo esta vacio.
    */
    bool isVacio();
    /**
      Obtiene la cantidad de vertices que tiene el grafo.
    */
    int getSize();
    /**
      Retorna un objeto de tipo Vertice por medio de su nombre como parametro.
    */
    Vertice *getVertice(string nombre);
    /**
      Similar a getVertice(), pero funciona a partir de un ID (numero entero) que es unico para cada vertice.
    */
    string getVerticeFromID(int num);
    /**
      Inserta una Arista a un grafo donde se indica en sus parametros el origen (Vertice) de la arista y su destino (Vertice) asi como su peso (numero entero).
    */
    void insertarArista(Vertice *origen, Vertice *destino, int peso);
    /**
      Inserta un vertice al cual se le indica su nombre por medio del parametro "nombre".
    */
    void insertarVertice(string nombre);
    /**
      Esta funcion aplica el algoritmo Dijsktra, el cual obtiene la ruta mas rapida de un vertice a todos los demas.
    */
    void dijsktra(int size);
    /**
      Elimin una arista o arco.
    */
    void eliminarArista(Vertice *origen, Vertice *destino);
    /**
      Elimina el grafo.
    */
    void eliminarGrafo();
    /**
      Elimina un vertice del grafo
    */
    void eliminarVertice(Vertice *vertice);
    /**
     Esta funcion es una funcion secundaria de dijkstra() y obtiene la minima distancia para el algoritmo Dijsktra
    */
    int minimumDist(int dist[], bool Dset[], int size);

};

#endif // GRAFO_H
