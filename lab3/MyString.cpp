#include "MyString.h"
#include<iostream>
#include<string>
#include<string.h>
/// Complete MyString's Methods
using namespace std;

MyString::MyString() {
	_size = 0; *_s = '\0';
}

MyString::MyString(const string &s) {
	set(s);
}

MyString::~MyString() {
	if (_s) delete [] _s;
}

int MyString::size() const{
	return _size;
}

char MyString::at(const int &index) const {
	if (size() > index)
		return *(_s + index);
	else
		cout << "Error in at()\n";
	return '\0';
}

void MyString::replace(const int &index, const char &ch) {
	if(index < _size)
	*(_s + index) = ch;
	else
	{
		cout << "Error in replace ()\n";
	}
}

void MyString::set(const string &s) {
	delete [] _s;
	_size = s.size();
	_s = new char[7];
	cout << s.size() << "\n";
	for (int i = 0; i < _size; i++)
	{
		_s[i] = s[i];
	}
}

void MyString::append(const std::string &s) {
	set(_s + s);
}

void MyString::reverse() {
	string s="";
	for (int i = 0; i < _size; i++)
	{
		s += _s[i];
	}
}

void MyString::print() const {
	cout << _s << "\n";
}

void MyString::clear() {
	_size = 0;
	*_s = '\0';
}
