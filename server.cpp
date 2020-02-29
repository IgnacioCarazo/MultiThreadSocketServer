#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{

}

void Server::StartServer(){
    if(!this->listen(QHostAddress::Any,5000)){
        qDebug() << "El servidor no se pudo iniciar";
    } else {
        qDebug() << "Esperando conexiones";

    }
}


void Server::incomingConnection(qintptr socketDescriptor){
    qDebug() << socketDescriptor << "Conectando...";
    Thread *thread = new Thread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();

}
