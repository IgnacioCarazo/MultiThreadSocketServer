#include "thread.h"

Thread::Thread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;

}

void Thread::run(){
    // empieza el thread
    qDebug() <<"Iniciando thread";
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Se ha conectado un cliente";

    exec();
}

void Thread::readyRead(){
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << "Informacion recibida: " << Data;
    socket->write(Data);
}

void Thread::disconnected(){
    qDebug() << socketDescriptor << "Un cliente se ha desconectado";
    socket->deleteLater();
    exit(0);
}
