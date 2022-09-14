/********************************************************************************
** Form generated from reading UI file 'updateitemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEITEMDIALOG_H
#define UI_UPDATEITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_UpdateItemDialog
{
public:
    QLabel *lblItemName;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *sbQuantity;
    QLabel *lblImage;
    QPushButton *btnLoadItemImage;
    QPushButton *btnConfirmEdit;

    void setupUi(QDialog *UpdateItemDialog)
    {
        if (UpdateItemDialog->objectName().isEmpty())
            UpdateItemDialog->setObjectName(QStringLiteral("UpdateItemDialog"));
        UpdateItemDialog->resize(486, 521);
        lblItemName = new QLabel(UpdateItemDialog);
        lblItemName->setObjectName(QStringLiteral("lblItemName"));
        lblItemName->setGeometry(QRect(210, 20, 121, 20));
        QFont font;
        font.setPointSize(12);
        lblItemName->setFont(font);
        label = new QLabel(UpdateItemDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 111, 31));
        label->setFont(font);
        label_2 = new QLabel(UpdateItemDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 131, 31));
        label_2->setFont(font);
        sbQuantity = new QSpinBox(UpdateItemDialog);
        sbQuantity->setObjectName(QStringLiteral("sbQuantity"));
        sbQuantity->setGeometry(QRect(190, 70, 221, 31));
        sbQuantity->setFont(font);
        sbQuantity->setMinimum(1);
        sbQuantity->setMaximum(1000);
        lblImage = new QLabel(UpdateItemDialog);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setGeometry(QRect(190, 140, 250, 250));
        lblImage->setFrameShape(QFrame::Panel);
        btnLoadItemImage = new QPushButton(UpdateItemDialog);
        btnLoadItemImage->setObjectName(QStringLiteral("btnLoadItemImage"));
        btnLoadItemImage->setGeometry(QRect(24, 170, 141, 31));
        btnLoadItemImage->setFont(font);
        btnConfirmEdit = new QPushButton(UpdateItemDialog);
        btnConfirmEdit->setObjectName(QStringLiteral("btnConfirmEdit"));
        btnConfirmEdit->setGeometry(QRect(190, 470, 111, 31));
        btnConfirmEdit->setFont(font);

        retranslateUi(UpdateItemDialog);

        QMetaObject::connectSlotsByName(UpdateItemDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateItemDialog)
    {
        UpdateItemDialog->setWindowTitle(QApplication::translate("UpdateItemDialog", "Dialog", Q_NULLPTR));
        lblItemName->setText(QApplication::translate("UpdateItemDialog", "Name of Item", Q_NULLPTR));
        label->setText(QApplication::translate("UpdateItemDialog", "Quantity:", Q_NULLPTR));
        label_2->setText(QApplication::translate("UpdateItemDialog", "Item Image:", Q_NULLPTR));
        lblImage->setText(QString());
        btnLoadItemImage->setText(QApplication::translate("UpdateItemDialog", "Load Item Image", Q_NULLPTR));
        btnConfirmEdit->setText(QApplication::translate("UpdateItemDialog", "Confirm Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdateItemDialog: public Ui_UpdateItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEITEMDIALOG_H
