#pragma once
#ifndef MYSTRING_H

#include <iostream>
#include <string>

class MyString
{
    private :
        char *_s;
        int _size;

    public :
        MyString();
        MyString(const std::string &s);
        ~MyString();

        int size() const;
        char at(const int &index) const;
        void replace(const int &index, const char &ch);
        void set(const std::string &s);
        void append(const std::string &s);
        void reverse();
        void print() const;
        void clear();
};


#endif // !MYSTRING_H
