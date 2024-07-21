/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *balanceLabel;
    QPushButton *checkBalanceButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *depositButton;
    QPushButton *withdrawButton;
    QPushButton *changePasswordButton;
    QPushButton *quitButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, -1, -1, -1);
        label = new QLabel(MainWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(MainWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(12, -1, 12, -1);
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        balanceLabel = new QLabel(MainWidget);
        balanceLabel->setObjectName("balanceLabel");

        horizontalLayout_2->addWidget(balanceLabel);

        checkBalanceButton = new QPushButton(MainWidget);
        checkBalanceButton->setObjectName("checkBalanceButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBalanceButton->sizePolicy().hasHeightForWidth());
        checkBalanceButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(checkBalanceButton);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 7);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(12, 10, 12, 15);
        depositButton = new QPushButton(MainWidget);
        depositButton->setObjectName("depositButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(depositButton->sizePolicy().hasHeightForWidth());
        depositButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(depositButton);

        withdrawButton = new QPushButton(MainWidget);
        withdrawButton->setObjectName("withdrawButton");
        sizePolicy1.setHeightForWidth(withdrawButton->sizePolicy().hasHeightForWidth());
        withdrawButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(withdrawButton);

        changePasswordButton = new QPushButton(MainWidget);
        changePasswordButton->setObjectName("changePasswordButton");
        sizePolicy1.setHeightForWidth(changePasswordButton->sizePolicy().hasHeightForWidth());
        changePasswordButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(changePasswordButton);

        quitButton = new QPushButton(MainWidget);
        quitButton->setObjectName("quitButton");
        sizePolicy1.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(quitButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "\345\260\212\346\225\254\347\232\204\347\224\250\346\210\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "\346\254\242\350\277\216\346\235\245\345\210\260\346\240\241\345\233\255\351\223\266\350\241\214\357\274\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\344\273\212\345\244\251\346\203\263\345\201\232\347\202\271\344\273\200\344\271\210\357\274\237", nullptr));
        label_4->setText(QCoreApplication::translate("MainWidget", "\350\264\246\346\210\267\344\275\231\351\242\235\357\274\232", nullptr));
        balanceLabel->setText(QCoreApplication::translate("MainWidget", "--- \345\205\203", nullptr));
        checkBalanceButton->setText(QCoreApplication::translate("MainWidget", "\346\237\245\350\257\242\344\275\231\351\242\235", nullptr));
        depositButton->setText(QCoreApplication::translate("MainWidget", "   \345\255\230\346\254\276   ", nullptr));
        withdrawButton->setText(QCoreApplication::translate("MainWidget", "   \345\217\226\346\254\276   ", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("MainWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
