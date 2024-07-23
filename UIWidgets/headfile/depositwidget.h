#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QWidget>

namespace Ui {
class DepositWidget;
}

class DepositWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWidget(QWidget *parent = nullptr);
    ~DepositWidget();

    // 在存款界面更新账户余额
    void updateBalance(unsigned int balance);

    QString getDepositAmount() const;

signals:
    void backButtonClicked();
    void depositButtonClicked();

private:
    Ui::DepositWidget *ui;
};

#endif // DEPOSITWIDGET_H
