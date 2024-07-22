#include "account.h"

Account::Account() : cardNumber(),password(),balance(){}

Account::Account(const QString& m_number, const QString& m_password, unsigned int m_balance)
    : cardNumber(m_number), password(m_password), balance(m_balance){}

bool Account::login(const QString& m_number, const QString& m_password){
    if(m_number == cardNumber && m_password == password){
        return true;
    }else{
        return false;
    }
}

QString Account::getCardNumber(){
    return cardNumber;
}

unsigned int Account::getBalance(){
    return balance;
}

void Account::deposit(unsigned int amount){
    this->balance += amount;
}

void Account::withdraw(unsigned int amount){
    this->balance -= amount;
}

bool Account::changePassword(const QString& oldPassword, const QString& newPassword){
    if(oldPassword == password){
        password = newPassword;
        return true;
    }else{
        return false;
    }
}
