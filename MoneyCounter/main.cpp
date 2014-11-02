#include "Money.h"
#include <iostream>
using namespace std;
void input(char& coin, int& amount);

int main()
{
    char coin;
    int amount;
    Money MoneyCount(2000);
    bool done = false;
    while (!done)
    {
        input(coin, amount);
        coin = tolower(coin);
        switch(coin)
        {
            case 'a':
                for (int i=0; i<amount; i++)
                    MoneyCount.incr1();
                break;
            case 's':
                for (int i=0; i<amount; i++)
                    MoneyCount.incr10();
                break;
            case 'd':
                for (int i=0; i<amount; i++)
                    MoneyCount.incr100();
                break;
            case 'f':
                for (int i=0; i<amount; i++)
                    MoneyCount.incr1000();
                break;
            case 'r'
                MoneyCount.reset();
            case 'q':
                done = true;
                break;
            default:
                cout << "Your input was invalid";
                break;
        };
        cout << "Count: " << MoneyCount.get_val() << endl;
    }
    return 0;
}

void input(char& coin, int& amount)
{
    cout << "Insert the coin, then the amount, or Q to quit:";
    cin >> coin >> amount;
}
