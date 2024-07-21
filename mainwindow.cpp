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
        QMessageBox::warning(this, "登陆失败", "用户名或密码不能为空！");
    }else if(atm.login(cardNumber,password)){
        QMessageBox::information(this, "登陆成功", "您已成功登陆！");
        ui->stackedWidget->setCurrentWidget(mainWidget);
    }else{
        QMessageBox::warning(this, "登陆失败", "用户名或密码错误！");
    }
}

void MainWindow::handleDeposit(){}

void MainWindow::handleWithdraw(){}

void MainWindow::handleChangePassword(){}


