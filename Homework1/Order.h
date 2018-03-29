#ifndef __ORDER__HEADER__INCLUDED__
#define __ORDER__HEADER__INCLUDED__
#include "ID.h"

struct Order {
    enum Type {INVALID = -1, SELL, BUY } type;
    uint walletId;
    double fmiCoins;
};

void serializeOrder(const Order&);

void deserializeOrder();

bool isSellOrderValid(const Order&);

bool isBuyOrderValid();

void createOrder();

#endif
