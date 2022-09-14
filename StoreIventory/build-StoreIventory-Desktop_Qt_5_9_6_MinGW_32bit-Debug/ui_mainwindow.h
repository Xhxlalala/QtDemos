/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menuNewProduct;
    QAction *menuEditSelectedProduct;
    QAction *menuSaveProducts;
    QAction *menuLoadProducts;
    QAction *menuExit;
    QWidget *centralWidget;
    QListWidget *lstProducts;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblProductName;
    QLabel *lblQuantity;
    QLabel *lblImage;
    QPushButton *btnRemove;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 563);
        menuNewProduct = new QAction(MainWindow);
        menuNewProduct->setObjectName(QStringLiteral("menuNewProduct"));
        menuEditSelectedProduct = new QAction(MainWindow);
        menuEditSelectedProduct->setObjectName(QStringLiteral("menuEditSelectedProduct"));
        menuSaveProducts = new QAction(MainWindow);
        menuSaveProducts->setObjectName(QStringLiteral("menuSaveProducts"));
        menuLoadProducts = new QAction(MainWindow);
        menuLoadProducts->setObjectName(QStringLiteral("menuLoadProducts"));
        menuExit = new QAction(MainWindow);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lstProducts = new QListWidget(centralWidget);
        lstProducts->setObjectName(QStringLiteral("lstProducts"));
        lstProducts->setGeometry(QRect(10, 10, 281, 421));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 30, 151, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 80, 141, 21));
        label_2->setFont(font);
        lblProductName = new QLabel(centralWidget);
        lblProductName->setObjectName(QStringLiteral("lblProductName"));
        lblProductName->setGeometry(QRect(460, 30, 181, 31));
        lblProductName->setFont(font);
        lblProductName->setFrameShape(QFrame::Panel);
        lblQuantity = new QLabel(centralWidget);
        lblQuantity->setObjectName(QStringLiteral("lblQuantity"));
        lblQuantity->setGeometry(QRect(460, 80, 181, 31));
        lblQuantity->setFont(font);
        lblQuantity->setFrameShape(QFrame::Panel);
        lblImage = new QLabel(centralWidget);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setGeometry(QRect(390, 170, 250, 250));
        lblImage->setFont(font);
        lblImage->setFrameShape(QFrame::Panel);
        btnRemove = new QPushButton(centralWidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setGeometry(QRect(10, 460, 281, 41));
        btnRemove->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuNewProduct);
        menuFile->addAction(menuEditSelectedProduct);
        menuFile->addSeparator();
        menuFile->addAction(menuSaveProducts);
        menuFile->addAction(menuLoadProducts);
        menuFile->addSeparator();
        menuFile->addAction(menuExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Store Inventory Application", Q_NULLPTR));
        menuNewProduct->setText(QApplication::translate("MainWindow", "New Product", Q_NULLPTR));
        menuEditSelectedProduct->setText(QApplication::translate("MainWindow", "Edit Selected Product", Q_NULLPTR));
        menuSaveProducts->setText(QApplication::translate("MainWindow", "Save Products", Q_NULLPTR));
        menuLoadProducts->setText(QApplication::translate("MainWindow", "Load Products", Q_NULLPTR));
        menuExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Selected product:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Quantity:", Q_NULLPTR));
        lblProductName->setText(QString());
        lblQuantity->setText(QString());
        lblImage->setText(QString());
        btnRemove->setText(QApplication::translate("MainWindow", "Remove Selected Item", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
