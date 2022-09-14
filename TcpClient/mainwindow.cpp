#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_socket,&QTcpSocket::connected,this,&MainWindow::connected);
    connect(&m_socket,&QTcpSocket::disconnected,this,&MainWindow::disconnected);
    connect(&m_socket,&QTcpSocket::readyRead,this,&MainWindow::readyRead);
    connect(&m_socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&MainWindow::error);
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
    m_model.setStringList(m_list);
    ui->listView->setModel(&m_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{
    if(m_socket.isOpen()) m_socket.close();

    m_name = QInputDialog::getText(this,"Name","What is your name?",QLineEdit::EchoMode::Normal,m_name);

    bool ok;
    quint16 port = static_cast<quint16>(ui->txtPort->text().toInt(&ok));
    if(!ok)
    {
        QMessageBox::critical(this,"Error","Please enter a valid port number!");
        return;
    }

    m_socket.connectToHost(ui->txtServer->text(), port);
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);

    if(!m_socket.waitForConnected(3000))
    {
        on_btnDisconnect_clicked();
        QMessageBox::critical(this,"Error","Could not connect to server!");
        return;
    }
}

void MainWindow::on_btnDisconnect_clicked()
{
    m_socket.close();
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
}

void MainWindow::on_btnSend_clicked()
{
    if(!m_socket.isOpen()) return;

    QByteArray data;
    data.append(m_name);
    data.append(QString(" : "));
    data.append(ui->txtMessage->text());

    m_socket.write(data);
    ui->txtMessage->setText(QString());
}

void MainWindow::connected()
{
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(true);
    ui->btnSend->setEnabled(true);
}

void MainWindow::disconnected()
{
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(false);
    ui->btnSend->setEnabled(false);
}

void MainWindow::readyRead()
{
    QByteArray data = m_socket.readAll();
    QString message(data);
    m_list.append(message);
    m_model.setStringList(m_list);
    ui->listView->scrollToBottom();
}

void MainWindow::error(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    QMessageBox::critical(this,"Error",m_socket.errorString());
}
