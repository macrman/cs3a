#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
using namespace std;

class Counter
{
    public:
        //constructors
        Counter();
        Counter(int value);
        //mutators
        void increment();
        void decrement();
        //accessors
        int get_count();
        //others
        bool is_zero();
        void output_count(ostream& out);
    private:
        int count;
};

#endif
