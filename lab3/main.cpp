#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString str("Hello");
    for (int i = 0; i < str.size(); i++) {
        cout << str.at(i) << " ";
    }
    cout << endl;
    str.print();

    str.append(", World.");
    str.print();

    str.clear();
    str.print();

    cout << str.at(0) << endl;

    str.set("1235");
    cout << str.at(4) << endl;
    cout << str.at(3) << endl;
    str.print();
    
    str.replace(3, '4');
    str.print();

    str.replace(5, '3');
    str.print();

    str.set("ABCDE");
    str.reverse();
    str.print();

    system("PAUSE");
    return 0;
}