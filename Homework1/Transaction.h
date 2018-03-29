#ifndef __TRANSACTION__HEADER__INCLUDED__
#define __TRANSACTION__HEADER__INCLUDED__
#include "ID.h"

struct Transaction {
    long long time;
    uint senderId;
    uint receiverId;
    double fmiCoins;
};

double convertToFmiCoin(const double);

double convertToLeva(const double);

void serializeTransaction(const Transaction&);

bool deserializeTransationByRecID(Transaction&);

bool deserializeTransationBySendID(Transaction&);

size_t transactionCountByID(const uint ID);

bool deserializeArrayOfTransByID(const uint, Transaction*);

void createTransaction(const uint, const uint, const double);


#endif
