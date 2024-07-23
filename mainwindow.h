#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "atmsystem.h"
#include "UIWidgets/headfile/loginwidget.h"
#include "UIWidgets/headfile/mainwidget.h"
#include "UIWidgets/headfile/depositwidget.h"
#include "UIWidgets/headfile/withdrawwidget.h"
#include "UIWidgets/headfile/changepasswordwidget.h"
#include "UIWidgets/headfile/accountcredeswidget.h"
#include "UIWidgets/headfile/transferwidget.h"

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
    // 转账槽函数
    void handleTransfer();



private:
    Ui::MainWindow *ui;
    LoginWidget* loginWidget;
    MainWidget* mainWidget;
    DepositWidget* depositWidget;
    WithdrawWidget* withdrawWidget;
    ChangePasswordWidget* changePasswordWidget;
    AccountCreDesWidget* accountCreDesWidget;
    TransferWidget* transferWidget;

    AtmSystem atm;
};
#endif // MAINWINDOW_H
