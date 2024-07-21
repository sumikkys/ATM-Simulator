#include "withdrawwidget.h"
#include "ui_withdrawwidget.h"

WithdrawWidget::WithdrawWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawWidget)
{
    ui->setupUi(this);
}

WithdrawWidget::~WithdrawWidget()
{
    delete ui;
}
