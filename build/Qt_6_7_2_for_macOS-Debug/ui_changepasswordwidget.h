/********************************************************************************
** Form generated from reading UI file 'changepasswordwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDWIDGET_H
#define UI_CHANGEPASSWORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordWidget
{
public:

    void setupUi(QWidget *ChangePasswordWidget)
    {
        if (ChangePasswordWidget->objectName().isEmpty())
            ChangePasswordWidget->setObjectName("ChangePasswordWidget");
        ChangePasswordWidget->resize(400, 300);

        retranslateUi(ChangePasswordWidget);

        QMetaObject::connectSlotsByName(ChangePasswordWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangePasswordWidget)
    {
        ChangePasswordWidget->setWindowTitle(QCoreApplication::translate("ChangePasswordWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordWidget: public Ui_ChangePasswordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDWIDGET_H
