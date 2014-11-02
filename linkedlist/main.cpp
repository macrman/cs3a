#include "List.h"
#include "SortedList.h"
#include <iostream>

using namespace std;
void print(List hello);

int main ()
{
    int newone[3]={1,2,3};

    List fuck(newone, 3);

    /*
    List hello = List(newone, 3);
    */
    List hello(1);
    hello.append(2);
    hello.append(3);
    hello.append(4);
    hello.insert_head(0);
    hello.print();
    // HAHA I DELETED THE LIST
    cout << endl;

    cout << "This is the last one: " << hello.get(-1) << endl<< endl;

    cout << "This is the item at pos 2 " << hello.get(2) << endl << endl;

    hello.append(7);
    cout << "Now let's append a 7: " << endl;
    hello.print();

    hello.insert(4, 9);
    cout << "Insert a 9 in pos 4: " << endl;
    hello.print();

    cout << "What's the size? " << hello.length() << endl;

    hello.del(hello.length() - 1);
    cout << "we deleted the last one:\n";

    print(hello);
    cout << "the number 3 is in position: " << hello.search(3)<< endl;
    hello[2] = 9;
    hello[0] = 9;

    print(hello);


    return 0;
}

void print(List hello)
{
    hello.print();
}
