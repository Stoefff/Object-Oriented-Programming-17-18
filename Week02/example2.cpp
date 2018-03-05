#include <iostream>
#include <fstream>

int main(){
    std::ifstream file ("example.txt"); // saved us one row of writing same as ^
    // We should always if the opening of a files is valid
    if (! file.good() ){ // there are also bad(), fail(), eof()
        std::cerr << "Could not open files"; // cerr - standart error
        return -1;
    }
    char buff[256];
    // getline return how many symbols are read, return negative num when error
    while (file.getline(buff, 256) ){
        file >> buff;
        std::cout << buff << std::endl; // Catches to space !!
    }
    file.close();
    return 0;
}
