#ifndef ACCOUNT_H
#define ACCOUNT_H



/***********************************************
 * 账户类
 **********************************************/



#include<QString>
#include<QCryptographicHash>

class Account
{
private:
    int id;
    QString cardNumber; // 卡号
    QString password; // 哈希后密码
    unsigned int balance; // 余额 数值10000表示为100.00元 以int形式存储保证准确性

    QString hashPassword(const QString& password) const ;// 哈希密码的方法

public:
    // 构造函数
    Account();
    Account(int id, const QString& m_number, const QString& m_password, unsigned int m_balance);

    // 获取Id
    int getId() const;

    // 获取卡号
    QString getCardNumber() const;

    // 获取余额
    unsigned int getBalance() const;

    // 验证密码
    bool validatePassword(const QString& m_password) const;

    // 设定id
    void setId(int m_id);

    // 设定余额
    void setBalance(unsigned int m_balance);

    // 取款
    void withdraw(unsigned int amount);

    // 存款
    void deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);


};

#endif // ACCOUNT_H
