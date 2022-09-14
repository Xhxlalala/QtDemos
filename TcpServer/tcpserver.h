#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

    int count();
    void close();

    QString message() const;
    void setMessage(const QString &message);

signals:
    void changed();

public slots:
    void disconnected();
    void readyRead();

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
    QString m_message;
    QList<QTcpSocket*> m_list;
};

#endif // TCPSERVER_H
