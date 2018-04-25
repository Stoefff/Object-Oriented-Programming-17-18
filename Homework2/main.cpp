#include <iostream>
#include "Text.h"
#include "HelperFuntions.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	char command[64];
	char filename[256];
	cout << "Please enter a filename: ";
	cin >> filename;
	while (!doesFileExits(filename)) {
		cin >> filename;
	}
	int arg1, arg2, arg3;
	char lineContent[maxLineSize];
	Text text(filename);
	while (true) {
		cout << "Enter command: ";
		cin >> command;
		if (!myStricmp(command, "makeHeading")) {
			cin >> arg1;
			text.makeHeading(arg1-1); //Because programmers count from 0
		} else if(!myStricmp(command, "makeItalic")) {
			cin >> arg1;
			cin >> arg2;
			cin >> arg3;
			text.makeWordItallic(arg1-1, arg2-1, arg3-1);
		} else if (!myStricmp(command, "makeBold")) {
			cin >> arg1;
			cin >> arg2;
			cin >> arg3;
			text.makeWordBold(arg1-1, arg2-1, arg3-1);
		} else if (!myStricmp(command, "makeCombine")) {
			cin >> arg1;
			cin >> arg2;
			cin >> arg3;
			text.makeWordCombined(arg1-1, arg2-1, arg3-1);
		} else if (!myStricmp(command, "addLine")) {
			cin.ignore();
			cin.getline(lineContent, maxLineSize);
			text.addLine(lineContent);
		} else if (!myStricmp(command, "remove")) {
			cin >> arg1;
			text.deleteLine(arg1-1);
		} else if (!myStricmp(command, "exit")) {
			break;
		} else {
			cout << "Invalid command, enter a new one: " << endl;
			cin.ignore();
		}
	}

	return 0;
}