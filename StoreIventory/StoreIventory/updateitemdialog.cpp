#include "updateitemdialog.h"
#include "ui_updateitemdialog.h"

UpdateItemDialog::UpdateItemDialog(Item* currentItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateItemDialog)
{
    ui->setupUi(this);

    this->currentItem = currentItem;

    if(currentItem != nullptr)
    {
        ui->lblItemName->setText(currentItem->getName());
        QPixmap pixmap(currentItem->getImageFilePath());
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);
        ui->sbQuantity->setValue(currentItem->getQuantity());
        imageFilePath = currentItem->getImageFilePath();
    }

    connect(ui->btnConfirmEdit,&QPushButton::clicked,this,&UpdateItemDialog::confirmUpdate);
    connect(ui->btnLoadItemImage,&QPushButton::clicked,this,&UpdateItemDialog::loadItemImage);
}

UpdateItemDialog::~UpdateItemDialog()
{
    delete ui;
}

void UpdateItemDialog::confirmUpdate()
{
    int quantity = ui->sbQuantity->value();
    if(quantity >= 1)
    {
        currentItem->setQuantity(quantity);
        currentItem->setImageFilePath(imageFilePath);
        this->close();
    }
    else
    {
        QMessageBox mb;
        mb.setText("quantity must be at least 1.");
        mb.exec();
    }
}

void UpdateItemDialog::loadItemImage()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,"Open Images","./","Image Files (*.png *.jpg)");
    if(filename != "")
    {
        int lastSplash = filename.lastIndexOf("/");
        QString shortName = filename.right(filename.size() - lastSplash - 1);
        QFile::copy(filename, "./images/" + shortName);
        QPixmap pixmap("./images/" + shortName);
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);
        imageFilePath = "./images/" + shortName;
    }
}
