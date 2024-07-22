#include "changepasswordwidget.h"
#include "ui_changepasswordwidget.h"

ChangePasswordWidget::ChangePasswordWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangePasswordWidget)
{
    ui->setupUi(this);

    // 按钮点击时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&ChangePasswordWidget::backButtonClicked);
    connect(ui->changePWDBtn,&QPushButton::clicked,this,&ChangePasswordWidget::changePWDBtnClicked);

}

ChangePasswordWidget::~ChangePasswordWidget()
{
    delete ui;
}

std::vector<QString> ChangePasswordWidget::getUserInput(){
    std::vector<QString> pwds;
    pwds.push_back(ui->oldPassword->text());
    pwds.push_back(ui->newPassword->text());
    pwds.push_back(ui->confirmPassword->text());

    return pwds;
}
