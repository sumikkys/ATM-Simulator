#include "account.h"

Account::Account() : cardNumber(),password(),balance(){}

Account::Account(const QString& m_number, const QString& m_password, unsigned int m_balance)
    : cardNumber(m_number), password(m_password), balance(m_balance){}

// 哈希密码
QString Account::hashPassword(const QString& password) const {
    QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(byteArray.toHex());
}


// 登陆
bool Account::login(const QString& m_number, const QString& m_password) const{
    if(m_number == cardNumber && hashPassword(m_password) == password){
        return true;
    }else{
        return false;
    }
}

void Account::setAccount(const QString& m_number, const QString& m_password, unsigned int m_balance){
    cardNumber = m_number;
    password = hashPassword(m_password);
    balance = m_balance;
}


// 返回卡号
QString Account::getCardNumber() const{
    return cardNumber;
}

// 返回余额
unsigned int Account::getBalance() const{
    return balance;
}

// 获取哈希后的密码
QString Account::getPassword() const{
    return password;
}

// 验证密码
bool Account::validatePassword(const QString& m_password) const{
    if(hashPassword(m_password) == password){
        return true;
    }else{ return false;}
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
    if(hashPassword(oldPassword) == password){
        password = hashPassword(newPassword);
        return true;
    }else{
        return false;
    }
}
