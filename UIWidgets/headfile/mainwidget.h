#ifndef MAINWIDGET_H
#define MAINWIDGET_H



/***********************************************
 * 主界面
 **********************************************/




#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    // 显示所查询的余额
    void showBalance(unsigned int m_balance);

    // 隐藏余额
    void hideBalance();


signals:
    void checkBalanceButtonClicked(); // 查询余额信号
    void quitButtonClicked(); // 退出登陆信号
    void toDepositButtonClicked(); // 前往存款界面信号
    void toWithdrawButtonClicked(); // 前往取款界面信号
    void toTransferButtonClicked(); // 前往转账界面信号
    void toChangePWDButoonClicked(); // 前往修改密码信号

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
