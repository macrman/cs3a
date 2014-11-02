#include <iostream>

using namespace std;


int main()
{
    int num =12345 ;
    int new_num = 0;
    cout << "num: " << num << endl;
    while(num > 0)
    {
        new_num = new_num*10 + (num % 10);
        num = num/10;
        cout << "new_num:" << new_num << endl;
        cout << "num: " << num << endl;
    }
    cout << new_num << endl;

    /*
    char letter;
    do
    {
        cin.get(letter);
        cout << letter << ' ';
    }while(letter != '\n' );
    */

    return 0;
}










