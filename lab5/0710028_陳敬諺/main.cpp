#include <iostream>
using namespace std;
#include "HugeInteger.h" 

int main() //< Do NOT modified this functiuon
{
	unsigned int seed;
	unsigned int length1, length2, length3;
	HugeInteger n1, n2, n3;
	int input_t;
	
	cout << "How many times to input?" << endl;
	cin >> input_t;

	for (int i = 0; i < input_t; i++) {
		cout << "Enter seed: ";
		cin >> seed;
		srand(seed);

		cout << "Enter the lengths of three huge integers: ";
		cin >> length1 >> length2 >> length3;

		
		n1 = HugeInteger::random(length1);
		cout << "N1: " << n1 << endl;
		n2 = HugeInteger::random(length2);
		cout << "N2: " << n2 << endl;
		n3 = HugeInteger::random(length3);
		cout << "N3: " << n3 << endl;
		
		
		cout << "N1 + N3 = " << n1 + n3 << endl;
		cout << "N2 - N3 = " << n2 - n3 << endl;
	}

	system("pause");
	return 0;
}
