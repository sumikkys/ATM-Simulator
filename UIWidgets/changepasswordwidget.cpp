#include "changepasswordwidget.h"
#include "ui_changepasswordwidget.h"
#include <QRegularExpressionValidator>

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

ChangePasswordWidget::~ChangePasswordWidget()
{
    delete ui;
}

void ChangePasswordWidget::clearInformation(){
    ui->oldPassword->clear();
    ui->newPassword->clear();
    ui->confirmPassword->clear();

}

std::vector<QString> ChangePasswordWidget::getUserInput() const{
    std::vector<QString> pwds;
    pwds.push_back(ui->oldPassword->text());
    pwds.push_back(ui->newPassword->text());
    pwds.push_back(ui->confirmPassword->text());

    return pwds;
}
