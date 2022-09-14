#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QString>

class Item
{
public:
    Item(QString name,int quantity,QString imageFilePath="none.png");

    QString getName() const;
    void setName(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

    QString getImageFilePath() const;
    void setImageFilePath(const QString &value);

private:
    QString name;
    int quantity;
    QString imageFilePath;
};

#endif // ITEM_H
