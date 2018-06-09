/*
		TODO: Make the code compilable on g++ xDDD
		For now it only compiles in Visual Studio
*/
#include <iostream>
#include "System.h"
#include "PostCollection.h"
#include "User.h"
#include "Mod.h"
#include "Admin.h"
#include "HelperFunctions.h"


using std::cout;
using std::cin;
using std::endl;

int main() {

	System* sys = &System::getInstance();
	sys->run();
	delete sys;

	// Test for User, Mod, Admin show they work perfectly

/*
	Admin* admin = Admin::getInstance("admin", 19);
	User** userColl = new User*[3];
	userColl[0] = admin->addUser("pesho", 20);
	userColl[1] = admin->addUser("goshe", 21);
	Mod** modColl = new Mod*[2];
	modColl[0] = admin->addMod("Zlaten", 22);
	modColl[1] = admin->addMod("Toto", 23);

	userColl[0]->addPost(3);
	userColl[0]->addPost(4);
	userColl[0]->addPost(5);

	userColl[0]->removeOwnPost(5);
	userColl[0]->removeOwnPost(4);
	modColl[0]->removePost(userColl[0], 3);

	modColl[0]->blockUser(userColl[1]);
	modColl[0]->unblockUser(userColl[1]);

	modColl[1]->rename("Antonio");

	userColl[0] = admin->removeUser(userColl[0]);
	userColl[1] = admin->removeUser(userColl[1]);
	modColl[0] = admin->removeMod(modColl[0]);
	modColl[1] = admin->removeMod(modColl[1]);

	delete admin;

*/

	// !!! This(PostCollection) works perfectly !!!

	//coll[0] = Admin::getInstance("admin", 19);
	//coll[1] = coll[0]->addMod("Pesho", 20);



/*
	PostCollection* coll = &PostCollection::getInstance();
	Post* pic = new Picture("maxresdefault.jpg");
	Post* text = new Text("Dab memes");
	Post* link = new Link("https://www.youtube.com/", "YouTube");

	coll->addPost(pic);
	coll->addPost(text);
	coll->addPost(link);
	coll->addPost(pic);

	size_t size = coll->getSize();

	for (int i = 0; i < size; i++) {
		coll->viewPost(i, "Juli");
	}
*/

	return 0;
}
