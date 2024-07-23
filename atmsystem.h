#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H
#include <QString>
#include<account.h>
#include <QFile>
#include <QMessageBox>
#include <QtSql>

class AtmSystem
{
private:
    Account account;
    QSqlDatabase db;

    // 哈希密码
    QString hashPassword(const QString& password) const ;

public:
    // 构造函数
    AtmSystem();

    // 初始化
    bool init();

    // 登陆 登陆成功时返回true给LoginWidget::handleLogin函数 并创建account
    bool login(const QString& cardNumber, const QString& password);

    // 获取卡号
    QString checkCardNumber() const;

    // 查询余额
    unsigned int checkBalance();

    // 取款
    bool withdraw(unsigned int amount);

    // 存款
    bool deposit(unsigned int amount);

    // 转账
    bool transfer(const QString& targetCard, unsigned int amount);

    // 修改密码
    bool changePassword(const QString& oldPassword, const QString& newPassword);

    // 开卡
    bool createCard(const QString& cardNumber, const QString& password);

    // 销户
    bool destroyAccount(const QString& cardNumber, const QString& password);
};

#endif // ATMSYSTEM_H
