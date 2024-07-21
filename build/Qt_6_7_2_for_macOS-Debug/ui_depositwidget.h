/********************************************************************************
** Form generated from reading UI file 'depositwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWIDGET_H
#define UI_DEPOSITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWidget
{
public:

    void setupUi(QWidget *DepositWidget)
    {
        if (DepositWidget->objectName().isEmpty())
            DepositWidget->setObjectName("DepositWidget");
        DepositWidget->resize(400, 300);

        retranslateUi(DepositWidget);

        QMetaObject::connectSlotsByName(DepositWidget);
    } // setupUi

    void retranslateUi(QWidget *DepositWidget)
    {
        DepositWidget->setWindowTitle(QCoreApplication::translate("DepositWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWidget: public Ui_DepositWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWIDGET_H
