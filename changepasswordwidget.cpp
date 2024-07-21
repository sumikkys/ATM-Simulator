#include "changepasswordwidget.h"
#include "ui_changepasswordwidget.h"

ChangePasswordWidget::ChangePasswordWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangePasswordWidget)
{
    ui->setupUi(this);
}

ChangePasswordWidget::~ChangePasswordWidget()
{
    delete ui;
}
