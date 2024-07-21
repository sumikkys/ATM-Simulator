#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>

class Account
{
private:
    QString cardNumber; // 卡号
    QString password; // 密码
    unsigned int balance; // 余额 数值10000表示为100.00元

public:
    // 构造函数
    Account(const QString& cardNumber, const QString& password, const unsigned int balance);

    // 获取余额
    unsigned int getBalance();

    // 取款
    bool withdraw(unsigned int amount);

    // 存款
    bool deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);


};

#endif // ACCOUNT_H
