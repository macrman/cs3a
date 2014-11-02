#include "Month.h"

using namespace std;

int main()
{
    Month MyMonth;
    cout << "set month to dec\n";
    MyMonth.set_month(12);
    MyMonth.output_month(cout);

    cout << "get the next month\n";
    Month HelloMonth = MyMonth.get_next_month();
    HelloMonth.output_month(cout);
    
    return 0;
}
