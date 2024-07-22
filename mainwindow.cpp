#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"
#include "atmsystem.h"
#include "loginwidget.h"
#include "mainwidget.h"
#include "depositwidget.h"
#include "withdrawwidget.h"
#include "changepasswordwidget.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow),loginWidget(new LoginWidget(this)),
    mainWidget(new MainWidget(this)), depositWidget(new DepositWidget(this))
    ,withdrawWidget(new WithdrawWidget(this)), changePasswordWidget(new ChangePasswordWidget(this)), atm()
{
    ui->setupUi(this);

    // 将各个Widget添加到stackedWidget
    ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->addWidget(mainWidget);
    ui->stackedWidget->addWidget(depositWidget);
    ui->stackedWidget->addWidget(withdrawWidget);
    ui->stackedWidget->addWidget(changePasswordWidget);
    ui->stackedWidget->setCurrentWidget(loginWidget);




    // 连接从子Widget得到的信号与槽函数
    connect(loginWidget,&LoginWidget::loginButtonClicked,this,&MainWindow::handleLogin);
    // lambda表达式处理查询余额信号
    connect(mainWidget,&MainWidget::checkBalanceButtonClicked,this,[this](){
        mainWidget->showBalance(atm.checkBalance());
    });
    // lambda表达式处理退出登录信号
    connect(mainWidget,&MainWidget::quitButtonClicked,this,[this](){
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();
    });
    // lambda表达式处理前往存款界面信号
    connect(mainWidget,&MainWidget::toDepositButtonClicked,this,[this](){
        ui->stackedWidget->setCurrentWidget(depositWidget);
        depositWidget->updateBalance(atm.checkBalance());

    });
    // lambda表达式处理返回主界面信号
    connect(depositWidget,&DepositWidget::backButtonClicked,this,[this](){
        ui->stackedWidget->setCurrentWidget(mainWidget);
        mainWidget->showBalance(atm.checkBalance());
    });
    // 连接存款信号与存款槽函数
    connect(depositWidget,&DepositWidget::depositButtonClicked,this,&MainWindow::handleDeposit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 处理登陆的槽函数
void MainWindow::handleLogin(){
    QString cardNumber = loginWidget->getCardNumber();
    QString password = loginWidget->getPassword();
    if(cardNumber.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this, "登陆失败", "卡号或密码不能为空！");
    }else if(atm.login(cardNumber,password)){
        QMessageBox::information(this, "登陆成功", "您已成功登陆！");
        ui->stackedWidget->setCurrentWidget(mainWidget);
    }else{
        QMessageBox::warning(this, "登陆失败", "卡号或密码错误！");
        loginWidget->clearInformation(); // 清除登陆信息便于用户重新输入卡号和密码
    }
}

void MainWindow::handleDeposit(){
    QString line = depositWidget->getDepositAmount();
    if(line.isEmpty()){
        QMessageBox::warning(this, "存款失败", "存款金额不能为空！");
    }else if(line.contains(".")){
        unsigned int intPart = line.split(".").first().toUInt();
        unsigned int floatPart = line.split(".").last().toUInt();
        if(line.split(".").last().size()<2) floatPart *= 10;
        unsigned int finalAmount = intPart*100+floatPart;
        atm.deposit(finalAmount);
        QMessageBox::information(this, "存款成功", "您已存款"+line+" 元。");
        depositWidget->updateBalance(atm.checkBalance());

    }else{
        unsigned int finalAmount = line.toUInt()*100;
        atm.deposit(finalAmount);
        QMessageBox::information(this, "存款成功", "您已存款"+line+" 元。");
        depositWidget->updateBalance(atm.checkBalance());
    }

}

void MainWindow::handleWithdraw(){}

void MainWindow::handleChangePassword(){}


