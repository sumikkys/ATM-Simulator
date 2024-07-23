/**
 * @file atmsystem.cpp
 * @brief ATM系统的实现，主要负责数据库操作
 */


#include "atmsystem.h"
#include "account.h"

/**
 * @brief 构造函数
 */
AtmSystem::AtmSystem() : account(), db(){}

/**
 * @brief AtmSystem::init 初始化函数，建立数据库连接
 *
 * 建立数据库连接，创建数据库表，设置默认初始账号
 *
 * @return
 */
bool AtmSystem::init(){

    // 建立数据库连接
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./atm_system.db");

    if (!db.open()) {
        qWarning() << "无法打开数据库:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;

    // 建立表
    query.exec("CREATE TABLE IF NOT EXISTS Accounts ("
               "account_id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "card_number TEXT UNIQUE NOT NULL,"
               "hashed_password TEXT NOT NULL,"
               "balance INTEGER NOT NULL CHECK (balance >= 0)"
               ");");

    // 查询初始账号是否存在，不存在则创建初始账号
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


/**
 * @brief AtmSystem::login 登陆函数，查询数据库，成功登陆后创建account
 * @param cardNumber 用户提供的卡号
 * @param password 用户提供的密码
 * @return 登陆是否成功的布尔值
 */
bool AtmSystem::login(const QString& cardNumber, const QString& password){

    // 查询数据库中是否有符合用户输入的卡号与密码
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE card_number = ? AND hashed_password = ?");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));
    query.exec();

    if(!query.next()){
        return false;
    }else{
        // 有则创建与数据库中数据对应的account作为当前登陆账户
        Account a(query.value(0).toInt(),
                  query.value(1).toString(),
                  query.value(2).toString(),
                  query.value(3).toUInt());
        account = a;
        return true;
    }
}

/**
 * @brief AtmSystem::checkCardNumber 返回当前账户的卡号
 *
 * @return 当前账户的卡号
 */
QString AtmSystem::checkCardNumber() const{
    return account.getCardNumber();
}

/**
 * @brief AtmSystem::checkBalance 查询并返回当前账户的余额
 *
 * @return 当前账户的余额
 */
unsigned int AtmSystem::checkBalance(){

    // 在数据库中查询当前账户余额
    QSqlQuery query;
    query.prepare("SELECT balance FROM Accounts WHERE card_number = ?");
    query.addBindValue(account.getCardNumber());
    query.exec();
    query.next();
    unsigned int dataBalance = query.value(0).toUInt();
    if(dataBalance == account.getBalance()){ // 数据库中数据与内存数据一致时直接返回
        return account.getBalance();
    }else{ // 数据库中数据与内存数据不一致时更新内存数据后返回
        account.setBalance(dataBalance);
        return dataBalance;
    }
}

/**
 * @brief AtmSystem::deposit 存款函数，更新数据库
 * @param amount 用户提供的存款金额
 * @return 存款是否成功的布尔值
 */
bool AtmSystem::deposit(unsigned int amount){

    // 在数据库中更新当前账户余额
    QSqlQuery query;
    db.transaction(); // 事务
    query.prepare("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    query.addBindValue(amount);
    query.addBindValue(account.getId());
    if (query.exec()){
        db.commit();
        account.deposit(amount);
        return true;
    }else{
        // 更新数据失败则回滚
        db.rollback();
        return false;

    }
}

/**
 * @brief AtmSystem::withdraw 取款函数，更新数据库
 * @param amount 用户提供的取款金额
 * @return 取款是否成功的布尔值
 */
bool AtmSystem::withdraw(unsigned int amount){

    QSqlQuery query;
    db.transaction(); // 事务

    // 在数据库中更新当前账户余额
    query.prepare("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
    query.addBindValue(amount);
    query.addBindValue(account.getId());
    if (query.exec()){
        db.commit();
        account.withdraw(amount);
        return true;
    }else{
        // 更新数据失败则回滚
        db.rollback();
        return false;

    }
}

/**
 * @brief AtmSystem::transfer 转账函数，查询同时更新数据库
 * @param targetCard 用户提供的目标卡号
 * @param amount 用户提供的转账金额
 * @return 转账是否成功的布尔值
 */
bool AtmSystem::transfer(const QString& targetCard, unsigned int amount){
    //在数据库中查询指定账户卡号是否存在
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
        db.transaction(); // 事务

        // 在数据库中更新对应账户余额
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
            // 更新数据失败则回滚
            db.rollback();
            return false;
        }
    }
    return false;
}

/**
 * @brief AtmSystem::changePassword 修改密码函数，更新数据库
 * @param oldPassword 用户提供的旧密码
 * @param newPassword 用户提供的新密码
 * @return 修改密码是否成功的布尔值
 */
bool AtmSystem::changePassword(const QString& oldPassword, const QString& newPassword){

    if(account.changePassword(oldPassword,newPassword)){ // 根据Account::changePassword返回结果更新数据库
        QSqlQuery query;
        db.transaction(); // 事务
        // 在数据库中更新当前账户密码
        query.prepare("UPDATE Accounts SET hashed_password = ? WHERE account_id = ?");
        query.addBindValue(hashPassword(newPassword));
        query.addBindValue(account.getId());
        if (query.exec()){
            db.commit();
            return true;
        }else{
            // 更新数据失败则回滚
            db.rollback();
            account.changePassword(newPassword,oldPassword);
            return false;

        }
    }else{
        return false;
    }
}

/**
 * @brief AtmSystem::createCard 开卡函数，查询并向数据库插入记录
 * @param cardNumber 用户提供的卡号
 * @param password 用户提供的密码
 * @return 开卡是否成功的布尔值
 */
bool AtmSystem::createCard(const QString& cardNumber, const QString& password){
    QSqlQuery query;

    //在数据库中查询指定账户卡号是否存在
    query.prepare("SELECT * FROM Accounts WHERE card_number = ?");
    query.addBindValue(cardNumber);
    if(query.next()){
        return false;
    }

    db.transaction(); // 事务

    // 在数据库中插入新账户记录
    query.prepare("INSERT INTO Accounts (card_number, hashed_password, balance) "
                  "VALUES (?, ?, ?)");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));
    query.addBindValue(0);
    if (query.exec()){
        db.commit();
        return true;
    }else{
        // 插入数据失败则回滚
        db.rollback();
        return false;

    }
}

/**
 * @brief AtmSystem::destroyAccount 销户函数，从数据库中删除记录
 * @param cardNumber 用户提供的卡号
 * @param password 用户提供的密码
 * @return 销户是否成功的布尔值
 */
bool AtmSystem::destroyAccount(const QString& cardNumber, const QString& password){

    QSqlQuery query;

    db.transaction(); // 事务

    // 在数据库中删除对应账户记录
    query.prepare("DELETE FROM Accounts WHERE card_number = ? AND hashed_password = ?");
    query.addBindValue(cardNumber);
    query.addBindValue(hashPassword(password));

    if(query.exec() && query.numRowsAffected()!=0){ // 影响行数不为0即有与之对应的记录则删除成功
        db.commit();
        return true;
    }else{
        // 删除数据失败则回滚
        db.rollback();
        return false;
    }
}

/**
 * @brief AtmSystem::hashPassword 哈希密码函数，用于加密密码
 * @param password 需要加密的密码
 * @return 加密后的密码
 */
QString AtmSystem::hashPassword(const QString& password) const {
    QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256); // Sha256加密算法
    return QString(byteArray.toHex()); // 转换为16进制字符串后返回
}
