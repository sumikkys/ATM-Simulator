#include "withdrawwidget.h"
#include "ui_withdrawwidget.h"

WithdrawWidget::WithdrawWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawWidget)
{
    ui->setupUi(this);

    // 按钮点击使广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&WithdrawWidget::backButtonClicked);
    connect(ui->withdrawButton,&QPushButton::clicked,this,&WithdrawWidget::withdrawButtonClicked);

    // 为ComboBox添加限定的取款金额
    for (int i = 100; i <= 5000; i += 100) {
        ui->withdrawAmtBox->addItem(QString::number(i));
    }
}

WithdrawWidget::~WithdrawWidget()
{
    delete ui;
}

void WithdrawWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

QString WithdrawWidget::getWithdrawAmount(){
    return ui->withdrawAmtBox->currentText();
}
