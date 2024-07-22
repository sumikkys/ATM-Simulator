#include "accountcredeswidget.h"
#include "ui_accountcredeswidget.h"

AccountCreDesWidget::AccountCreDesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountCreDesWidget)
{
    ui->setupUi(this);

    // 点击开卡按钮时广播信号
    connect(ui->createButton,&QPushButton::clicked,this,&AccountCreDesWidget::createButtonClicked);
    // 点击销户按钮时广播信号
    connect(ui->destoryButton,&QPushButton::clicked,this,&AccountCreDesWidget::destoryButtonClicked);
    // 点击返回按钮时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&AccountCreDesWidget::backButtonClicked);

}

AccountCreDesWidget::~AccountCreDesWidget()
{
    delete ui;
}

void AccountCreDesWidget::clearInformation(){
    ui->numberLine->clear();
    ui->passwordLine->clear();
}
