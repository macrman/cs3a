#ifndef MONEY_H
#define MONEY_H
using namespace std;

class Money
{
    public:
        Money();
        Money(int maximum);
        // assessors
        int get_val();
        // members
        void reset();
        void incr1();
        void incr10();
        void incr100();
        void incr1000();
        bool overflow();
    private:
        int val;
        int max;
};
#endif
