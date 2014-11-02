#include "Counter.h"
using namespace std;

int main()
{
    // test single arg
    Counter Count1(10);
    cout << "start with 10:";
    Count1.output_count(cout);

    // test increment
    Count1.increment();
    cout << "now we increment by 1:";
    Count1.output_count(cout);

    // test decrement
    Count1.decrement();
    cout << "now we decrement by 1:";
    Count1.output_count(cout);

    cout << "Done with first test\n";

    // test no arg
    Counter Count2;
    cout << "start with 0:";
    Count2.output_count(cout);

    // test decrement below zero
    cout << "try to decrement to neg num (should be 0):";
    Count2.decrement();
    Count2.output_count(cout);

    cout << "Done with second test\n";

    return 0;
}
