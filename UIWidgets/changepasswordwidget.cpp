/**
 * @file changepasswordwidget.cpp
 * @brief 修改密码界面的实现
 */


#include "headfile/changepasswordwidget.h"
#include "ui_changepasswordwidget.h"
#include <QRegularExpressionValidator>

/**
 * @brief 构造函数，初始化修改密码界面
 *
 * @param parent 父Widget指针
 *
 */

ChangePasswordWidget::ChangePasswordWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangePasswordWidget)
{
    ui->setupUi(this);

    // 按钮点击时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&ChangePasswordWidget::backButtonClicked);
    connect(ui->changePWDBtn,&QPushButton::clicked,this,&ChangePasswordWidget::changePWDBtnClicked);

    //限制密码输入框输入格式为6位纯数字
    auto passwordRegex = QRegularExpression("[0-9]{6}");
    QValidator* passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    ui->oldPassword->setValidator(passwordValidator);
    ui->newPassword->setValidator(passwordValidator);
    ui->confirmPassword->setValidator(passwordValidator);


}

/**
 * @brief 析构函数
 */
ChangePasswordWidget::~ChangePasswordWidget()
{
    delete ui;
}

/**
 * @brief 清除用户已输入的信息，便于下次输入
 */
void ChangePasswordWidget::clearInformation(){
    ui->oldPassword->clear();
    ui->newPassword->clear();
    ui->confirmPassword->clear();

}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 含有旧密码、新密码、确认新密码的vector<QString>容器
 */
std::vector<QString> ChangePasswordWidget::getUserInput() const{
    std::vector<QString> pwds;
    pwds.push_back(ui->oldPassword->text());
    pwds.push_back(ui->newPassword->text());
    pwds.push_back(ui->confirmPassword->text());

    return pwds;
}
