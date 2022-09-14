#include "item.h"

Item::Item(QString name, int quantity, QString imageFilePath)
{
    this->name = name;
    this->quantity = quantity;
    this->imageFilePath = imageFilePath;
}

QString Item::getName() const
{
    return name;
}

void Item::setName(const QString &value)
{
    name = value;
}

int Item::getQuantity() const
{
    return quantity;
}

void Item::setQuantity(int value)
{
    quantity = value;
}

QString Item::getImageFilePath() const
{
    return imageFilePath;
}

void Item::setImageFilePath(const QString &value)
{
    imageFilePath = value;
}
