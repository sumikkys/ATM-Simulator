#include "depositwidget.h"
#include "ui_depositwidget.h"
#include <QRegularExpressionValidator>
DepositWidget::DepositWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositWidget)
{
    ui->setupUi(this);

    // 按钮点击使广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&DepositWidget::backButtonClicked);
    connect(ui->depositButton,&QPushButton::clicked,this,&DepositWidget::depositButtonClicked);

    //限制单次存款金额与格式
    auto amountRegex = QRegularExpression("[0-9]{1,7}\\.[0-9]{1,2}");
    QValidator* numberValidator = new QRegularExpressionValidator(amountRegex, this);
    ui->amountLine->setValidator(numberValidator);

}

DepositWidget::~DepositWidget()
{
    delete ui;
}

void DepositWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

QString DepositWidget::getDepositAmount(){
    return ui->amountLine->text();
}
