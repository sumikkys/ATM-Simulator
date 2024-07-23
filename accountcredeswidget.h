#ifndef ACCOUNTCREDESWIDGET_H
#define ACCOUNTCREDESWIDGET_H

#include <QWidget>

namespace Ui {
class AccountCreDesWidget;
}

class AccountCreDesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountCreDesWidget(QWidget *parent = nullptr);
    ~AccountCreDesWidget();

    void clearInformation();
    std::vector<QString> getUserInput() const;


signals:
    void backButtonClicked();
    void destoryButtonClicked();
    void createButtonClicked();

private:
    Ui::AccountCreDesWidget *ui;
};

#endif // ACCOUNTCREDESWIDGET_H
