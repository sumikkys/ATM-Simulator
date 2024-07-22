#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : account("123456", "123456", 1000000) {}


// 登陆
bool AtmSystem::login(const QString& cardNumber, const QString& password){
    return account.login(cardNumber,password);
}

// 返回卡号
QString AtmSystem::checkCardNumber(){
    return account.getCardNumber();
}

// 返回余额
unsigned int AtmSystem::checkBalance(){
    return account.getBalance();
}

// 存款
void AtmSystem::deposit(unsigned int amount){
    account.deposit(amount);
}

// 取款
void AtmSystem::withdraw(unsigned int amount){
    account.withdraw(amount);
}

// 修改密码
bool AtmSystem::changePassword(const QString& oldPassword, const QString& newPassword){
    return account.changePassword(oldPassword,newPassword);
}

