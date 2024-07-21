#ifndef CHANGEPASSWORDWIDGET_H
#define CHANGEPASSWORDWIDGET_H

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

private:
    Ui::ChangePasswordWidget *ui;
};

#endif // CHANGEPASSWORDWIDGET_H
