#include <iostream>
#include <fstream>
using namespace std;
void count_occurences_of(int num, int record[9999][2], int &size);
void insert(int a[][2], int &size, int pos, int item);
void show(int a[9999][2], int &size);

int main()
{
    int record[9999][2], size = 0;
    char input;
    ifstream fin;

    fin.open("numfile.txt");
    fin.get(input);
    while(! fin.eof())
    {
        if (isdigit(input))
        {
            int num = input - '0';
            count_occurences_of(num, record, size);
        }
        fin.get(input);
    }
    show(record, size);
}

void count_occurences_of(int num, int record[9999][2], int &size)
{
    if (size == 0) // if the record is empty, just insert it in the front
    {
        record[0][0] = num;
        record[0][1] = 1;
        size++;
        return;
    }
    else if (num < record[0][0]) // if num is < the first one, insert it into the front
    {
        insert(record, size, 0, num);
    }
    else if (num > record[size-1][0]) // if num is larger than the last one, put it @ end
    {
        insert(record, size, size, num);
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            if (record[i][0] == num) // if num exists, increment the num of occurences
            {
                record[i][1]++;
            }
            else if (num > record[i-1][0] && num < record[i][0]) //otherwise, insert in order
            {
                insert(record, size, i, num);
            }
        }
    }
}

void insert(int a[][2], int &size, int pos, int item)
{
    for (int j = 0; j < 2; j++)
    {
        for (int i = size; i>= pos; i--)
        {
            a[i+1][j] = a[i][j];
        }
    }
    a[pos][0] = item;
    a[pos][1] = 1;
    size++;
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
    cout << "===========================================================\n";
}
