/**
 * @file depositwidget.cpp
 * @brief 存款界面的实现
 */



#include "headfile/depositwidget.h"
#include "ui_depositwidget.h"
#include <QRegularExpressionValidator>

/**
 * @brief 构造函数，初始化存款界面
 *
 * @param parent 父Widget指针
 *
 */
DepositWidget::DepositWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositWidget)
{
    ui->setupUi(this);

    // 按钮点击时广播信号
    connect(ui->backButton,&QPushButton::clicked,this,&DepositWidget::backButtonClicked);
    connect(ui->depositButton,&QPushButton::clicked,this,&DepositWidget::depositButtonClicked);

    //限制单次存款金额与格式
    auto amountRegex = QRegularExpression("[0-9]{1,7}\\.[0-9]{1,2}");
    QValidator* numberValidator = new QRegularExpressionValidator(amountRegex, this);
    ui->amountLine->setValidator(numberValidator);

}

/**
 * @brief 析构函数
 */
DepositWidget::~DepositWidget()
{
    delete ui;
}
/**
 * @brief 更新显示当前帐户余额
 */
void DepositWidget::updateBalance(unsigned int balance){
    ui->balanceLabel->setText(QString::number(balance/100)+"."+QString("%1").arg(balance%100, 2, 10, QChar('0')));
}

/**
 * @brief 清除用户已输入的信息，便于下次输入
 */
void DepositWidget::clearInformation(){
    ui->amountLine->clear();

}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的存款金额的QString
 */
QString DepositWidget::getDepositAmount() const{
    return ui->amountLine->text();
}
