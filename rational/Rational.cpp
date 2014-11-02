#include "Rational.h"
using namespace std;

Rational::Rational()
{
    top = 1;
    bottom =1;
}
Rational::Rational(int enumerator)
{
    top = enumerator;
    bottom = 1;
}
Rational::Rational(int enumerator, int denominator)
{
    top = enumerator;
    bottom = denominator;
}

// mutators
void Rational::set_enum(int enumerator)
{
    top = enumerator;
}
void Rational::set_denom(int denominator)
{
    bottom = denominator;
}

// accessors
int Rational::get_enum()
{
    return top;
}
int Rational::get_denum()
{
    return bottom;
}


//operators
Rational operator *(const Rational& Left, const Rational& Right)
{
    Rational Product;
    Product.top = Left.top * Right.top;
    Product.bottom = Left.bottom * Right.bottom;
    return Product;
}
Rational operator /(const Rational& Left, const Rational& Right)
{
    Rational Temp;
    Temp.top = Left.top * Right.bottom;
    Temp.bottom = Left.bottom * Right.top;
    return Temp;
}
bool operator ==(const Rational& Left, const Rational& Right)
{
    Rational temp;
    if (Left.top * Right.bottom == Right.top * Left.bottom)
        return true;
    return false;
}
bool operator <(const Rational& Left, const Rational& Right)
{
    if (Left.top * Right.bottom < Right.top * Left.bottom)
        return true;
    return false;
}
bool operator >(const Rational& Left, const Rational& Right)
{
    if (Left.top * Right.bottom > Right.top * Left.bottom)
        return true;
    return false;
}
ostream& operator <<(ostream& outs, const Rational& Rat)
{
    outs << Rat.top << '/' << Rat.bottom;
    return outs;
}

Rational Rational::neg()
{
    Rational Negative = (top - (top * 2), bottom);
    return Negative;
}

