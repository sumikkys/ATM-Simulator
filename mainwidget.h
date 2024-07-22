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


signals:
    void checkBalanceButtonClicked();
    void quitButtonClicked();
    void toDepositButtonClicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
