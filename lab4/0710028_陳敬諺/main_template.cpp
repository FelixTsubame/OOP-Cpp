#include <iostream>
#include <string>
using namespace std;

class Test {
public:
	string my_name;
	/* Add code here */
	Test(const string s) {
		my_name = s;
		cout << "born " << my_name << "\n";
	}
	~Test() {
		cout << "dead " << my_name << "\n";;
	}
};

Test G("G");

void foo() {
	Test D("D");
}

void main_to_see_stop() {
	/* Add code here */
	Test A("A");
	static Test E("E");
	Test B("B");
	foo();
	Test C("C");
}

void construct_by(int i) {
	Test temp(to_string(i));
}

void num() {
	/* Add code here */
	Test F("F");
	int i = 0;
	while (i < 3) {
		/* Add code here */
		construct_by(i);
		i++;
	}
}

int main() {
	main_to_see_stop(); // Don't modify this
	num();
	cout << "After main" << endl;
}