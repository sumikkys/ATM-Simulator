#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QMessageBox>
#include <QIntValidator>

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //点击登陆按钮时广播信号
    connect(ui->loginButton,&QPushButton::clicked,this,&LoginWidget::loginButtonClicked);

    //限制卡号输入框输入格式为16位纯数字
    auto numberRegex = QRegularExpression("[0-9]{16}");
    QValidator* numberValidator = new QRegularExpressionValidator(numberRegex, this);
    ui->numberLine->setValidator(numberValidator);
    //限制密码输入框输入格式为6位纯数字
    auto passwordRegex = QRegularExpression("[0-9]{6}");
    QValidator* passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    ui->passwordLine->setValidator(passwordValidator);

}

LoginWidget::~LoginWidget()
{
    delete ui;
}

QString LoginWidget::getCardNumber(){
    QString cardNumber = ui->numberLine->text();
    return cardNumber;
}

QString LoginWidget::getPassword(){
    QString password = ui->passwordLine->text();
    return password;
}

// 用户退出登录后清除登陆信息
void LoginWidget::clearInformation(){
    ui->numberLine->clear();
    ui->passwordLine->clear();
}
