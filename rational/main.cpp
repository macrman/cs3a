#include "Rational.h"

using namespace std;

int main()
{
    Rational R1(3,4), R2(2,5), R3(6,8);
    cout << "3/4 * 2/5 = " << R1*R2 << endl;
    cout << "3/4 / 2/5 = " << R1/R2 << endl;
    cout << "3/4 * 2 = " << R1*2 << endl;
    cout << "3/4 == 2/5 = " << (R1==R2) << endl;
    cout << "3/4 == 6/8 = " << (R1==R3) << endl;
    cout << "3/4 < 2/5 =" << (R1<R2) << endl;
    cout << "3/4 > 2/5 =" << (R1>R2) << endl;
    return 0;
}
