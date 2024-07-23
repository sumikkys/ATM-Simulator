/**
 * @file withdrawwidget.cpp
 * @brief 取款界面的实现
 */


#include "headfile/withdrawwidget.h"
#include "ui_withdrawwidget.h"

/**
 * @brief 构造函数，初始化取款界面
 *
 * @param parent 父Widget指针
 *
 */
WithdrawWidget::WithdrawWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawWidget)
{
    ui->setupUi(this);

    // 按钮点击时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&WithdrawWidget::backButtonClicked);
    connect(ui->withdrawButton,&QPushButton::clicked,this,&WithdrawWidget::withdrawButtonClicked);

    // 为ComboBox添加限定的取款金额
    for (int i = 100; i <= 5000; i += 100) {
        ui->withdrawAmtBox->addItem(QString::number(i));
    }
}

/**
 * @brief 析构函数
 */
WithdrawWidget::~WithdrawWidget()
{
    delete ui;
}

/**
 * @brief 更新显示当前帐户余额
 */
void WithdrawWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的取款金额的QString
 */
QString WithdrawWidget::getWithdrawAmount() const{
    return ui->withdrawAmtBox->currentText();
}
