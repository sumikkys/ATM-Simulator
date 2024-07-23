#ifndef TRANSFERWIDGET_H
#define TRANSFERWIDGET_H

/***********************************************
 * 转账界面
 **********************************************/



#include <QWidget>

namespace Ui {
class TransferWidget;
}

class TransferWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TransferWidget(QWidget *parent = nullptr);
    ~TransferWidget();

    // 在转账界面更新账户余额
    void updateBalance(unsigned int balance);
    // 清除用户已输入信息
    void clearInformation();

    // 返回用户输入给MainWindow的处理函数
    QString getTransferAmount() const;
    QString getTargetCard() const;

signals:
    void backButtonClicked(); // 返回信号
    void transferBtnClicked(); // 转账信号

private:
    Ui::TransferWidget *ui;
};

#endif // TRANSFERWIDGET_H
