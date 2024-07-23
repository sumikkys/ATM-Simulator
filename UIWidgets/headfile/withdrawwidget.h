#ifndef WITHDRAWWIDGET_H
#define WITHDRAWWIDGET_H


/***********************************************
 * 取款界面
 **********************************************/



#include <QWidget>

namespace Ui {
class WithdrawWidget;
}

class WithdrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawWidget(QWidget *parent = nullptr);
    ~WithdrawWidget();

    // 在取款界面更新账户余额
    void updateBalance(unsigned int balance);

    // 返回用户输入给MainWindow的处理函数
    QString getWithdrawAmount() const;

signals:
    void backButtonClicked(); // 返回信号
    void withdrawButtonClicked(); // 取款信号

private:
    Ui::WithdrawWidget *ui;
};

#endif // WITHDRAWWIDGET_H
