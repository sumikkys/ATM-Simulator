#ifndef ACCOUNTCREDESWIDGET_H
#define ACCOUNTCREDESWIDGET_H


/***********************************************
 * 开卡/销户界面
 **********************************************/

#include <QWidget>

namespace Ui {
class AccountCreDesWidget;
}

class AccountCreDesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountCreDesWidget(QWidget *parent = nullptr);
    ~AccountCreDesWidget();

    void clearInformation(); // 清除已输入信息
    std::vector<QString> getUserInput() const; // 获取用户输入的信息返回给MainWindow的处理函数


signals:
    void backButtonClicked(); // 返回信号
    void destoryButtonClicked(); // 销户信号
    void createButtonClicked(); // 开卡信号

private:
    Ui::AccountCreDesWidget *ui;
};

#endif // ACCOUNTCREDESWIDGET_H
