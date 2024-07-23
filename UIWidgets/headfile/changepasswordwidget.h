#ifndef CHANGEPASSWORDWIDGET_H
#define CHANGEPASSWORDWIDGET_H


/***********************************************
 * 修改密码界面
 **********************************************/



#include <QWidget>

namespace Ui {
class ChangePasswordWidget;
}

class ChangePasswordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePasswordWidget(QWidget *parent = nullptr);
    ~ChangePasswordWidget();

    void clearInformation(); // 清除已输入信息
    std::vector<QString> getUserInput() const; // 获取用户输入的信息返回给MainWindow的处理函数

signals:
    void backButtonClicked(); // 返回信号
    void changePWDBtnClicked(); // 修改密码信号

private:
    Ui::ChangePasswordWidget *ui;
};

#endif // CHANGEPASSWORDWIDGET_H
