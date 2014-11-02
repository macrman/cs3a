#include "Matrix.h"
#include <iostream>

void print(Matrix hello);
int main()
{
    int demo[5] = {4,3,5,8,-1};
    Matrix wat = Matrix(demo);
    cout << "Initialize a Matrix of 4 rows, with 4,3,5,8 columns in each"
         << "respective row.\n";
    wat.show();

    cout << "Now let's put an 'X' in the last row, 2nd position.\n";
    wat.insert(3,1,'X');
    print(wat);

    cout << "Now let's fill row 1 with all A's\n";
    wat.fill_row(0, 'A');
    print(wat);

    cout << "Now let's find the location of the X.\n";
    int col, row;
    wat.search('X', row, col);
    cout << row << ',' << col << endl;

    // SEARCH FUNC

    Matrix bar = wat;
    bar.remove(3,1);
    cout << "Now let's remove that X.\n";
    print(bar);

    bar.clear_row(0);
    cout << "Now let's clear the first row.\n" << bar;

    return 0;
}

void print(Matrix hello)
{
    hello.show();
}
