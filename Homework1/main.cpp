////////////////////////
// Compiled using g++ 5.4.0 on Ubuntu 16.04 64 bit like:
// $ g++ main.cpp HelperFunctions.cpp ID.cpp Wallet.cpp Transaction.cpp Order.cpp
// BTW I underestimated the task so now its 23:40 and i know exactly how to
// complete it but the i cant write in time the remaining code :)
////////////////////////
#include <iostream>
#include <string.h>
#include "Wallet.h"
#include "Order.h"
#include "ID.h"
#include "HelperFunctions.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    initilizeID();
    char command[32];
    while(true){
        cin >> command;
        if(!myStricmp(command, "add-wallet")){
            createWallet();
        } else if (!myStricmp(command, "make-order")){
            createOrder();
        } else if (!myStricmp(command, "wallet-info")){

        } else if (!myStricmp(command, "attract-ivestors")){

        } else if (!myStricmp(command, "quit")){
            break;
        } else {
            cout << "Invalid command, enter a new one: " << endl;
        }
    }
    saveLastID();
    return 0;
}
