#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "item.h"

namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(Item*& newItem, QWidget* parent = nullptr);
    ~AddItemDialog();

    void confirmAdd();
    void loadItemImage();
private:
    Ui::AddItemDialog *ui;
    Item** newItem;
    QString imageFilePath;
};

#endif // ADDITEMDIALOG_H
