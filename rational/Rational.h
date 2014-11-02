#include <iostream>

using namespace std;

class Rational
{
    public:
        // constructors
        Rational();
        Rational(int enumerator);
        Rational(int enumerator, int denominator);
        // mutators
        void set_enum(int enumerator);
        void set_denom(int denominator);
        // accessors
        int get_enum();
        int get_denum();

        // operators
        friend Rational operator *(const Rational& Left, const Rational& Right);
        friend Rational operator /(const Rational& Left, const Rational& Right);
        // comparision ops
        friend bool operator ==(const Rational& Left, const Rational& Right);
        friend bool operator <(const Rational& Left, const Rational& Right);
        friend bool operator >(const Rational& Left, const Rational& Right);
        // io ops
        friend ostream& operator <<(ostream& outs, const Rational& Rat);
        //member funcs
        Rational neg();
        // input output
        void input(istream& in);
        void output(ostream& out);

    private:
        int bottom;
        int top;
};
