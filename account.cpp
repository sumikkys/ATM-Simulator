/**
 * @file account.cpp
 * @brief 账户类的实现
 */


#include "account.h"

/**
 * @brief 构造函数
 */
Account::Account() : id(),cardNumber(),password(),balance(){}

/**
 * @brief 构造函数，根据提供的信息创建完整的Account对象
 *
 * @param m_id 账户id
 * @param m_number 卡号
 * @param m_password 已哈希的密码
 * @param m_balance 账户余额
 */
Account::Account(int m_id, const QString& m_number, const QString& m_password, unsigned int m_balance)
    : id(m_id),cardNumber(m_number), password(m_password), balance(m_balance){}

/**
 * @brief 对输入的密码进行加密
 *
 * @param password 要加密的密码
 * @return 加密后的 16 进制字符串
 */
QString Account::hashPassword(const QString& password) const {
    QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256); // Sha256加密算法
    return QString(byteArray.toHex()); // 转换为16进制字符串后返回
}


/**
 * @brief 返回当前账户的id
 *
 * @return 当前账户的id
 */
int Account::getId() const{
    return id;
}

/**
 * @brief 返回当前账户的卡号
 *
 * @return 当前账户的卡号
 */
QString Account::getCardNumber() const{
    return cardNumber;
}

/**
 * @brief 返回当前账户的余额
 *
 * @return 当前账户的余额
 */
unsigned int Account::getBalance() const{
    return balance;
}


/**
 * @brief 对外提供的验证密码的方法
 *
 * @param m_password 要验证的密码
 * @return 密码是否正确的布尔值
 */
bool Account::validatePassword(const QString& m_password) const{
    if(hashPassword(m_password) == password){
        return true;
    }else{ return false;}
}


/**
 * @brief 设置当前账户的id
 *
 * @param m_id 要设置为的id
 */
void Account::setId(int m_id){
    id = m_id;
}

/**
 * @brief 设置当前账户的余额
 *
 * @param m_balance 要设置为的余额
 */
void Account::setBalance(unsigned int m_balance){
    balance = m_balance;
}

/**
 * @brief 存款，增加账户余额
 *
 * @param amount 要存款的金额
 */
void Account::deposit(unsigned int amount){
    this->balance += amount;
}

/**
 * @brief 取款，减少账户余额
 *
 * @param amount 要取款的金额
 */
void Account::withdraw(unsigned int amount){
    this->balance -= amount;
}

/**
 * @brief 修改密码的方法
 *
 * 验证用户提供的旧密码是否正确，若正确则将密码修改为新密码
 *
 * @param oldPassword 用户提供的旧密码
 * @param newPassword 用户提供的新密码
 * @return 修改密码是否成功的布尔值
 */
bool Account::changePassword(const QString& oldPassword, const QString& newPassword){
    if(hashPassword(oldPassword) == password){
        password = hashPassword(newPassword);
        return true;
    }else{
        return false;
    }
}
