#include "HelperFunctions.h"
#include "Math.h"

char* size_t_to_char(size_t num) {
	size_t digitCounter = 1;
	size_t num1 = num;
	while ((num1 / 10) != 0) {
		num1 /= 10;
		digitCounter++;
	}
	char* number = new char[digitCounter + 1]; // +1 for \0
	for (int i = 0, j = digitCounter - 1; i < digitCounter; i++, j--) {
		number[i] = '0' + (num / pow(10, j));
		num %= (int)pow(10, j);
	}
	number[digitCounter] = '\0';
	return number;
}

int charToInt(const char* str) {
	int counter = 0;
	const char* strItt = str;
	while (*strItt != '\0') {
		counter++;
		strItt++;
	}
	int num = 0;
	strItt = str;
	while (*strItt != '\0') {
		counter--;
		num += (*strItt - '0') * (int)pow(10, counter);
		strItt++;
	}
	return num;
}