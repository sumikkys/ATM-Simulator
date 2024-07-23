/**
 * @file transferwidget.cpp
 * @brief 转账界面的实现
 */



#include "headfile/transferwidget.h"
#include "ui_transferwidget.h"
#include <QRegularExpressionValidator>

/**
 * @brief 构造函数，初始化转账界面
 *
 * @param parent 父Widget指针
 *
 */
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

/**
 * @brief 析构函数
 */
TransferWidget::~TransferWidget()
{
    delete ui;
}

/**
 * @brief 更新显示当前帐户余额
 */
void TransferWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

/**
 * @brief 清除用户已输入的信息，便于下次输入
 */
void TransferWidget::clearInformation(){
    ui->amountLine->clear();
    ui->targetCard->clear();
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的转账金额的QString
 */
QString TransferWidget::getTransferAmount() const{
    return ui->amountLine->text();
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的转账卡号的QString
 */
QString TransferWidget::getTargetCard() const{
    return ui->targetCard->text();
}

