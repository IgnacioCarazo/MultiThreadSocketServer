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
    /**
      Constructor
    */
        explicit Server(QObject *parent = 0);
    /**
      Inicia el servidor
    */
        void StartServer();

    signals:


    public slots:

    protected:
        /**
          Instancia un thread que se le asigna al cliente. Por cada cliente que se conecta se instancia un thread distinto
        */
        void incomingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
