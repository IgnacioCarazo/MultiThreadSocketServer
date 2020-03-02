#include <QCoreApplication>
#include <server.h>
#include <grafo.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Grafo *G =  new Grafo();
    G->insertarVertice("SanJose");
    G->insertarVertice("Heredia");
    G->insertarVertice("Alajuela");
    G->insertarVertice("Limon");
    G->insertarVertice("Puntarenas");
    G->insertarVertice("Cartago");
    G->insertarVertice("Guanacaste");
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Heredia"), 70);
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Alajuela"), 80);
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Limon"), 100);
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Puntarenas"), 30);
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Cartago"), 20);
    G->insertarArista(G->getVertice("SanJose"),G->getVertice("Guanacaste"), 60);
    G->insertarArista(G->getVertice("Heredia"),G->getVertice("Alajuela"), 20);
    G->insertarArista(G->getVertice("Alajuela"),G->getVertice("Heredia"), 10);
    G->insertarArista(G->getVertice("Limon"),G->getVertice("Cartago"), 10);
    G->insertarArista(G->getVertice("Limon"),G->getVertice("SanJose"), 150);
    G->insertarArista(G->getVertice("Puntarenas"),G->getVertice("SanJose"), 10);
    G->insertarArista(G->getVertice("Puntarenas"),G->getVertice("SanJose"), 10);
    G->insertarArista(G->getVertice("Cartago"),G->getVertice("Puntarenas"), 50);
    G->insertarArista(G->getVertice("Cartago"),G->getVertice("Limon"), 70);
    G->insertarArista(G->getVertice("Guanacaste"),G->getVertice("SanJose"), 40);
    G->insertarArista(G->getVertice("Guanacaste"),G->getVertice("Heredia"), 80);
    G->insertarArista(G->getVertice("Guanacaste"),G->getVertice("Alajuela"), 10);
    G->dijsktra(G->getSize());


    Server Server;
    Server.StartServer();
    return a.exec();

}
