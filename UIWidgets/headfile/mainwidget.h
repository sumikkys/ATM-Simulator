#ifndef MAINWIDGET_H
#define MAINWIDGET_H

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
    void checkBalanceButtonClicked();
    void quitButtonClicked();
    void toDepositButtonClicked();
    void toWithdrawButtonClicked();
    void toTransferButtonClicked();
    void toChangePWDButoonClicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
