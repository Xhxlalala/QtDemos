#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include "item.h"
#include "additemdialog.h"
#include "updateitemdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void handleMenuItemNew();
    void removeSelectedProduct();
    void handleItemClick(QListWidgetItem* item);
    void handleMenuItemEdit();
    void handleSaveItems();
    void handleLoadItems();

private:
    Ui::MainWindow *ui;
    QVector<Item*> productList;
};

#endif // MAINWINDOW_H
