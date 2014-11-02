#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void convert2array(string& s_digit, int digit[]);
void add_nums(int array1[], int array2[], int sumarray[], int base);
void add_in_any_base(string& first, string& second, int sum[], int base);
void display_result(int sum[]);
void show(int a[]);
int const overflow = 4; //num can't be more than 100 digits long


int main()
{
    int first[overflow] = {0}, second[overflow] = {0}, answer[overflow] = {0};
    string one = "12af", two = "111f";
    add_in_any_base(one, two, answer, 16); 
    show(answer);
    display_result(answer);
    cout << "hello";
    return 0;
}

void add_in_any_base(string& first, string& second, int sum[], int base)
{
    int array1[overflow], array2[overflow];
    convert2array(first, array1);
    convert2array(second, array2);
    add_nums(array1, array2, sum, base);
}

void convert2array(string& s_digit, int digit[])
{
    if(s_digit.length() > overflow)
    {
        cout << "convert 2 array error";
        exit(1);
    }
    for (int spos=s_digit.length()-1, apos=overflow-1; (spos>= 0); apos--, spos--)
    {
        char ch = s_digit[spos]; // ch will be the the array.pos value
        if (isdigit(ch)) // if its just a digit, put it in
        {
            digit[apos] = ch - '0';
        }
        else 
        {
            char lttr = toupper(ch); // conver to uppercase, if letter, convert to corresponding int.
            if (isalpha(lttr))
            {
                digit[apos] = lttr;
                digit[apos] = digit[apos] - 55;
            }
            else // otherwise, it's an invalid char
            {
                cout << "invalid char error";
                exit(1);
            }
        }
    }
    cout << endl;
    return;
}

void add_nums(int array1[], int array2[], int sumarray[], int base)
{
    for (int pos = overflow - 1; (pos >=0); pos--)
    {
        if (array1[pos] >= base || array2[pos] >= base) // if the number is greater than the base, input was invalid
        {
            cout << "num greater than base error";
            exit(1);
        }
        sumarray[pos] += (array1[pos] + array2[pos]);
        if (pos == 0 && sumarray[0] > base - 1) // if 1st pos requires carrying 1, it will overflow
        {
            cout << "Overflow error during calculation.\n";
            exit(0);
        cout << "error";
        }
        if (sumarray[pos] > base - 1 ) // if its greater than base -1, it requires carrying the 1
        {
            sumarray[pos] = sumarray[pos] - base;
            cout << "carry";
            sumarray[(pos-1)]++;
        }
    }
    return;
}

void show(int a[])
{
    for (int i=0; i<overflow; i++)
        cout << a[i] << ' ';
}
void display_result(int sum[])
{
    cout << endl << "======================================\n";
    for (int pos=0; (pos < overflow); pos++)
    {
        if (sum[pos] != 0)
        {
            for (pos; pos < overflow; pos++)
            {
                if (sum[pos] >= 0 && sum[pos] <=9) // if num is 0-9, just display it
                {
                    cout << sum[pos];
                }
                else
                {
                    char c = sum[pos] + 55;
                    cout << c;
                }
            }
            cout << endl;
            return;
        }
    }
    cout << endl;
    return;
}
