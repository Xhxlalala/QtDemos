#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    qDeleteAll(m_list);
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    //Add them all up!
    double total = 0;
    foreach(Equation *e, m_list)
    {
        bool ok;
        double value = e->getSum().toDouble(&ok);
        if(!ok) continue;
        total = total + value;
    }

    QMessageBox::information(this,"Total","Total is: " + QString::number(total));
    //accept();
}

void Dialog::clear()
{
    qDeleteAll(m_list);
    m_list.clear();
    update();
}

void Dialog::add()
{
    updateAction(Equation::Action::ADD);
}

void Dialog::subtract()
{
    updateAction(Equation::Action::SUBTRACT);
}

void Dialog::multiply()
{
    updateAction(Equation::Action::MULTIPLY);
}

void Dialog::divide()
{
    updateAction(Equation::Action::DIVIDE);
}

void Dialog::number()
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    if(!btn) return;

    bool ok;
    double value = btn->text().toDouble(&ok);
    Q_UNUSED(value)

    if(!ok)
    {
        QMessageBox::critical(this,"Error","Not a number!");
        return;
    }

    updateValue(btn->text());

}

void Dialog::update()
{
    if (ui->listWidget->count() != m_list.count())
    {
        ui->listWidget->clear();
        foreach (Equation *e, m_list)
        {
            ui->listWidget->addItem(e->toString());
        }
        ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    }
    else
    {
        ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
        ui->listWidget->item(ui->listWidget->count() - 1)->setText(m_list.last()->toString());
    }
}

void Dialog::addEquation()
{
    m_list.append(new Equation(this));
    update();
}

void Dialog::init()
{
    int row = 0;
    int col = 2;
    for (int i = 9; i >= 0; i--)
    {
        QPushButton *btn = new QPushButton(QString::number(i), this);
        connect(btn,&QPushButton::clicked,this,&Dialog::number);

        ui->gridLayout->addWidget(btn, row, col);
        col--;
        if (col < 0)
        {
            row++;
            col = 2;
            if (row == 3) col = 0;
        }
    }

    QPushButton *btnAdd = new QPushButton("+", this);
    QPushButton *btnSubtract = new QPushButton("-", this);
    QPushButton *btnMultiply = new QPushButton("*", this);
    QPushButton *btnDivide = new QPushButton("/", this);
    QPushButton *btnClear = new QPushButton("Clear", this);
    QPushButton *btnRow = new QPushButton("Add Equation", this);

    connect(btnAdd,&QPushButton::clicked,this,&Dialog::add);
    connect(btnSubtract,&QPushButton::clicked,this,&Dialog::subtract);
    connect(btnMultiply,&QPushButton::clicked,this,&Dialog::multiply);
    connect(btnDivide,&QPushButton::clicked,this,&Dialog::divide);
    connect(btnClear,&QPushButton::clicked,this,&Dialog::clear);
    connect(btnRow,&QPushButton::clicked,this,&Dialog::addEquation);

    ui->gridLayout->addWidget(btnAdd,0,3);
    ui->gridLayout->addWidget(btnSubtract,1,3);
    ui->gridLayout->addWidget(btnMultiply,2,3);
    ui->gridLayout->addWidget(btnDivide,3,3);

    ui->buttonBox->addButton(btnClear,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnRow,QDialogButtonBox::ButtonRole::ActionRole);
}

Equation *Dialog::getLast()
{
    if(m_list.count() == 0) m_list.append(new Equation(this));
    return m_list.last();
}

void Dialog::updateValue(QString data)
{
    Equation *equation = getLast();
    if(!equation) return;

    QString value;
    if(equation->getAction() == Equation::Action::NONE)
    {
        value = equation->getValue1();
        value.append(data);
        equation->setValue1(value);
    }
    else
    {
        value = equation->getValue2();
        value.append(data);
        equation->setValue2(value);
    }

    equation->calculate();
    update();
}

void Dialog::updateAction(Equation::Action value)
{
    Equation *equation = getLast();
    if(!equation) return;

    equation->setAction(value);
    equation->calculate();
    update();
}
