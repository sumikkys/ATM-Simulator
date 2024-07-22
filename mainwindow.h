#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "account.h"
#include "atmsystem.h"
#include "loginwidget.h"
#include "mainwidget.h"
#include "depositwidget.h"
#include "withdrawwidget.h"
#include "changepasswordwidget.h"
#include "accountcredeswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    // 登陆槽函数
    void handleLogin();
    // 存款槽函数
    void handleDeposit();
    // 取款槽函数
    void handleWithdraw();
    // 修改密码槽函数
    void handleChangePassword();
    // 开卡槽函数
    void handleCreate();
    // 销户槽函数
    void handleDestory();



private:
    Ui::MainWindow *ui;
    LoginWidget* loginWidget;
    MainWidget* mainWidget;
    DepositWidget* depositWidget;
    WithdrawWidget* withdrawWidget;
    ChangePasswordWidget* changePasswordWidget;
    AccountCreDesWidget* accountCreDesWidget;

    AtmSystem atm;
};
#endif // MAINWINDOW_H
