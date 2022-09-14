#include "equation.h"

Equation::Equation(QObject *parent) : QObject(parent)
{
    m_action = Action::RESET;
    calculate();
}

QString Equation::getSum() const
{
    return m_sum;
}

void Equation::setSum(const QString &sum)
{
    m_sum = sum;
}

QString Equation::getValue1() const
{
    return m_value1;
}

void Equation::setValue1(const QString &value1)
{
    m_value1 = value1;
}

QString Equation::getValue2() const
{
    return m_value2;
}

void Equation::setValue2(const QString &value2)
{
    m_value2 = value2;
}

Equation::Action Equation::getAction() const
{
    return m_action;
}

void Equation::setAction(const Equation::Action &action)
{
    m_action = action;
}

void Equation::calculate()
{
    double dval1 = getValue(m_value1);
    double dval2 = getValue(m_value2);
    double dsum = 0;

    switch (m_action) {
    case Action::NONE:
        break;
    case Action::RESET:
        m_sum.clear();
        m_value1.clear();
        m_value2.clear();
        m_action = Action::NONE;
        break;
    case Action::ADD:
        dsum = dval1 + dval2;
        break;
    case Action::SUBTRACT:
        dsum = dval1 - dval2;
        break;
    case Action::MULTIPLY:
        dsum = dval1 * dval2;
        break;
    case Action::DIVIDE:
        dsum = dval1 / dval2;
        break;
    }

    m_value1 = QString::number(dval1);
    m_value2 = QString::number(dval2);
    m_sum = QString::number(dsum);

    qInfo() << "v1: " << m_value1 << " v2: " << m_value2 << " sum: " << m_sum;
}

QString Equation::toString()
{
    QString display;
    display.append(m_value1);
    display.append(" ");

    switch (m_action) {
    case Action::NONE:
        display.append("?");
        break;
    case Action::RESET:
        display.append("?");
        break;
    case Action::ADD:
        display.append("+");
        break;
    case Action::SUBTRACT:
        display.append("-");
        break;
    case Action::MULTIPLY:
        display.append("*");
        break;
    case Action::DIVIDE:
        display.append("/");
        break;
    }
    display.append(" ");
    display.append(m_value2);
    display.append(" = ");
    display.append(m_sum);
    return display;
}

double Equation::getValue(QString data)
{
    bool ok;
    double value = data.toDouble(&ok);
    if(!ok) value = 0;
    return value;
}
