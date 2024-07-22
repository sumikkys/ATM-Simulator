#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H
#include <QString>
#include<account.h>
#include <QFile>
#include <QMessageBox>

class AtmSystem
{
private:
    std::vector<Account> accounts;

    int index;
public:
    // 构造函数
    AtmSystem();

    // 设置初始账号便于调试
    bool recoverDefaultAccount();

    // 初始化
    bool init();

    // 登陆 登陆成功时返回true给LoginWidget::handleLogin函数 并创建account
    bool login(const QString& cardNumber, const QString& password);

    // 获取卡号
    QString checkCardNumber();

    // 查询余额
    unsigned int checkBalance();

    // 取款
    bool withdraw(unsigned int amount);

    // 存款
    bool deposit(unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);
};

#endif // ATMSYSTEM_H
