#include "depositwidget.h"
#include "ui_depositwidget.h"

DepositWidget::DepositWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositWidget)
{
    ui->setupUi(this);
}

DepositWidget::~DepositWidget()
{
    delete ui;
}
