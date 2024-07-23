#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : account(), db(){}

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
        return true;
}


// 登陆
bool AtmSystem::login(const QString& cardNumber, const QString& password){
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE card_number = ?");
    query.addBindValue(cardNumber);
    query.exec();
    if(!query.next()){
        return false;
    }else{
        Account a(query.value(0).toInt(),
                  query.value(1).toString(),
                  query.value(2).toString(),
                  query.value(3).toUInt()
            );
        if(a.login(cardNumber,password)){
            account = a;
            return true;
        }else{
            return false;
        }
    }
}

// 返回卡号
QString AtmSystem::checkCardNumber() const{
    return account.getCardNumber();
}

// 返回余额
unsigned int AtmSystem::checkBalance() const{
    return account.getBalance();
}

// 存款
bool AtmSystem::deposit(unsigned int amount){


    QSqlQuery query;
    db.transaction();

    query.prepare("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    query.addBindValue(amount);
    query.addBindValue(account.getId());
    if (query.exec()){
        db.commit();
        account.deposit(amount);
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
    query.addBindValue(account.getId());
    if (query.exec()){
        db.commit();
        account.withdraw(amount);
        return true;
    }else{
        db.rollback();
        return false;

    }
}

// 转账
bool AtmSystem::transfer(const QString& targetCard, unsigned int amount){
    QSqlQuery query;
    query.prepare("SELECT account_id FROM Accounts WHERE card_number = ?");
    query.addBindValue(targetCard);
    query.exec();
    if(!query.next()){
        return false;
    }else{
        int id = query.value(0).toInt();
        QSqlQuery query1;
        QSqlQuery query2;
        db.transaction();

        query1.prepare("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
        query2.prepare("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
        query1.addBindValue(amount);
        query1.addBindValue(id);
        query2.addBindValue(amount);
        query2.addBindValue(account.getId());
        if (query1.exec() && query2.exec()){
            db.commit();
            account.withdraw(amount);
            return true;
        }else{
            db.rollback();
            return false;
        }
    }
    return false;
}

// 修改密码
bool AtmSystem::changePassword(const QString& oldPassword, const QString& newPassword){
    if(account.changePassword(oldPassword,newPassword)){
        QSqlQuery query;
        db.transaction();

        query.prepare("UPDATE Accounts SET hashed_password = ? WHERE account_id = ?");
        query.addBindValue(account.getPassword());
        query.addBindValue(account.getId());
        if (query.exec()){
            db.commit();
            return true;
        }else{
            db.rollback();
            account.changePassword(newPassword,oldPassword);
            return false;

        }
    }else{
        return false;
    }
}

bool AtmSystem::createCard(const QString& cardNumber, const QString& password){
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE card_number = ?");
    query.addBindValue(cardNumber);
    if(query.next()){
        return false;
    }

    Account a;
    a.setAccount(cardNumber,password,0);


    db.transaction();

    query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                  "VALUES (?, ?, ?)");
    query.addBindValue(a.getCardNumber());
    query.addBindValue(a.getPassword());
    query.addBindValue(a.getBalance());
    if (query.exec()){
        db.commit();
        return true;
    }else{
        db.rollback();
        return false;

    }
}

bool AtmSystem::destroyAccount(const QString& cardNumber, const QString& password){

    QSqlQuery query;

    query.prepare("SELECT * FROM Accounts WHERE card_number = ?");
    query.addBindValue(cardNumber);
    query.exec();
    if(query.next()){
        Account a(query.value(0).toInt(),
                  query.value(1).toString(),
                  query.value(2).toString(),
                  query.value(3).toUInt());
        if(a.validatePassword(password)){
            db.transaction();
            query.prepare("DELETE FROM Accounts WHERE card_number = ?");
            query.addBindValue(cardNumber);

            if(query.exec()){
                db.commit();
                return true;
            }else{
                db.rollback();
                return false;
            }
            return false;
        }else{
            return false;
        }
    }else{
        return false;
    }


}
