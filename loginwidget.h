#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    // 向外提供输入框中输入的卡号与密码
    QString getCardNumber();
    QString getPassword();

    // 用户退出登录后清除登陆信息
    void clearInformation();
signals:
    // 当登陆按钮点击时loginWidget广播的信号
    void loginButtonClicked();

    // 当开卡/销户点击时广播信号
    void toCreDesBtnClicked();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
