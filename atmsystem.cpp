#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : accounts(), db(), loginedId(), vectorIndex(){}

// 初始化
bool AtmSystem::init(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./atm_system.db");

    if (!db.open()) {
        qWarning() << "无法打开数据库:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS Accounts ("
               "account_id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "card_number TEXT UNIQUE NOT NULL,"
               "hashed_password TEXT NOT NULL,"
               "balance INTEGER NOT NULL CHECK (balance >= 0)"
               ");");

    Account a;
    a.setAccount("123456","123456",1000000);

    query.exec("SELECT * FROM Accounts WHERE card_number = '123456'");
    if(!query.next()){
        query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                      "VALUES (?, ?, ?)");
        query.addBindValue(a.getCardNumber());
        query.addBindValue(a.getPassword());
        query.addBindValue(a.getBalance());
        query.exec();
    }

    if(!query.exec("SELECT * FROM Accounts")){
        return false;
    }else{
        while(query.next()){
            accounts.emplace_back(query.value(0).toInt(),
                                  query.value(1).toString(),
                                  query.value(2).toString(),
                                  query.value(3).toUInt());
        }
        return true;
    }
}


// 登陆
bool AtmSystem::login(const QString& cardNumber, const QString& password){
    int i = 0;
    for(const Account& account : accounts){
        if(account.login(cardNumber, password)){
            loginedId = account.getId();
            vectorIndex = i;
            return true;
        }
        i++;
    }
    return false;
}

// 返回卡号
QString AtmSystem::checkCardNumber() const{
    return accounts[vectorIndex].getCardNumber();
}

// 返回余额
unsigned int AtmSystem::checkBalance() const{
    return accounts[vectorIndex].getBalance();
}

// 存款
bool AtmSystem::deposit(unsigned int amount){


    QSqlQuery query;
    db.transaction();

    query.prepare("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    query.addBindValue(amount);
    query.addBindValue(loginedId);
    if (query.exec()){
        db.commit();
        accounts[vectorIndex].deposit(amount);
        return true;
    }else{
        db.rollback();
        return false;

    }
}

// 取款
bool AtmSystem::withdraw(unsigned int amount){

    QSqlQuery query;
    db.transaction();

    query.prepare("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
    query.addBindValue(amount);
    query.addBindValue(loginedId);
    if (query.exec()){
        db.commit();
        accounts[vectorIndex].withdraw(amount);
        return true;
    }else{
        db.rollback();
        return false;

    }
}

// 转账
bool AtmSystem::transfer(const QString& targetCard, unsigned int amount){
    for(Account& account : accounts){
        if(account.getCardNumber() == targetCard){
            int id = account.getId();
            QSqlQuery query1;
            QSqlQuery query2;
            db.transaction();

            query1.prepare("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
            query2.prepare("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
            query1.addBindValue(amount);
            query1.addBindValue(id);
            query2.addBindValue(amount);
            query2.addBindValue(loginedId);
            if (query1.exec() && query2.exec()){
                db.commit();
                account.deposit(amount);
                accounts[vectorIndex].withdraw(amount);
                return true;
            }else{
                db.rollback();
                return false;
            }
        }
    }
    return false;
}

// 修改密码
bool AtmSystem::changePassword(const QString& oldPassword, const QString& newPassword){
    if(accounts[vectorIndex].changePassword(oldPassword,newPassword)){
        QSqlQuery query;
        db.transaction();

        query.prepare("UPDATE Accounts SET hashed_password = ? WHERE account_id = ?");
        query.addBindValue(accounts[vectorIndex].getPassword());
        query.addBindValue(loginedId);
        if (query.exec()){
            db.commit();
            return true;
        }else{
            db.rollback();
            accounts[vectorIndex].changePassword(newPassword,oldPassword);
            return false;

        }
    }else{
        return false;
    }
}

bool AtmSystem::createCard(const QString& cardNumber, const QString& password){
    for(const Account& account : accounts){
        if(account.getCardNumber() == cardNumber){
            return false;
        }
    }
    Account a;
    a.setAccount(cardNumber,password,0);

    QSqlQuery query;
    db.transaction();

    query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                  "VALUES (?, ?, ?)");
    query.addBindValue(a.getCardNumber());
    query.addBindValue(a.getPassword());
    query.addBindValue(a.getBalance());
    if (query.exec()){
        db.commit();
        query.prepare("SELECT account_id FROM Accounts WHERE card_number = ?");
        query.addBindValue(a.getCardNumber());
        query.exec();
        query.next();
        a.setId(query.value(0).toInt());
        accounts.push_back(a);
        return true;
    }else{
        db.rollback();
        return false;

    }
}

bool AtmSystem::destroyAccount(const QString& cardNumber, const QString& password){
    int i=0;
    for(const Account& account : accounts){
        if(account.getCardNumber() == cardNumber && account.validatePassword(password)){
            QSqlQuery query;
            db.transaction();

            query.prepare("DELETE FROM Accounts WHERE card_number = ?");
            query.addBindValue(cardNumber);

            if(query.exec()){
                db.commit();
                accounts.erase(accounts.begin()+i);
                return true;
            }else{
                db.rollback();
                return false;
            }
        }
        i++;
    }
    return false;

}
