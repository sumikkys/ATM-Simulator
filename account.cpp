#include "account.h"

Account::Account() : id(),cardNumber(),password(),balance(){}

Account::Account(int m_id, const QString& m_number, const QString& m_password, unsigned int m_balance)
    : id(m_id),cardNumber(m_number), password(m_password), balance(m_balance){}

// 哈希密码
QString Account::hashPassword(const QString& password) const {
    QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(byteArray.toHex());
}


// 返回id
int Account::getId() const{
    return id;
}

// 返回卡号
QString Account::getCardNumber() const{
    return cardNumber;
}

// 返回余额
unsigned int Account::getBalance() const{
    return balance;
}


// 验证密码
bool Account::validatePassword(const QString& m_password) const{
    if(hashPassword(m_password) == password){
        return true;
    }else{ return false;}
}


// 设置id
void Account::setId(int m_id){
    id = m_id;
}

// 设定余额
void Account::setBalance(unsigned int m_balance){
    balance = m_balance;
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
