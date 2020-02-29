#ifndef THREAD_H
#define THREAD_H


#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

/**
  La clase Thread permite que al servidor se conecten diferentes clientes al mismo tiempo y "atenderlos" al mismo tiempo
*/

class Thread : public QThread
{
    Q_OBJECT
    public:
        /**
          Constructor
        */
        explicit Thread(int ID, QObject *parent = 0);
        void run();

    signals:
        void error(QTcpSocket::SocketError socketerror);

    public slots:
        void readyRead();
        void disconnected();

    private:
        QTcpSocket *socket;
        int socketDescriptor;
};

#endif // THREAD_H
