#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"
#include "ID.h"
#include "HelperFunctions.h"
#include "Transaction.h"
#include "Order.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::cerr;
using std::ios;

const char* ordersFileName = "orders.dat";
const char* types[2] = {"SELL", "BUY"};

void serializeOrder(const Order& order){
    ofstream file (ordersFileName, ios::binary | ios::app);
    if(!file.good()){
        cerr << ordersFileName << " write stream failed!" << endl;
        return;
    }
    file.write((char*)&order, sizeof(order));
    file.close();
}


// Cant think of any better name for this function
// Finds the first BUY order which can match with the given SELL order
bool deserializeMatchingBuyOrder(const Order& sellOrder, Order& order){
    ifstream file (ordersFileName, ios::binary);
    if(!file.good()){
        cerr << ordersFileName << " read stream failed!" << endl;
        return false;
    }
    Order temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.type == Order::BUY){
            if(compareFloat(temp.fmiCoins, sellOrder.fmiCoins) == 0 ||
            compareFloat(temp.fmiCoins, sellOrder.fmiCoins) == -1){
                    order = temp;
            }
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool deleteSerializedOrder(Order order){
    ifstream file (ordersFileName, ios::binary);
    if(!file.good()){
        cerr << ordersFileName << " read stream failed!" << endl;
        return false;
    }
    Order temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.type == order.type &&
        temp.walletId == order.walletId &&
        compareFloat(temp.fmiCoins, order.fmiCoins) == 0){

            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool isSellOrderValid(const Order& order){
    Wallet wallet;
    wallet.id = order.walletId;
    if(!deserializeWalletByID(wallet)){
        return false;
    }
    if(compareFloat(order.fmiCoins, walletCurrentCoins(wallet)) == 1){ // compare using EPS
        return false;
    }
    return true;
}

bool isBuyOrderValid(const Order& order){
    Wallet wallet;
    wallet.id = order.walletId;
    if(!deserializeWalletByID(wallet)){
        return false;
    }
    if(compareFloat(order.fmiCoins, convertToFmiCoin(wallet.fiatMoney)) == 1){
        return false;
    }
    return true;
}

void makeSellOrder(Order& sellOrder){
    Order buyOrder;
    while(deserializeMatchingBuyOrder(sellOrder, buyOrder) &&
    compareFloat(sellOrder.fmiCoins, 0.0) != 0){
        sellOrder.fmiCoins -= buyOrder.fmiCoins;
        deleteSerializedOrder(buyOrder);
        createTransaction(sellOrder.walletId, buyOrder.walletId, buyOrder.fmiCoins);
    } if(compareFloat(sellOrder.fmiCoins, 0.0) != 0){
        serializeOrder(sellOrder);
    }
}

void makeBuyOrder(Order& order){

}

//Not completed
void createOrder(){
    bool isInvalid = true;
    while (isInvalid){
        isInvalid = false;
        Order order;
        char type[8];
        cin >> type;
        if(!myStricmp(type, "BUY")){
            order.type = Order::BUY;
        } else if(!myStricmp(type, "SELL")){
            order.type = Order::SELL;
        } else {
            isInvalid = true;
            cout << "You have enter Invalid type" << endl;
            continue;
        }
        cin >> order.fmiCoins;
        cin >> order.walletId;
        if(order.type == Order::SELL){
            if(isSellOrderValid(order)){
                makeSellOrder(order);
            } else {
                isInvalid = true;
                continue;
            }
        } else if(isBuyOrderValid(order)){
            makeBuyOrder(order);
        } else {
            isInvalid = true;
            continue;
        }
    }
}
