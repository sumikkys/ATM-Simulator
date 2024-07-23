/**
 * @file loginwidget.cpp
 * @brief 登陆界面的实现
 */


#include "headfile/loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>
#include <QIntValidator>


/**
 * @brief 构造函数，初始化登陆界面
 *
 * @param parent 父Widget指针
 *
 */
LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //点击登陆按钮时广播信号
    connect(ui->loginButton,&QPushButton::clicked,this,&LoginWidget::loginButtonClicked);
    //点击开卡/销户按钮时广播信号
    connect(ui->toCreDesBtn,&QPushButton::clicked,this,&LoginWidget::toCreDesBtnClicked);

    //限制卡号输入框输入格式为16位纯数字
    auto numberRegex = QRegularExpression("[0-9]{16}");
    QValidator* numberValidator = new QRegularExpressionValidator(numberRegex, this);
    ui->numberLine->setValidator(numberValidator);
    //限制密码输入框输入格式为6位纯数字
    auto passwordRegex = QRegularExpression("[0-9]{6}");
    QValidator* passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    ui->passwordLine->setValidator(passwordValidator);

}

/**
 * @brief 析构函数
 */
LoginWidget::~LoginWidget()
{
    delete ui;
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的卡号的QString
 */
QString LoginWidget::getCardNumber() const{
    QString cardNumber = ui->numberLine->text();
    return cardNumber;
}

/**
 * @brief 获取用户在图形界面的输入，返回给MainWindow的处理函数
 *
 * @return 返回用户输入的密码的QString
 */
QString LoginWidget::getPassword() const{
    QString password = ui->passwordLine->text();
    return password;
}

/**
 * @brief 清除用户已输入的信息，便于下次登陆时输入新信息
 */
void LoginWidget::clearInformation(){
    ui->numberLine->clear();
    ui->passwordLine->clear();
}
