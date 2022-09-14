#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include "tcpserver.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnStart_clicked();
    void on_btnEnd_clicked();
    void next();
    void back();
    void changed();

private:
    Ui::Dialog *ui;
    QPushButton *btnBack;
    QPushButton *btnNext;
    TcpServer server;

    void init();
    void enableButtons();
};

#endif // DIALOG_H
