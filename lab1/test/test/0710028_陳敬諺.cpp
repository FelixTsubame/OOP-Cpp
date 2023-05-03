#include <iostream>
#include <string>

using namespace std;

class com_num {
public:
	double real;
	double imag;
};


int main() {

	int t;
	cin >> t;
	while (t--) {
		com_num a, b;
		char command;
		cin >> command;
		string output;
		double tempar;
		double tempai;
		switch (command)
		{
		case 'p':
			cin >> a.real >> a.imag;
			if (a.imag == 0)
				output = to_string(a.real);
			else if (a.real == 0)
				output = to_string(a.imag) + "i";
			else if(a.imag < 0)
				output = to_string(a.real) + to_string(a.imag) + "i";
			else
				output = to_string(a.real) + "+" + to_string(a.imag) + "i";
			cout << output << "\n";
			break;
		case '+':
			cin >> a.real >> a.imag >> b.real >> b.imag;
			a.real += b.real;
			a.imag += b.imag;
			if (a.imag == 0)
				output = to_string(a.real);
			else if (a.real == 0)
				output = to_string(a.imag) + "i";
			else if (a.imag < 0)
				output = to_string(a.real) + to_string(a.imag) + "i";
			else
				output = to_string(a.real) + "+" + to_string(a.imag) + "i";
			cout << output << "\n";
			break;
		case '*':
			cin >> a.real >> a.imag >> b.real >> b.imag;
			tempar = a.real;
			tempai = a.imag;
			a.real = tempar * b.real - tempai * b.imag;
			a.imag = tempar * b.imag + tempai * b.real;
			if (a.imag == 0)
				output = to_string(a.real);
			else if (a.real == 0)
				output = to_string(a.imag) + "i";
			else if (a.imag < 0)
				output = to_string(a.real) + to_string(a.imag) + "i";
			else
				output = to_string(a.real) + "+" + to_string(a.imag) + "i";
			cout << output << "\n";
			break;
		default:
			break;
		}
	}


	return 0;
}
