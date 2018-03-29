#include <iostream>
#include <fstream>
#include <ctime>
#include "Transaction.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::cerr;
using std::ios;

const short course = 375;
const char* transFileName = "transactions.dat";

void serializeTransaction(const Transaction& tran){
    ofstream file (transFileName, ios::binary | ios::app);
    if(!file.good()){
        cerr << transFileName << " write stream failed!" << endl;
        return;
    }
    file.write((char*)&tran, sizeof(tran));
    file.close();
}

bool deserializeTransationByRecID(Transaction& tran){
    ifstream file (transFileName, ios::binary);
    if(!file.good()){
        cerr << transFileName << " read stream failed!" << endl;
        return false;
    }
    Transaction temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.receiverId == tran.receiverId){
            tran = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
//Wanted to merge this 2 fucntions but i thinks its better this way
bool deserializeTransationBySendID(Transaction& tran){
    ifstream file (transFileName, ios::binary);
    if(!file.good()){
        cerr << transFileName << " read stream failed!" << endl;
        return false;
    }
    Transaction temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.senderId == tran.senderId){
            tran = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

size_t transactionCountByID(const uint ID){
    ifstream file (transFileName, ios::binary);
    if(!file.good()){
        cerr << transFileName << " read stream failed!" << endl;
    }
    size_t count = 0;
    Transaction temp;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.senderId == ID || temp.receiverId == ID ){
            count++;
        }
    }
    file.close();
    return count;
}

bool deserializeArrayOfTransByID(const uint ID, Transaction* tranArr){
    ifstream file (transFileName, ios::binary);
    if(!file.good()){
        cerr << transFileName << " read stream failed!" << endl;
        return false;
    }
    Transaction temp;
    size_t count = 0;
    while(!file.eof()){
        if(file.eof()){ // Is this really necessary
            break;
        }
        file.read((char*)&temp, sizeof(temp));
        if(temp.receiverId == ID || temp.senderId == ID ){
            tranArr[count++] = temp;
        }
    }
    file.close();
    if(count == 0){ return false; }
    else { return true; }
}


double convertToFmiCoin(const double money){
    return money / course;
}

double convertToLeva(const double fmiCoins){
    return fmiCoins * course;
}

void createTransaction(const uint senderId, const uint receiverId, const double fmiCoins){
    Transaction tran;
    tran.senderId = senderId;
    tran.receiverId = receiverId;
    tran.fmiCoins = fmiCoins;
    tran.time = (long long)(time(NULL));
    serializeTransaction(tran);
}
