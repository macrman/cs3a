#include "BaseList.h"
#include <iostream>
#include <cassert>

using namespace std;

void listprint(BaseList<int> list);
int main() {

    {
        // Create an empty list
        BaseList<int> mylist;
        // make sure the size is null
        assert(mylist.len() == 0);

        // now we prepend some items
        mylist.prepend(3);
        mylist.prepend(2);
        mylist.prepend(1);

        // now let's append some items
        mylist.append(4);
        mylist.append(5);

        // check the size again
        cout << mylist.len()<< endl;
        assert(mylist.len() == 5);

        // make sure the first one is correct
        assert(mylist.get(0) == 1);

        // make sure the 3rd one is correct
        assert(mylist[2] == 3);

        // make sure the last one is correct
        assert(mylist.get(mylist.len() - 1) == 5);

        // now let's delete stuff
        mylist.del(4);

        mylist.insert(3, 9);

        BaseList<int>::Iterator iter = mylist.begin();
        *iter = 9;

        listprint(mylist);
        mylist.print();

        BaseList<int> newlist;
        mylist = newlist;

    }

    // test iterator
    cout << "All tests passed! YAY Everything works!" << endl
         << "You're fucking amazing. Go get yourself some drinks."
         << endl;
    return 0;
}

void listprint(BaseList<int> list)
{
    list.print();
}
