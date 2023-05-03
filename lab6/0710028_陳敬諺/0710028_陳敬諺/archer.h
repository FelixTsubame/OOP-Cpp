#pragma once
#ifndef ARCHER_H
#define ARCHER_H
#include "role.h"
using namespace std;
class Archer : public Role {
public:
	Archer(const string inID, const int inlevel, const int inmoney, const int inhp) {
		ID = inID;
		level = inlevel;
		money = inmoney;
		hp = inhp;
	};
	/*~Archer() {
		ID = nullptr;
		level = 0;
		money = 0;
		hp = 0;
	};*/

	virtual void ShowRole() const{
		cout << ID << " is Archer \n";
	};
};

#endif // !ARCHER_H

