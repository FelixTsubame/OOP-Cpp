#pragma once
#ifndef STAFF_H
#include "role.h"
#include "magician.h"
#include <string>
using namespace std;

class Staff {
public:
	Staff(string staffName) :name(staffName), damage(10) {

	}
	bool equipable(Role* role) {
		if (isMagician(role))
		{
			cout << role->getID() << " can equip this staff.\n";
			return true;
		}
		else
		{
			cout << "bad cast.\n";
			return false;
		}
		
		// use isMagician to check whether the role can equip the staff.
	}

private:
	string name;
	int damage;
	bool isMagician(Role* role) {
		Magician *magician = dynamic_cast<Magician*>(role);
		if(magician!=NULL) {
			//Magician magician = dynamic_cast<Magician&>(*role);
			cout << role->getID() << " is a magician.\n";
			return true;
		}
		else
		{
			//cout << "bad cast.\n";
			return false;
		}
		// use dynamic casting to check whether the role is a magician. 
		
	}
};
#endif
