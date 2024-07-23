/**
 * @file accountcredeswidget.cpp
 * @brief 开卡/销户界面的实现
 */

#include "headfile/accountcredeswidget.h"
#include "ui_accountcredeswidget.h"
#include <QRegularExpressionValidator>


/**
 * @brief 构造函数，初始化开卡销户界面
 *
 * @param parent 父Widget指针
 *
 */
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
/**
 * @brief 析构函数
 */
AccountCreDesWidget::~AccountCreDesWidget()
{
    delete ui;
}

/**
 * @brief 清除用户已输入的信息，便于下次输入
 */
void AccountCreDesWidget::clearInformation(){
    ui->numberLine->clear();
    ui->confirmPwdLine->clear();
    ui->passwordLine->clear();
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 含有卡号、密码、确认密码的vector<QString>容器
 */
std::vector<QString> AccountCreDesWidget::getUserInput() const{
    std::vector<QString> userInput;
    userInput.push_back(ui->numberLine->text());
    userInput.push_back(ui->passwordLine->text());
    userInput.push_back(ui->confirmPwdLine->text());

    return userInput;
    }
