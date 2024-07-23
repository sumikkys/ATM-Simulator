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

    query.exec("SELECT * FROM Accounts WHERE card_number = '123456'");
    if(!query.next()){
        query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                      "VALUES (?, ?, ?)");
        query.addBindValue("123456");
        query.addBindValue(hashPassword("123456"));
        query.addBindValue(1000000);
        query.exec();
    }
        return true;
}


// 登陆
bool AtmSystem::login(const QString& cardNumber, const QString& password){
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE card_number = ? AND hashed_password = ?");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));
    query.exec();
    if(!query.next()){
        return false;
    }else{
        Account a(query.value(0).toInt(),
                  query.value(1).toString(),
                  query.value(2).toString(),
                  query.value(3).toUInt());
        account = a;
        return true;
    }
}

// 返回卡号
QString AtmSystem::checkCardNumber() const{
    return account.getCardNumber();
}

// 返回余额
unsigned int AtmSystem::checkBalance(){
    QSqlQuery query;
    query.prepare("SELECT balance FROM Accounts WHERE card_number = ?");
    query.addBindValue(account.getCardNumber());
    query.exec();
    query.next();
    unsigned int dataBalance = query.value(0).toUInt();
    if(dataBalance == account.getBalance()){
        return account.getBalance();
    }else{
        account.setBalance(dataBalance);
        return dataBalance;
    }
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
        query.addBindValue(hashPassword(newPassword));
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

// 开卡
bool AtmSystem::createCard(const QString& cardNumber, const QString& password){
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE card_number = ?");
    query.addBindValue(cardNumber);
    if(query.next()){
        return false;
    }

    db.transaction();

    query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                  "VALUES (?, ?, ?)");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));
    query.addBindValue(0);
    if (query.exec()){
        db.commit();
        return true;
    }else{
        db.rollback();
        return false;

    }
}

// 销户
bool AtmSystem::destroyAccount(const QString& cardNumber, const QString& password){

    QSqlQuery query;

    db.transaction();
    query.prepare("DELETE FROM Accounts WHERE card_number = ? AND hashed_password = ?");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));

    if(query.exec() && query.numRowsAffected()!=0){
        db.commit();
        return true;
    }else{
        db.rollback();
        return false;
    }
}

// 哈希密码
QString AtmSystem::hashPassword(const QString& password) const {
    QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(byteArray.toHex());
}
