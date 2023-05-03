#pragma once
#ifndef MAGICIAN_H
#define MAGICIAN_H
#include "role.h"
using namespace std;
class Magician : public Role {
public:
	Magician(const string inID, const int inlevel, const int inmoney, const int inhp) {
		ID = inID;
		level = inlevel;
		money = inmoney;
		hp = inhp;
	};
	/*~Magician() {
		ID = nullptr;
		level = 0;
		money = 0;
		hp = 0;
	};*/
	
	virtual void ShowRole() const {
		cout << ID << " is Magician \n";
	};
};

#endif // !MAGICIAN_H
