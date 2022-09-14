#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->menuNewProduct,&QAction::triggered,this,&MainWindow::handleMenuItemNew);
    connect(ui->menuEditSelectedProduct,&QAction::triggered,this,&MainWindow::handleMenuItemEdit);
    connect(ui->menuSaveProducts,&QAction::triggered,this,&MainWindow::handleSaveItems);
    connect(ui->menuLoadProducts,&QAction::triggered,this,&MainWindow::handleLoadItems);
    connect(ui->btnRemove,&QPushButton::clicked,this,&MainWindow::removeSelectedProduct);
    connect(ui->lstProducts,&QListWidget::itemClicked,this,&MainWindow::handleItemClick);
}

MainWindow::~MainWindow()
{
    for(Item* product : productList)
    {
        delete product;
    }
    productList.clear();
    delete ui;
}

void MainWindow::handleMenuItemNew()
{
    Item* newItem = nullptr;
    AddItemDialog addItemDialog(newItem,nullptr);

    addItemDialog.setModal(true);
    addItemDialog.exec();

    if(newItem != nullptr)
    {
        productList.push_back(newItem);
        ui->lstProducts->addItem(newItem->getName());
    }
}

void MainWindow::removeSelectedProduct()
{
    int index = ui->lstProducts->currentRow();

    if (index >= 0)
    {
        Item* theItem = productList.at(index);
        delete theItem;
        productList.removeAt(index);

        delete ui->lstProducts->currentItem();
    }
    QPixmap pixmap("none.png");
    ui->lblImage->setPixmap(pixmap);
}

void MainWindow::handleItemClick(QListWidgetItem *item)
{
    int index = item->listWidget()->currentRow();

    if(index != -1)
    {
        Item* currentItem = productList.at(index);
        if(currentItem != nullptr)
        {
            ui->lblProductName->setText(currentItem->getName());
            ui->lblQuantity->setText(QString::number(currentItem->getQuantity()));

            QPixmap pixmap(currentItem->getImageFilePath());

            ui->lblImage->setPixmap(pixmap);
            ui->lblImage->setScaledContents(true);
        }
    }
}

void MainWindow::handleMenuItemEdit()
{
    int index = ui->lstProducts->currentRow();

    if(index != -1)
    {
        Item* currentItem = productList.at(index);
        if(currentItem != nullptr)
        {
            UpdateItemDialog updateItemDialog(currentItem,nullptr);
            updateItemDialog.exec();

            ui->lblProductName->setText(currentItem->getName());
            ui->lblQuantity->setText(QString::number(currentItem->getQuantity()));

            QPixmap pixmap(currentItem->getImageFilePath());
            ui->lblImage->setPixmap(pixmap);
            ui->lblImage->setScaledContents(true);
        }
    }
}

void MainWindow::handleSaveItems()
{
    QFile outputFile("products.txt");
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outputFile);

    for(Item* product : productList)
    {
        out << product->getName() << ",";
        out << product->getQuantity() << ",";
        out << product->getImageFilePath() << "\n";
    }

    out.flush();
    outputFile.close();
}

void MainWindow::handleLoadItems()
{
    QFile inputFile("products.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&inputFile);

    for(Item* temp : productList) delete temp;

    productList.clear();
    ui->lstProducts->clear();

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList info = line.split(",");

        ui->lstProducts->addItem(info.at(0));

        Item* product = new Item(info.at(0),info.at(1).toInt(),info.at(2));
        productList.push_back(product);
    }

    in.flush();
    inputFile.close();
}
