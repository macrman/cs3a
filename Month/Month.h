#ifndef MONTH_H
#define MONTH_H
#include <iostream>
using namespace std;

class Month
{
    public:
        //constructors
        Month();
        Month(int m);
        //mut
        void set_month(int month);
        //accessors
        int get_month();
        Month get_next_month();
        //input & output
        void input_month(istream& stream);
        void output_month(ostream& stream);
    private:
        int month;
};

#endif
