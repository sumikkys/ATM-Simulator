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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WithdrawWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *balanceLabel;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QComboBox *withdrawAmtBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *withdrawButton;
    QPushButton *backButton;

    void setupUi(QWidget *WithdrawWidget)
    {
        if (WithdrawWidget->objectName().isEmpty())
            WithdrawWidget->setObjectName("WithdrawWidget");
        WithdrawWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(WithdrawWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(WithdrawWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(WithdrawWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        balanceLabel = new QLabel(WithdrawWidget);
        balanceLabel->setObjectName("balanceLabel");

        horizontalLayout_2->addWidget(balanceLabel);

        label_4 = new QLabel(WithdrawWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_5 = new QLabel(WithdrawWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        withdrawAmtBox = new QComboBox(WithdrawWidget);
        withdrawAmtBox->setObjectName("withdrawAmtBox");

        horizontalLayout_3->addWidget(withdrawAmtBox);

        label_6 = new QLabel(WithdrawWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(3, 4);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 10, 20, 30);
        withdrawButton = new QPushButton(WithdrawWidget);
        withdrawButton->setObjectName("withdrawButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(withdrawButton->sizePolicy().hasHeightForWidth());
        withdrawButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(withdrawButton);

        backButton = new QPushButton(WithdrawWidget);
        backButton->setObjectName("backButton");
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(backButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WithdrawWidget);

        QMetaObject::connectSlotsByName(WithdrawWidget);
    } // setupUi

    void retranslateUi(QWidget *WithdrawWidget)
    {
        WithdrawWidget->setWindowTitle(QCoreApplication::translate("WithdrawWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("WithdrawWidget", "\345\217\226\346\254\276\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("WithdrawWidget", "\350\264\246\346\210\267\344\275\231\351\242\235\357\274\232 ", nullptr));
        balanceLabel->setText(QCoreApplication::translate("WithdrawWidget", "------", nullptr));
        label_4->setText(QCoreApplication::translate("WithdrawWidget", "               \345\205\203", nullptr));
        label_5->setText(QCoreApplication::translate("WithdrawWidget", "\345\217\226\346\254\276\351\207\221\351\242\235\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("WithdrawWidget", "\345\205\203", nullptr));
        withdrawButton->setText(QCoreApplication::translate("WithdrawWidget", "\345\217\226\346\254\276", nullptr));
        backButton->setText(QCoreApplication::translate("WithdrawWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawWidget: public Ui_WithdrawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWWIDGET_H
