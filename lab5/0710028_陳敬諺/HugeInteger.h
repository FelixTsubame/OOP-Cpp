#ifndef HUGE_INTEGER_H
#define HUGE_INTEGER_H
#include <vector>
#include <iostream>
using namespace std;

#define MAX 1000 // max length of huge interger
class HugeInteger
{
	friend ostream &operator<<(ostream &output, const HugeInteger &in);
public:
	HugeInteger(); // default constructor (the default value = 0)
	HugeInteger(HugeInteger &in); // copy constructor
	static HugeInteger random(unsigned int size); // randomly generate an integer
	HugeInteger operator+(const HugeInteger &right);
	HugeInteger  operator-(const HugeInteger &right);

private:
	int length;
	vector<int> numarr;
};

#endif