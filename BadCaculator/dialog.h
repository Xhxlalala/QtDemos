#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "equation.h"


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

    void on_buttonBox_accepted();
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void number();
    void update();
    void addEquation();

private:
    Ui::Dialog *ui;

    QList<Equation*> m_list;
    void init();
    Equation *getLast();
    void updateValue(QString data);
    void updateAction(Equation::Action value);
};

#endif // DIALOG_H
