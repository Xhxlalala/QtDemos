#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{

}

int TcpServer::count()
{
    return m_list.count();
}

void TcpServer::close()
{
    foreach (QTcpSocket *socket, m_list) {
        socket->close();
    }
    qDeleteAll(m_list);
    m_list.clear();

    emit changed();

    QTcpServer::close();
}

void TcpServer::disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket) return;

    m_list.removeAll(socket);
    disconnect(socket,&QTcpSocket::disconnected,this,&TcpServer::disconnected);
    disconnect(socket,&QTcpSocket::readyRead,this,&TcpServer::readyRead);
    socket->deleteLater();

    emit changed();
}

void TcpServer::readyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket) return;

    QByteArray data = socket->readAll();
    foreach (QTcpSocket *socket, m_list)
    {
        socket->write(data);
    }
}

void TcpServer::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    if(!socket->waitForConnected(3000))
    {
        delete socket;
        return;
    }

    m_list.append(socket);
    connect(socket,&QTcpSocket::disconnected,this,&TcpServer::disconnected);
    connect(socket,&QTcpSocket::readyRead,this,&TcpServer::readyRead);

    emit changed();
    socket->write(m_message.toLatin1());
}

QString TcpServer::message() const
{
    return m_message;
}

void TcpServer::setMessage(const QString &message)
{
    m_message = message;
}
