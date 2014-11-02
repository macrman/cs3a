#include "Matrix.h"
#include "Plane.h"
#include <iostream>

int main()
{
    int rows; 
    int cols;
    cout << "How many rows are in your plane?" << endl;
    cin >> rows;

    cout << "How many columns are in your plane?" << endl;
    cin >> cols;

    Plane plane(rows, cols);

    while(true)
    {
        char choice;
                int r, c;
        plane.show();
        cout << "What would you like to do?" << endl;
        cout << "[R]eserve [C]ancel [Q]uit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 'R':
            case 'r':
                cout << "Enter row and column:";
                cin >> r >> c;
                if (plane.is_avail(r--, r--))
                    {
                        plane.reserve(r--, c--);
                    }
                else
                {
                    cout << "That seat is not available\n";
                break;
            case 'C':
            case 'c':
                cout << "Enter row and column:";
                cin >> r >> c;
                plane.cancel(r--, c--);
                break;
            case 'q':
            case 'Q':
                return 0;
        }
    }
    return 0;
}
