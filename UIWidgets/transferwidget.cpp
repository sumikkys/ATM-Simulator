#include "headfile/transferwidget.h"
#include "ui_transferwidget.h"
#include <QRegularExpressionValidator>

TransferWidget::TransferWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TransferWidget)
{
    ui->setupUi(this);

    // 按钮点击时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&TransferWidget::backButtonClicked);
    connect(ui->transferButton,&QPushButton::clicked,this,&TransferWidget::transferBtnClicked);

    //限制单次转账金额与格式
    auto amountRegex = QRegularExpression("[0-9]{1,7}\\.[0-9]{1,2}");
    QValidator* amountValidator = new QRegularExpressionValidator(amountRegex, this);
    ui->amountLine->setValidator(amountValidator);
    //限制卡号输入框输入格式为16位纯数字
    auto numberRegex = QRegularExpression("[0-9]{16}");
    QValidator* numberValidator = new QRegularExpressionValidator(numberRegex, this);
    ui->targetCard->setValidator(numberValidator);
}

TransferWidget::~TransferWidget()
{
    delete ui;
}

// 更新显示当前帐户余额
void TransferWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

QString TransferWidget::getTransferAmount() const{
    return ui->amountLine->text();
}

QString TransferWidget::getTargetCard() const{
    return ui->targetCard->text();
}

