#include "role.h"
#include "magician.h"
#include "warrior.h"
#include "archer.h"
#include "staff.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Role* warrior = new Warrior("Steve", 1, 1987, 200);
	warrior->printAllInfo();
	warrior->ShowRole();
	cout << endl;

	Role* archer = new Archer("Legolas", 99, 99999, 6000);
	archer->printAllInfo();
	archer->ShowRole();
	cout << endl;

	Role* magician = new Magician("Lisa", 15, 981, 145);
	magician->printAllInfo();
	magician->ShowRole();
	cout << endl;
	
	Staff* staff = new Staff("flame");
	cout << "Checking whether the role can equip a staff.." << endl;
	staff->equipable(warrior);
	staff->equipable(archer);
	staff->equipable(magician);
	cout << endl;




	system("PAUSE");
	return 0;
}