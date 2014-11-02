#include "Month.h"
using namespace std;

Month::Month()
{
    month = 1;
}
Month::Month(int m)
{
    month = m;
}

//mut
void Month::set_month(int m)
{
    month = m;
}

//accessors
int Month::get_month()
{
    return month;
}
Month Month::get_next_month()
{
    if (month < 12)
    {
        Month NextMonth(month + 1);
        return NextMonth;
    }
    else
    {
        Month NextMonth(1);
        return NextMonth;
    }
}

//input & output
void Month::input_month(istream& stream)
{
    stream >> month;
}
void Month::output_month(ostream& stream)
{
    stream << month << endl;
}
