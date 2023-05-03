#pragma once
#ifndef ROLE_H
#define ROLE_H
#include<string>
#include<iostream>
using namespace std;
class Role
{
public:
	Role();
	Role(const string inID,const int inlevel,const int inmoney,const int inhp);
	~Role();
	void printAllInfo();
	virtual void ShowRole() const =0;
	string getID();

protected:
	string ID;
	int level;
	int money;
	int hp;
};

Role::Role() {
	ID = "NONE";
	level = 0;
	money = 0;
	hp = 0;
}

Role::Role(const string inID, const int inlevel, const int inmoney, const int inhp)
{
	ID = inID;
	level = inlevel;
	money = inmoney;
	hp = inhp;
}

Role::~Role()
{
	ID = "\0";
	level = 0;
	money = 0;
	hp = 0;
}

void Role::printAllInfo() {
	cout << "ID is : " << ID << ".\n" << "Level is : " << level << ".\n" << "Money is : " << money << ".\n" << "Hp is : " << hp << ".\n";
}

string Role::getID() {
	return ID;
}
#endif // !ROLE_H

