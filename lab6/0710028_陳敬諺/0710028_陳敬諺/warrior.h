#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include"role.h"
using namespace std;

class Warrior: public Role
{
public:
	Warrior(const string inID, const int inlevel, const int inmoney, const int inhp) {
		ID = inID;
		level = inlevel;
		money = inmoney;
		hp = inhp;
	};
	/*~Warrior() {
		ID = nullptr;
		level = 0;
		money = 0;
		hp = 0;
	};*/

	virtual void ShowRole() const {
		cout << ID << " is Warrior \n";
	};

};

#endif // !WARRIOR_H
