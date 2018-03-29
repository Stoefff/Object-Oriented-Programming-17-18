#include <iostream>
#include "HelperFunctions.h"
#include "math.h"

using std::cin;

const double EPS = 0.0001;

// Copied from Vasi's code
void readName(char* name, unsigned short size){
	while (cin && isspace(cin.peek()))
		cin.ignore();
	cin.getline(name, size);
	if (cin.fail())
	{
		cin.clear();
		while (cin && '\n' != cin.get());
	}
	cin.clear();
}

// There is no standart stricmp() in linux so i decided write cause
// Because linux's strcasecmp() doesn't work on windows :)
int myStricmp(const char * str1, const char * str2) {
	while (*str1 != '\0' && (tolower(*str1) == tolower(*str2))) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int compareFloat(const double num1, const double num2){
	if(fabs(num1 - num2) <= EPS){
		return 0; // num1 == num2
	} else if(num1 > num2){
		return 1; // num1 > num2
	} else {
		return -1; // num1 < num2
	}
}
