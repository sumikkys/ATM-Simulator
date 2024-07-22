#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>

class Account
{
private:
    QString cardNumber; // 卡号
    QString password; // 密码
    unsigned int balance; // 余额 数值10000表示为100.00元 以int形式存储保证准确性

public:
    // 构造函数
    Account();

    Account(const QString& m_number, const QString& m_password, const unsigned int m_balance);

    // 登陆后初始化函数
    // void setAccount(const QString& m_number, const QString& m_password, const unsigned int m_balance);

    bool login(const QString& m_number, const QString& m_password);
    // 获取余额
    unsigned int getBalance();

    // 取款
    void withdraw(unsigned int amount);

    // 存款
    void deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);


};

#endif // ACCOUNT_H
