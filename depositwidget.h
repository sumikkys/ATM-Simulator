#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QWidget>

namespace Ui {
class DepositWidget;
}

class DepositWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWidget(QWidget *parent = nullptr);
    ~DepositWidget();

private:
    Ui::DepositWidget *ui;
};

#endif // DEPOSITWIDGET_H
