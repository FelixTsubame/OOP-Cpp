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