#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>
#include<QCryptographicHash>

class Account
{
private:
    int id;
    QString cardNumber; // 卡号
    QString password; // 密码，哈希后存储
    unsigned int balance; // 余额 数值10000表示为100.00元 以int形式存储保证准确性

    QString hashPassword(const QString& password) const ;// 哈希密码的方法

public:
    // 构造函数
    Account();

    Account(int id, const QString& m_number, const QString& m_password, unsigned int m_balance);

    bool login(const QString& m_number, const QString& m_password) const;

    // 设定账户
    void setAccount(const QString& m_number, const QString& m_password, unsigned int m_balance);

    // 设定卡号
    void setId(int m_id);

    // 获取Id
    int getId() const;

    // 获取卡号
    QString getCardNumber() const;

    // 获取余额
    unsigned int getBalance() const;

    // 获取哈希后的密码
    QString getPassword() const;

    // 验证密码
    bool validatePassword(const QString& m_password) const;

    // 取款
    void withdraw(unsigned int amount);

    // 存款
    void deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);


};

#endif // ACCOUNT_H
