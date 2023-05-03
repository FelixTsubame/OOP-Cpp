#include "HugeInteger.h"
#include <iostream>
#include <vector>
using namespace std;

HugeInteger::HugeInteger() 
{
	numarr.clear();
	length = 0;
}

HugeInteger::HugeInteger(HugeInteger &in)
{
	length = in.length;
	numarr.resize(in.length);

	for (int i = 0; i < length; i++)
	{
		numarr[i] = in.numarr[i];
	}
}


HugeInteger HugeInteger::random(unsigned int size) 
{
	HugeInteger a;
	a.length = size;
	a.numarr.resize(size);
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		temp = rand() % 10;
		a.numarr[i] = temp;
	}

	a.numarr[size - 1] = rand() % 9 + 1;

	return a;
}

HugeInteger HugeInteger::operator+(const HugeInteger &right) {
	HugeInteger sum;
	int size;
	int c = 0;
	size = length;
	sum.numarr.resize(size);
	for (int i = 0; i < size; i++)
	{
		if (i < right.length)
			sum.numarr[i] = numarr[i] + right.numarr[i];
		else
			sum.numarr[i] = numarr[i];
		//cout << sum.numarr[i] << "\n";
	}
	
	for (int i = 0; i < sum.numarr.size(); i++)
	{
		sum.numarr[i]+=c;
		c = sum.numarr[i] / 10;
		sum.numarr[i] %= 10;
	}
	if (c != 0)
		sum.numarr.push_back(c);
	sum.length = sum.numarr.size();
	return sum;
};

HugeInteger HugeInteger::operator-(const HugeInteger &right) {
	HugeInteger sum;
	int size;
	int c = 0;
	size = length;
	sum.numarr.resize(size);
	for (int i = 0; i < size; i++)
	{
		if (i < right.length)
			sum.numarr[i] = numarr[i] - right.numarr[i];
		else
			sum.numarr[i] = numarr[i];
		//cout << sum.numarr[i] << "\n";
	}

	for (int i = 0; i < sum.numarr.size(); i++)
	{
		sum.numarr[i] -= c;
		if (sum.numarr[i]<0)
		{
			sum.numarr[i] += 10;
			c = 1;
		}
		else
		{
			c = 0;
		}
	}
	if (sum.numarr[length-1] == 0)
		sum.numarr.pop_back();
	sum.length = sum.numarr.size();
	return sum;

};

ostream &operator<<(ostream &output, const HugeInteger &in) {
	string num;
	for (int i = in.length - 1; i >= 0; i--)
		output << in.numarr[i];
	return output;
};