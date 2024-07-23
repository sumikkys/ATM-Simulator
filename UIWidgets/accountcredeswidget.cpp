#include "headfile/accountcredeswidget.h"
#include "ui_accountcredeswidget.h"
#include <QRegularExpressionValidator>

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

    //限制密码输入框输入格式为6位纯数字
    auto passwordRegex = QRegularExpression("[0-9]{6}");
    QValidator* passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    ui->passwordLine->setValidator(passwordValidator);
    ui->confirmPwdLine->setValidator(passwordValidator);
    //限制卡号输入框输入格式为16位纯数字
    auto numberRegex = QRegularExpression("[0-9]{16}");
    QValidator* numberValidator = new QRegularExpressionValidator(numberRegex, this);
    ui->numberLine->setValidator(numberValidator);

}

AccountCreDesWidget::~AccountCreDesWidget()
{
    delete ui;
}

void AccountCreDesWidget::clearInformation(){
    ui->numberLine->clear();
    ui->confirmPwdLine->clear();
    ui->passwordLine->clear();
}

std::vector<QString> AccountCreDesWidget::getUserInput() const{
    std::vector<QString> userInput;
    userInput.push_back(ui->numberLine->text());
    userInput.push_back(ui->passwordLine->text());
    userInput.push_back(ui->confirmPwdLine->text());

    return userInput;
    }
