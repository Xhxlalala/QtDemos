#include "additemdialog.h"
#include "ui_additemdialog.h"
#include <QDir>

AddItemDialog::AddItemDialog(Item*& newItem, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
    this->newItem = &newItem;
    imageFilePath = "none.png";

    connect(ui->btnConfirmAdd,&QPushButton::clicked,this,&AddItemDialog::confirmAdd);
    connect(ui->btnLoadImage,&QPushButton::clicked,this,&AddItemDialog::loadItemImage);

    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        // create it
        pathDir.mkdir("./images");
    }
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

void AddItemDialog::confirmAdd()
{
    QString productName = ui->txtProductName->text();
    int quantity = ui->sbQuantity->value();
    if(productName.trimmed() != "" && quantity >= 1)
    {
        *newItem = new Item(productName,quantity,imageFilePath);
        this->close();
    }
    else
    {
        QMessageBox::critical(this,"Warning","You must have a valid name and a quantity of at least 1");
    }
}

void AddItemDialog::loadItemImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"Open Image","./","Image Files (*.png *.jpg)");
    if(fileName != "")
    {
        int lastSplash = fileName.lastIndexOf("/");
        QString shortName = fileName.right(fileName.size() - lastSplash - 1);
        QFile::copy(fileName, "./images/" + shortName);
        QPixmap pixmap("./images/" + shortName);
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);
        imageFilePath = "./images/" + shortName;
    }
}
