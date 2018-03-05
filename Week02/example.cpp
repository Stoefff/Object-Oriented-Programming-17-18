#include <iostream>
#include <fstream>

int main(){
    std::ofstream file; // var of type file
    file.open("example.txt"); // read from file
    //file.open("example.txt", ios::out | ios::app);
    // There are many flags for open();
    // if open an non existing file - it is created
    file << "File area cool\n"; // << are defined only for text files
    file.close();
    return 0;
}
