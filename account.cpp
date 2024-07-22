#include "account.h"

Account::Account() : cardNumber(),password(),balance(){}

Account::Account(const QString& m_number, const QString& m_password, const unsigned int m_balance)
    : cardNumber(m_number), password(m_password), balance(m_balance){}

// void Account::setAccount(const QString& m_number, const QString& m_password, const unsigned int m_balance) {
//     cardNumber = m_number;
//     password = m_password;
//     balance = m_balance;
// }

bool Account::login(const QString& m_number, const QString& m_password){
    if(m_number == cardNumber && m_password == password){
        return true;
    }else{
        return false;
    }
}

unsigned int Account::getBalance(){
    return balance;
}

void Account::deposit(unsigned int amount){
    this->balance += amount;
}
