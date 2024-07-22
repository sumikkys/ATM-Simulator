#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : accounts(),index(0){}

bool AtmSystem::recoverDefaultAccount(){
    QFile file("data.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        return false;
    }

    QTextStream out(&file);
    Account a;
    a.setAccount("123456","123456",1000000);
    out << a.getCardNumber() <<","<< a.getPassword()<<"," << QString::number(a.getBalance()) << "\n";
    file.close();
    return true;
}

// 初始化
bool AtmSystem::init(){
    QFile file("data.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QStringList line = in.readLine().split(",");
        if(line.size()!=3){
            continue;
        }
        accounts.emplace_back(line.at(0),line.at(1),line.at(2).toUInt());
    }
    file.close();

    return true;
}


// 登陆
bool AtmSystem::login(const QString& cardNumber, const QString& password){
    int i = 0 ;
    for(Account account : accounts){
        if(account.login(cardNumber, password)){
            index = i;
            return true;
        }
        i++;
    }
    return false;
}

// 返回卡号
QString AtmSystem::checkCardNumber(){
    return accounts[index].getCardNumber();
}

// 返回余额
unsigned int AtmSystem::checkBalance(){
    return accounts[index].getBalance();
}

// 存款
bool AtmSystem::deposit(unsigned int amount){
    accounts[index].deposit(amount);
    QFile file("data.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        return false;
    }

    QTextStream out(&file);

    for(Account account : accounts){
        out << account.getCardNumber() << "," << account.getPassword()<< "," << QString::number(account.getBalance()) << "\n";
    }
    file.close();
    return true;
}

// 取款
bool AtmSystem::withdraw(unsigned int amount){
    accounts[index].withdraw(amount);
    QFile file("data.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        return false;
    }

    QTextStream out(&file);

    for(Account account : accounts){
        out << account.getCardNumber() << "," << account.getPassword()<< "," << QString::number(account.getBalance()) << "\n";
    }
    file.close();
    return true;

}

// 修改密码
bool AtmSystem::changePassword(const QString& oldPassword, const QString& newPassword){
    if(accounts[index].changePassword(oldPassword,newPassword)){
        QFile file("data.txt");

        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
            return false;
        }

        QTextStream out(&file);

        for(Account account : accounts){
            out << account.getCardNumber() << "," << account.getPassword()<< "," << QString::number(account.getBalance()) << "\n";
        }
        file.close();
        return true;
        }else{
    return false;
        }
}

