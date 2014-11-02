#include "Plane.h"

Plane::Plane(int row, int col)
{

    cout << "rows: " << row << "cols: " << col << endl;
    int my_size[row+1]; 
    for(int pos=0; pos < row+1; pos++)
        my_size[pos] = col;
    my_size[row] = -1;

    Seats.set_matrix_layout(my_size);
    Seats.allocate2d();
    Seats.fill_null();
}

void Plane::reserve(int row, int col)
{
    Seats.insert(row, col, 'X');
}
void Plane::cancel(int row, int col)
{
    Seats.remove(row, col);
}
bool Plane::is_avail(int row, int col)
{
    if(Seats.get(row,col) == '\0')
        return true;
    return false;
}

void Plane::show()
{
    cout << Seats;
}
