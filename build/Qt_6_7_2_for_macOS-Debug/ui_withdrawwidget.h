/********************************************************************************
** Form generated from reading UI file 'withdrawwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWWIDGET_H
#define UI_WITHDRAWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WithdrawWidget
{
public:

    void setupUi(QWidget *WithdrawWidget)
    {
        if (WithdrawWidget->objectName().isEmpty())
            WithdrawWidget->setObjectName("WithdrawWidget");
        WithdrawWidget->resize(400, 300);

        retranslateUi(WithdrawWidget);

        QMetaObject::connectSlotsByName(WithdrawWidget);
    } // setupUi

    void retranslateUi(QWidget *WithdrawWidget)
    {
        WithdrawWidget->setWindowTitle(QCoreApplication::translate("WithdrawWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawWidget: public Ui_WithdrawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWWIDGET_H
