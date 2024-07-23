#ifndef TRANSFERWIDGET_H
#define TRANSFERWIDGET_H

#include <QWidget>

namespace Ui {
class TransferWidget;
}

class TransferWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TransferWidget(QWidget *parent = nullptr);
    ~TransferWidget();

    // 在转账界面更新账户余额
    void updateBalance(unsigned int balance);

    QString getTransferAmount() const;
    QString getTargetCard() const;

signals:
    void backButtonClicked();
    void transferBtnClicked();

private:
    Ui::TransferWidget *ui;
};

#endif // TRANSFERWIDGET_H
