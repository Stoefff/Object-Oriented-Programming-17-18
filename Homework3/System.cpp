#include "System.h"
#include <iostream>
#include "HelperFunctions.h"

using std::cin;
using std::cout;
using std::endl;

System::System() {
	pC = &PostCollection::getInstance();
	uC = &UserCollection::getInstance();
}

System& System::getInstance() {
	static System instance;
	return instance;
}

System::~System() {
	delete pC;
	delete uC;
}

void System::run() {
	// Its 00:54 and i have no time to make them dynamic :(
	char arg1[128];
	char arg2[32];
	char arg3[128];
	char arg4[512];
	char arg5[512];
	while (true) {
		cin >> arg1 >> arg2 >> arg2;
		if (!_stricmp(arg1, "info")) {
			// get info
			continue;
		}
		else if (!_stricmp(arg1, "quit")) {
			break;
		}
		else if (!_stricmp(arg2, "add_user")) {
			cin >> arg4;
			uC->addUser(arg1, arg3, charToInt(arg4));
		}
		else if (!_stricmp(arg2, "add_moderator")) {
			cin >> arg4;
			uC->addMod(arg1, arg3, charToInt(arg4));
		}
		else if (!_stricmp(arg2, "remove_user")) {
			uC->removePerson(arg1, arg3);
		}
		else if (!_stricmp(arg2, "rename")) {
			uC->rename(arg1, arg3);
		}
		else if (!_stricmp(arg2, "block")) {
			uC->blockUser(arg1, arg3);
		}
		else if (!_stricmp(arg2, "unblock")) {
			uC->unblockUser(arg1, arg3);
		}
		else if (!_stricmp(arg2, "post")) {
			if (!_stricmp(arg3, "[image]")) {
				cin.ignore();
				cin.getline(arg4, 512);
				Picture* temp = new Picture(arg4);
				pC->addPost(temp);
				// What happens when ^ fails :(
				// No time to correct this wrong behavior
				uC->addPost(arg1, temp->getID());
				delete temp;
			}
			else if (!_stricmp(arg3, "[url]")) {
				cin >> arg4;
				cin.ignore();
				cin.getline(arg5, 512);
				Link* temp = new Link(arg4, arg5);
				pC->addPost(temp);
				uC->addPost(arg1, temp->getID());
				delete temp;
			}
			else if (!_stricmp(arg3, "[text]")) {
				cin.ignore();
				cin.getline(arg4, 512);
				Text* temp = new Text(arg4);
				pC->addPost(temp);
				uC->addPost(arg1, temp->getID());
				delete temp;
			}
		}
		else if (!_stricmp(arg2, "remove_post")) {
			pC->removePost(charToInt(arg3));
			uC->removePost(arg1, charToInt(arg3));
		}
		else if (!_stricmp(arg2, "view_post")) {
			if (uC->isUserNameTaken(arg1)) {
				pC->viewPost(charToInt(arg3), arg1);
			}
		}
		else if (!_stricmp(arg2, "view_all_posts")) {
			if (uC->isUserNameTaken(arg1)) {
				if (uC->isUserNameTaken(arg3)) {
					//
				}
			}
		} 
		else {
			cout << "No such command!" << endl;
		}
	}
}