#include "MyString.h"
#include<iostream>
#include<string>
#include<string.h>
/// Complete MyString's Methods
using namespace std;

MyString::MyString() {
	_size = 0; _s = nullptr;
}

MyString::MyString(const string &s) {
	set(s);
}

MyString::~MyString() {
	if (_s) delete[] _s;
}

int MyString::size() const {
	return _size;
}

char MyString::at(const int &index) const {
	//cout << _size;
	if (_size > index)
		return *(_s + index);
	else
		cout << "Error in at()";
	return '\0';
}

void MyString::replace(const int &index, const char &ch) {
	if (index < _size)
		*(_s + index) = ch;
	else
	{
		cout << "Error in replace ()\n";
	}
}

void MyString::set(const string &s) {
	delete[] _s;
	_size = s.size();
	_s = new char[_size+1];
	for (int i = 0; i < _size; i++)
	{
		_s[i] = s[i];
	}
	_s[_size] = '\0';
}

void MyString::append(const std::string &s) {
	set(_s + s);
}

void MyString::reverse() {
	string s;
	for (int i = 0; i < _size; i++)
	{
		s += _s[_size - i - 1];
	}
	set(s);
}

void MyString::print() const {
	puts(_s);
}

void MyString::clear() {
	_size = 0;
	*_s = '\0';
}
