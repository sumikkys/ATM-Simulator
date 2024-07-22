#include "account.h"

Account::Account() : cardNumber(),password(),balance(){}

Account::Account(const QString& m_number, const QString& m_password, unsigned int m_balance)
    : cardNumber(m_number), password(m_password), balance(m_balance){}

// 登陆
bool Account::login(const QString& m_number, const QString& m_password){
    if(m_number == cardNumber && m_password == password){
        return true;
    }else{
        return false;
    }
}

// 返回卡号
QString Account::getCardNumber(){
    return cardNumber;
}

// 返回余额
unsigned int Account::getBalance(){
    return balance;
}

// 存款
void Account::deposit(unsigned int amount){
    this->balance += amount;
}

// 取款
void Account::withdraw(unsigned int amount){
    this->balance -= amount;
}

// 修改密码
bool Account::changePassword(const QString& oldPassword, const QString& newPassword){
    if(oldPassword == password){
        password = newPassword;
        return true;
    }else{
        return false;
    }
}
