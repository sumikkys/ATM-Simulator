#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    connect(ui->checkBalanceButton,&QPushButton::clicked,this,&MainWidget::checkBalanceButtonClicked);
    connect(ui->quitButton,&QPushButton::clicked,this,&MainWidget::quitButtonClicked);
    connect(ui->toDepositButton,&QPushButton::clicked,this,&MainWidget::toDepositButtonClicked);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::showBalance(unsigned int m_balance){
    // 通过格式化将unsigned int的balance显示为小数且小数部分始终保持两位
    ui->balanceLabel->setText(QString::number(m_balance/100)+"."+QString("%1").arg(m_balance%100, 2, 10, QChar('0'))+ " 元");
}
