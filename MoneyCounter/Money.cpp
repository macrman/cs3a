#include "Money.h"
using namespace std;

Money::Money()
{
    max = 9000;
    val = 0;
}
Money::Money(int maximum)
{
    max = maximum;
    val = 0;
}
// assessors
int Money::get_val()
{
    return val;
}
// members
void Money::reset()
{
    val = 0;
}
void Money::incr1()
{
    if (!overflow())
        val += 1;
}
void Money::incr10()
{
    if (!overflow())
        val += 10;
}
void Money::incr100()
{
    if (!overflow())
        val += 100;
}
void Money::incr1000()
{
    if (!overflow())
        val += 1000;
}
bool Money::overflow()
{
    if (val > max)
        return true;
}
