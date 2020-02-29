#ifndef SERVER_H
#define SERVER_H


#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include <thread.h>
/**
  La clase Server crea un servidor que permite utilizar logica ante solicitudes de un cliente
*/
class Server : public QTcpServer
{
    Q_OBJECT
    public:
        explicit Server(QObject *parent = 0);
        void StartServer();

    signals:


    public slots:

    protected:
        void incomingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
