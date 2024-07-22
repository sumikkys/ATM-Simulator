#ifndef WITHDRAWWIDGET_H
#define WITHDRAWWIDGET_H

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

    QString getWithdrawAmount();

signals:
    void backButtonClicked();
    void withdrawButtonClicked();

private:
    Ui::WithdrawWidget *ui;
};

#endif // WITHDRAWWIDGET_H
