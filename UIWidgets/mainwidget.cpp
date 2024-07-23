/**
 * @file mainwidget.cpp
 * @brief 主界面的实现
 */



#include "headfile/mainwidget.h"
#include "ui_mainwidget.h"


/**
 * @brief 构造函数，初始化主界面
 *
 * @param parent 父Widget指针
 *
 */
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 广播点击按钮信号
    connect(ui->checkBalanceButton, &QPushButton::clicked, this, &MainWidget::checkBalanceButtonClicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &MainWidget::quitButtonClicked);
    connect(ui->toDepositButton, &QPushButton::clicked, this, &MainWidget::toDepositButtonClicked);
    connect(ui->toWithdrawButton, &QPushButton::clicked, this, &MainWidget::toWithdrawButtonClicked);
    connect(ui->toChangePasswordButton, &QPushButton::clicked, this, &MainWidget::toChangePWDButoonClicked);
    connect(ui->toTransferButton, &QPushButton::clicked, this , &MainWidget::toTransferButtonClicked);
}

/**
 * @brief 析构函数
 */
MainWidget::~MainWidget()
{
    delete ui;
}

/**
 * @brief 显示当前帐户余额
 */
void MainWidget::showBalance(unsigned int m_balance){
    // 通过格式化将unsigned int的balance显示为小数且小数部分始终保持两位
    ui->balanceLabel->setText(QString::number(m_balance/100)+"."+QString("%1").arg(m_balance%100, 2, 10, QChar('0'))+ " 元");
}

/**
 * @brief 在用户登陆后隐藏金额，保护用户隐私
 */
void MainWidget::hideBalance(){
    ui->balanceLabel->setText("---");
}
