/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *numberLine;
    QLineEdit *passwordLine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoginWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(LoginWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(37);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        label->setFont(font);
        label->setLineWidth(1);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label->setIndent(-1);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(100, -1, 100, -1);
        numberLine = new QLineEdit(LoginWidget);
        numberLine->setObjectName("numberLine");
        numberLine->setInputMethodHints(Qt::ImhNone);

        verticalLayout_2->addWidget(numberLine);

        passwordLine = new QLineEdit(LoginWidget);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordLine);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(120, 0, 120, 50);
        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginWidget", "ATM\350\207\252\345\212\250\346\237\234\345\221\230\346\234\272", nullptr));
        numberLine->setInputMask(QString());
        numberLine->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\351\223\266\350\241\214\345\215\241\345\217\267", nullptr));
        passwordLine->setInputMask(QString());
        passwordLine->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
