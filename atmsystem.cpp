#include "atmsystem.h"
#include "account.h"

AtmSystem::AtmSystem() : account("123456", "123456", 1000000) {}

bool AtmSystem::login(const QString& cardNumber, const QString& password){
    return account.login(cardNumber,password);
}

unsigned int AtmSystem::checkBalance(){
    return account.getBalance();
}
