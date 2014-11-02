#include "Counter.h"
using namespace std;

//constructors
Counter::Counter()
{
    count = 0;
}

Counter::Counter(int value)
{
    if(value < 0)
    {
        count = 0;
    }
    else
    {
        count = value;
    }
}

//mutators
void Counter::increment()
{
    count++;
}

void Counter::decrement()
{
    if (!is_zero()) // count must be > 0
    {
        count--;
    }
}

//accessors
int Counter::get_count()
{
    return count;
}

//others
bool Counter::is_zero()
{
    if(count == 0)
        return true;
    return false;
}
void Counter::output_count(ostream& out)
{
    out << get_count()<< endl;
}
