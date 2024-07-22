#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : account("123456", "123456", 1000000) {}

bool AtmSystem::login(const QString& cardNumber, const QString& password){
    return account.login(cardNumber,password);
}

QString AtmSystem::checkCardNumber(){
    return account.getCardNumber();
}

unsigned int AtmSystem::checkBalance(){
    return account.getBalance();
}

void AtmSystem::deposit(unsigned int amount){
    account.deposit(amount);
}

void AtmSystem::withdraw(unsigned int amount){
    account.withdraw(amount);
}
