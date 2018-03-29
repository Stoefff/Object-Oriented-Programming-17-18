#ifndef __WALLET__HEADER__INCLUDED__
#define __WALLET__HEADER__INCLUDED__
#include "ID.h"

const short maxOwnerLength = 256;

struct Wallet {
    char owner[maxOwnerLength];
    uint id;
    double fiatMoney;
};

void serializeWallet(const Wallet&);

bool deserializeWalletByID(Wallet&);

bool deserializeWalletByName(Wallet&);

double walletCurrentCoins(const Wallet&);

void createWallet();



#endif
