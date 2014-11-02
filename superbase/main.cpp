#include "SuperBase.h"
#include <iostream>
using namespace std;

int main()
{
    SuperBase MyNum = SuperBase();
    cout << "Initiate class w/no args. Value should be 0 and " 
         << "base should be 10:" << endl 
         << "Size:" << MyNum.get_size() << endl
         << "Value:" << MyNum << endl 
         << "Base:" << MyNum.get_base() << endl;

    SuperBase Hello = SuperBase("C1a1", 16);
    cout << "Initiate class w/2 args. Value should be 12 1 10 1 and"
         << "base should be 16:" << endl
         << "Size:" << Hello.get_size() << endl
         << "Value:" << Hello << endl
         << "Base:" << Hello.get_base() << endl;

    SuperBase Foo = SuperBase("123");
    cout << "Initiate class w/1 arg. Value should be 123 and "
         << "base should be 10:" << endl
         << "Size:" << Foo.get_size() << endl
         << "Value:" << Foo << endl
         << "Base:" << Foo.get_base() << endl;
    cout << Foo << endl;

    SuperBase Bar = SuperBase("999");
    cout << "Initiate class w/1 arg. Value should be 123 and "
         << "base should be 10:" << endl
         << "Size:" << Foo.get_size() << endl
         << "Value:" << Foo << endl
         << "Base:" << Foo.get_base() << endl;
    cout << Foo << endl;
    cout << Bar+Foo << endl;

    return 0;
}
