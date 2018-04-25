#include "HelperFuntions.h"
#include <iostream>
#include <fstream>

bool isWhitespace(const char sym) {
	if ((sym == ' ') || (sym == '\t')
		|| (sym == '\n') || (sym == '\0')) {
		return true;
	}
	else { return false; }
}

size_t countWords(const char* str) {
	size_t count = 0;
	while (*str != '\0') {
		if ((isWhitespace(*str) == false)
			&& (isWhitespace(*(str + 1)) == true)) { //Possible problems here
			count++;
		}
		str++;
	}
	return count;
}

int myStricmp(const char * str1, const char * str2) {
	while (*str1 != '\0' && (tolower(*str1) == tolower(*str2))) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

bool doesFileExits(const char* filename) {
	std::ifstream file(filename, std::ios::in);
	if (!file.good()) {
		std::cerr << "No such file present!?" << std::endl;
		return false;
	} else {
		return true;
	}
}