#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"
#include "ID.h"
#include "HelperFunctions.h"
#include "Transaction.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::cerr;
using std::ios;

const uint systemWalletID = 4294967295;// = -1 maybe ??
const char* walletsFileName = "wallets.dat";

void serializeWallet(const Wallet& wallet){
    ofstream file (walletsFileName, ios::binary | ios::app);
    if(!file.good()){
        cerr << walletsFileName << " write stream failed!" << endl;
        return;
    }
    file.write((char*)&wallet, sizeof(wallet));
    file.close();
}
bool deserializeWalletByID(Wallet& wallet){
    ifstream file (walletsFileName, ios::binary);
    if(!file.good()){
        cerr << walletsFileName << " read stream failed!" << endl;
        return false;
    }
    Wallet temp;
    while(!file.eof()){
        file.read((char*)&temp, sizeof(temp));
        if(temp.id == wallet.id){
            wallet = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool deserializeWalletByName(Wallet& wallet){
    ifstream file (walletsFileName, ios::binary);
    if(!file.good()){
        cerr << walletsFileName << " read stream failed!" << endl;
        return false;
    }
    Wallet temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessery
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(strcmp(wallet.owner, temp.owner)){
            wallet = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

double walletCurrentCoins(const Wallet& wallet){
    size_t arrSize = transactionCountByID(wallet.id);
    Transaction* tranArr = new (std::nothrow) Transaction[arrSize];
    double count = 0.0;
    if(!deserializeArrayOfTransByID(wallet.id, tranArr)){
    //    cout << "No transaction with that ID were found" << endl;
    // return 0;
    }
    for (int i = 0; i < arrSize; i++){
        if(tranArr[i].receiverId == wallet.id){
            count += tranArr[i].fmiCoins;
        } else { // else (tranArr[i].senderId == wallet.id) == true
            count -= tranArr[i].fmiCoins;
        }
    }
    delete[] tranArr;
    return count;
}

void createWallet(){
    Wallet wallet;
    cin >> wallet.fiatMoney;
    readName(wallet.owner, maxOwnerLength);
    wallet.id = getAndIncrementID();
    createTransaction(systemWalletID, wallet.id, convertToFmiCoin(wallet.fiatMoney));
    serializeWallet(wallet);
}
