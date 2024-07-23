#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "atmsystem.h"
#include "loginwidget.h"
#include "mainwidget.h"
#include "depositwidget.h"
#include "withdrawwidget.h"
#include "changepasswordwidget.h"
#include "transferwidget.h"
#include "accountcredeswidget.h"
#include <QMessageBox>
#include <QString>
#include <QSet>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow), loginWidget(new LoginWidget(this)),
    mainWidget(new MainWidget(this)), depositWidget(new DepositWidget(this))
    , withdrawWidget(new WithdrawWidget(this)), changePasswordWidget(new ChangePasswordWidget(this))
    , accountCreDesWidget(new AccountCreDesWidget(this)), transferWidget(new TransferWidget(this)), atm()
{
    ui->setupUi(this);

    if(!QFile::exists("data.txt")){ // data.txt不存在时设置初始账号
        if(atm.recoverDefaultAccount()){
            QMessageBox::information(this, "恢复默认", "已恢复默认账号");
        }
    }


    if(!atm.init()){ // 初始化atm系统
        QMessageBox::warning(this, "错误", "初始化读取文件时出错");
        QApplication::quit();
    }

    // 将各个Widget添加到stackedWidget
    ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->addWidget(mainWidget);
    ui->stackedWidget->addWidget(depositWidget);
    ui->stackedWidget->addWidget(withdrawWidget);
    ui->stackedWidget->addWidget(changePasswordWidget);
    ui->stackedWidget->addWidget(accountCreDesWidget);
    ui->stackedWidget->addWidget(transferWidget);
    ui->stackedWidget->setCurrentWidget(loginWidget);





    // 连接从子Widget得到的信号与槽函数
    connect(loginWidget, &LoginWidget::loginButtonClicked, this, &MainWindow::handleLogin);
    // 连接存款信号与存款槽函数
    connect(depositWidget, &DepositWidget::depositButtonClicked, this, &MainWindow::handleDeposit);
    // 连接取款信号与取款槽函数
    connect(withdrawWidget, &WithdrawWidget::withdrawButtonClicked, this, &MainWindow::handleWithdraw);
    // 连接修改密码信号与修改密码槽函数
    connect(changePasswordWidget, &ChangePasswordWidget::changePWDBtnClicked, this , &MainWindow::handleChangePassword);
    // 连接开卡信号与开卡槽函数
    connect(accountCreDesWidget, &AccountCreDesWidget::createButtonClicked, this, &MainWindow::handleCreate);
    // 连接销户信号与销户槽函数
    connect(accountCreDesWidget, &AccountCreDesWidget::destoryButtonClicked, this , &MainWindow::handleDestory);
    // 连接转账信号与转账槽函数
    connect(transferWidget, &TransferWidget::transferBtnClicked, this , &MainWindow::handleTransfer);
    // lambda表达式处理查询余额信号
    connect(mainWidget, &MainWidget::checkBalanceButtonClicked, this, [this](){
        mainWidget->showBalance(atm.checkBalance());
    });
    // lambda表达式处理退出登录信号
    connect(mainWidget, &MainWidget::quitButtonClicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();
    });
    // lambda表达式处理前往存款界面信号
    connect(mainWidget, &MainWidget::toDepositButtonClicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(depositWidget);
        depositWidget->updateBalance(atm.checkBalance());

    });
    // lambda表达式处理前往取款界面信号
    connect(mainWidget, &MainWidget::toWithdrawButtonClicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(withdrawWidget);
        withdrawWidget->updateBalance(atm.checkBalance());
    });
    // lambda表达式处理前往转账界面信号
    connect(mainWidget, &MainWidget::toTransferButtonClicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(transferWidget);
        transferWidget->updateBalance(atm.checkBalance());
    });
    // lambda表达式处理前往修改密码界面信号
    connect(mainWidget, &MainWidget::toChangePWDButoonClicked, this , [this](){
        ui->stackedWidget->setCurrentWidget(changePasswordWidget);
        changePasswordWidget->clearInformation();
    });
    // lambda表达式处理前往开卡销户界面信号
    connect(loginWidget, &LoginWidget::toCreDesBtnClicked, this , [this](){
        ui->stackedWidget->setCurrentWidget(accountCreDesWidget);
        accountCreDesWidget->clearInformation();
    });
    // lambda表达式处理返回主界面信号
    connect(depositWidget,&DepositWidget::backButtonClicked, this, [this](){ // 存款界面返回
        ui->stackedWidget->setCurrentWidget(mainWidget);
        mainWidget->showBalance(atm.checkBalance());
    });
    connect(withdrawWidget, &WithdrawWidget::backButtonClicked, this, [this](){ // 取款界面返回
        ui->stackedWidget->setCurrentWidget(mainWidget);
        mainWidget->showBalance(atm.checkBalance());
    });
    connect(transferWidget, &TransferWidget::backButtonClicked, this, [this](){ // 转账界面返回
        ui->stackedWidget->setCurrentWidget(mainWidget);
        mainWidget->showBalance(atm.checkBalance());
    } );
    connect(changePasswordWidget, &ChangePasswordWidget::backButtonClicked, this, [this](){ // 修改密码界面返回
        ui->stackedWidget->setCurrentWidget(mainWidget);
    } );
    connect(accountCreDesWidget, &AccountCreDesWidget::backButtonClicked, this, [this](){ // 开卡销户界面返回
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();
    } );


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
    if(line.isEmpty()){ // 检验是否为空
        QMessageBox::warning(this, "存款失败", "存款金额不能为空！");
    }else if(line.contains(".")){ //分开处理带.和不带.的情况
        unsigned int intPart = line.split(".").first().toUInt();
        unsigned int floatPart = line.split(".").last().toUInt();
        if(line.split(".").last().size()<2) floatPart *= 10; // 判断小数部分的位数
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

void MainWindow::handleWithdraw(){
    QString line = withdrawWidget->getWithdrawAmount();
    unsigned int finalAmount = line.toUInt()*100;
    if(finalAmount > atm.checkBalance()){ // 避免透支
        QMessageBox::warning(this, "取款失败", "您的账户余额不足！");
    }else{
        atm.withdraw(finalAmount);
        QMessageBox::information(this, "取款成功", "您已取款"+line+" 元。");
        withdrawWidget->updateBalance(atm.checkBalance());
    }
}

void MainWindow::handleChangePassword(){
    std::vector<QString> pwds = changePasswordWidget->getUserInput();
    if(pwds[0].isEmpty() || pwds[1].isEmpty() || pwds[2].isEmpty()){
        QMessageBox::warning(this, "修改密码失败", "您输入的密码不能为空！");
    }else if(pwds[1] != pwds[2]){
        QMessageBox::warning(this, "修改密码失败", "您输入的两次新密码不一致！");
        changePasswordWidget->clearInformation();
    }else if(pwds[1].size() < 6){
        QMessageBox::warning(this, "修改密码失败", "您输入的新密码必须为6位！");
        changePasswordWidget->clearInformation();

    }else if([pwds]() -> bool{
                   QSet<QString> charSet;
                   for(const QChar& ch : pwds[1]){
                       charSet.insert(ch);
                   }
                   return charSet.size() == 1;
               }()){ //检查新密码是否6位完全相同 通过将所有字符添加进集合 利用集合的互异性判断是否完全相同
        QMessageBox::warning(this, "修改密码失败", "密码6位不能完全相同！");
        changePasswordWidget->clearInformation();

    }else if (atm.changePassword(pwds[0],pwds[1])){
        QMessageBox::information(this, "修改密码成功", "您已成功修改密码");
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();

    }else{
        QMessageBox::warning(this, "修改密码失败", "您输入的旧密码错误！");
        changePasswordWidget->clearInformation();

    }

}

void MainWindow::handleCreate(){
    std::vector<QString> inputs = accountCreDesWidget->getUserInput();
    if(inputs[0].isEmpty() || inputs[1].isEmpty() || inputs[2].isEmpty()){
        QMessageBox::warning(this, "开卡失败", "您输入的卡号与密码不能为空！");
    }else if(inputs[1] != inputs[2]){
        QMessageBox::warning(this, "开卡失败", "您输入的两次密码不一致！");
        accountCreDesWidget->clearInformation();
    }else if(inputs[1].size() < 6){
        QMessageBox::warning(this, "开卡失败", "您输入的密码必须为6位！");
        accountCreDesWidget->clearInformation();

    }else if([inputs]() -> bool{
                   QSet<QString> charSet;
                   for(const QChar& ch : inputs[1]){
                       charSet.insert(ch);
                   }
                   return charSet.size() == 1;
               }()){ //检查新密码是否6位完全相同 通过将所有字符添加进集合 利用集合的互异性判断是否完全相同
        QMessageBox::warning(this, "开卡失败", "密码6位不能完全相同！");
        accountCreDesWidget->clearInformation();

    }else if (atm.createCard(inputs[0],inputs[1])){
        QMessageBox::information(this, "开卡成功", "您已成功开卡");
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();

    }else{
        QMessageBox::warning(this, "开卡失败", "卡号与已有卡号重复");
        accountCreDesWidget->clearInformation();

    }
}

void MainWindow::handleDestory(){
    std::vector<QString> inputs = accountCreDesWidget->getUserInput();
    if(inputs[0].isEmpty() || inputs[1].isEmpty() || inputs[2].isEmpty()){
        QMessageBox::warning(this, "销户失败", "您输入的卡号与密码不能为空！");
    }else if(inputs[1] != inputs[2]){
        QMessageBox::warning(this, "销户失败", "您输入的两次密码不一致！");
        accountCreDesWidget->clearInformation();
    }else if(inputs[1].size() < 6){
        QMessageBox::warning(this, "销户失败", "您输入的密码必须为6位！");
        accountCreDesWidget->clearInformation();

    }else if (atm.destroyAccount(inputs[0],inputs[1])){
        QMessageBox::information(this, "销户成功", "您已成功销户");
        ui->stackedWidget->setCurrentWidget(loginWidget);
        loginWidget->clearInformation();

    }else{
        QMessageBox::warning(this, "销户失败", "卡号不存在");
        accountCreDesWidget->clearInformation();

    }

}

void MainWindow::handleTransfer(){
    unsigned int amount = transferWidget->getTransferAmount().toUInt();
    QString targetCard = transferWidget->getTargetCard();
    if(amount > atm.checkBalance()){
        QMessageBox::warning(this, "转账失败", "您的帐户余额不足。");
    }else if(atm.transfer(targetCard , amount)){
        QMessageBox::information(this, "转账成功", "您已成功转账");
        transferWidget->updateBalance(atm.checkBalance());
    }else{
        QMessageBox::warning(this, "转账失败", "您输入的卡号不存在。");

    }
}

