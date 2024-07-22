#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H
#include <QString>
#include<account.h>

class AtmSystem
{
private:
    Account account;
public:
    // 构造函数
    AtmSystem();

    // 登陆 登陆成功时返回true给LoginWidget::handleLogin函数 并创建account
    bool login(const QString& cardNumber, const QString& password);

    // 查询余额
    unsigned int checkBalance();

    // 取款
    void withdraw(unsigned int amount);

    // 存款
    void deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);
};

#endif // ATMSYSTEM_H
