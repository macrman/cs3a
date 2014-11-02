#include <iostream>
using namespace std;

void show(int a[9999][2], int &size);
void showsinglerow(int a[], int size);

int main ()
{
    int hello[999][2];
    int size = 5;
    for (int i=0; i<size; i++)
        hello[i][0] = i;
    for (int i=0, j=4; i<size; i++, j--)
        hello[i][1] = j;
    show(hello, size);
    showsinglerow(hello[3], 9);
    return 0;
}

void showsinglerow(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
}

void show(int a[9999][2], int &size)
{
    cout << "===========================================================\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "size:" << size << endl;
    cout << "===========================================================\n";
}
