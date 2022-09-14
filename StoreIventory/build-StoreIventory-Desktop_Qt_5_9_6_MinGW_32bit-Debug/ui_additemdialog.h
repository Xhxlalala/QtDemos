/********************************************************************************
** Form generated from reading UI file 'additemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMDIALOG_H
#define UI_ADDITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddItemDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtProductName;
    QSpinBox *sbQuantity;
    QLabel *lblImage;
    QPushButton *btnConfirmAdd;
    QPushButton *btnLoadImage;

    void setupUi(QDialog *AddItemDialog)
    {
        if (AddItemDialog->objectName().isEmpty())
            AddItemDialog->setObjectName(QStringLiteral("AddItemDialog"));
        AddItemDialog->resize(490, 550);
        label = new QLabel(AddItemDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 101, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(AddItemDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 101, 21));
        label_2->setFont(font);
        label_3 = new QLabel(AddItemDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 180, 91, 21));
        label_3->setFont(font);
        txtProductName = new QLineEdit(AddItemDialog);
        txtProductName->setObjectName(QStringLiteral("txtProductName"));
        txtProductName->setGeometry(QRect(210, 30, 231, 31));
        txtProductName->setFont(font);
        sbQuantity = new QSpinBox(AddItemDialog);
        sbQuantity->setObjectName(QStringLiteral("sbQuantity"));
        sbQuantity->setGeometry(QRect(210, 100, 231, 31));
        sbQuantity->setFont(font);
        sbQuantity->setMinimum(1);
        sbQuantity->setMaximum(1000);
        lblImage = new QLabel(AddItemDialog);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setGeometry(QRect(210, 180, 250, 250));
        lblImage->setFrameShape(QFrame::Panel);
        btnConfirmAdd = new QPushButton(AddItemDialog);
        btnConfirmAdd->setObjectName(QStringLiteral("btnConfirmAdd"));
        btnConfirmAdd->setGeometry(QRect(200, 490, 121, 31));
        btnConfirmAdd->setFont(font);
        btnLoadImage = new QPushButton(AddItemDialog);
        btnLoadImage->setObjectName(QStringLiteral("btnLoadImage"));
        btnLoadImage->setGeometry(QRect(20, 220, 141, 31));
        btnLoadImage->setFont(font);

        retranslateUi(AddItemDialog);

        QMetaObject::connectSlotsByName(AddItemDialog);
    } // setupUi

    void retranslateUi(QDialog *AddItemDialog)
    {
        AddItemDialog->setWindowTitle(QApplication::translate("AddItemDialog", "Add Item", Q_NULLPTR));
        label->setText(QApplication::translate("AddItemDialog", "Product Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddItemDialog", "Quantity:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddItemDialog", "Item Image:", Q_NULLPTR));
        lblImage->setText(QString());
        btnConfirmAdd->setText(QApplication::translate("AddItemDialog", "Confirm Add", Q_NULLPTR));
        btnLoadImage->setText(QApplication::translate("AddItemDialog", "Load Item Image", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddItemDialog: public Ui_AddItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMDIALOG_H
