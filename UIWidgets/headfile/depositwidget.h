#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H


/***********************************************
 * 存款界面
 **********************************************/



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

    // 清除已输入信息
    void clearInformation();

    // 返回用户输入的存款金额给MainWindow处理函数
    QString getDepositAmount() const;

signals:
    void backButtonClicked(); // 返回信号
    void depositButtonClicked(); // 存款信号

private:
    Ui::DepositWidget *ui;
};

#endif // DEPOSITWIDGET_H
