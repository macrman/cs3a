#include "Matrix.h"

Matrix::Matrix()
{
    row_size = 0;
    matrix_layout = NULL;
    matrix = NULL;
}
Matrix::Matrix(int sizes[])
{
    set_matrix_layout(sizes);
    allocate2d();
    fill_null();
}

int Matrix::get_num_rows() const
{
    return row_size;
}

int Matrix::get_num_cols(int row) const
{
    return matrix_layout[row];
}

void Matrix::show()
{
    for(int row = 0; row < get_num_rows(); row++)
    {
        for(int column = 0; column < get_num_cols(row); column++)
        {
            if(matrix[row][column] == '\0')
            {
                cout << "[ ]";
            }
            else
            {
                cout << '[' << matrix[row][column] << "]";
            }
        }
        cout << endl;
    }
}

void Matrix::set_matrix_layout(int rows[])
{
    int count = 0;
    while(rows[count] != -1)
    {
        count++;
    }
    row_size = count;
    matrix_layout = new int[row_size];
    for (int c = 0; c < row_size + 1; c++)
    {
        matrix_layout[c] = rows[c];
    }
}

void Matrix::allocate2d()
{
    matrix = new char*[get_num_rows()];
    for(int row = 0; row < get_num_rows(); row++)
    {
        matrix[row] = new char[matrix_layout[row]];
    }
}

void Matrix::fill_null()
{
    for(int row = 0; row < get_num_rows(); row++)
    {
        for(int column = 0; column < matrix_layout[row]; column++)
        {
            matrix[row][column] = '\0';
        }
    }
}

void Matrix::insert(const int row, const int col, const char val)
{
    if (cell_exists(row, col))
    {
        matrix[row][col] = val;
    }
}

void Matrix::fill_row(const int row, const char val)
{
    for(int col = 0; col < get_num_cols(row); col++)
    {
        matrix[row][col] = val;
    }
}
bool Matrix::cell_exists(int row, int col) const
{
    if((row < get_num_rows()) && (col < get_num_cols(row)))
        return true;
    return false;
}
char Matrix::get(int row, int col) const
{
    if (cell_exists(row, col))
    {
        return matrix[row][col];
    }
}

void Matrix::remove(const int row, const int col)
{
    if (cell_exists(row, col))
    {
        matrix[row][col] = '\0';
    }
}
void Matrix::clear_row(const int row)
{
    fill_row(row, '\0');
}

void Matrix::deallocate()
{
    if(matrix) // make sure there is something to delete
    {
        for (int row = 0; row < get_num_rows(); row++)
        {
            delete [] matrix[row];
        }
        delete [] matrix;
        matrix = NULL;
    }
    if(matrix_layout)
    {
        delete [] matrix_layout;
        matrix_layout = NULL;
    }
    row_size = 0;
}

ostream& operator <<(ostream& outs, Matrix& array)
{
    for(int row = 0; row < array.get_num_rows(); row++)
    {
        for(int column = 0; column < array.get_num_cols(row); column++)
        {
            if(array.matrix[row][column] == '\0')
            {
                outs << "[ ]";
            }
            else
            {
                outs << '[' << array.matrix[row][column] << "]";
            }
        }
        outs << endl;
    }
}

Matrix::Matrix(const Matrix& copythis) // copy constructer
{
    row_size = 0;
    matrix = NULL;
    matrix_layout = NULL;

    // get the size of the original matrix_layout
    int orig_num_rows = copythis.get_num_rows() + 1;
    int orig_matrix_layout [orig_num_rows];

    // now copy the contents of the orig matrix_layout into an new array
    for (int row = 0; row < orig_num_rows; row++)
    {
        orig_matrix_layout[row] = copythis.get_num_cols(row);
    }
    // pass that copy of the orig matrix layout to initialize a new layout
    // within the allocated space
    set_matrix_layout(orig_matrix_layout);

    // now lets allocate the matrix
    allocate2d();

    // now lets copy the contents of the orignal matrix into the new matrix
    for (int row = 0; row < get_num_rows(); row++)
    {
        for(int col = 0; col < get_num_cols(row); col++)
        {
            insert(row, col, copythis.get(row,col));
        }
    }
}

Matrix& Matrix::operator =(const Matrix& copythis) //overload assignment opp
{
    if(&copythis == this)
        return *this;

    deallocate();

    // get the size of the original matrix_layout
    int orig_num_rows = copythis.get_num_rows() + 1;
    int orig_matrix_layout [orig_num_rows];

    // now copy the contents of the orig matrix_layout into an new array
    for (int row = 0; row < orig_num_rows; row++)
    {
        orig_matrix_layout[row] = copythis.get_num_cols(row);
    }
    // pass that copy of the orig matrix layout to initialize a new layout
    // within the allocated space
    set_matrix_layout(orig_matrix_layout);

    // now lets allocate the matrix
    allocate2d();

    // now lets copy the contents of the orignal matrix into the new matrix
    for (int row = 0; row < get_num_rows(); row++)
    {
        for(int col = 0; col < get_num_cols(row); col++)
        {
            insert(row, col, copythis.get(row,col));
        }
    }
    return *this;
}

Matrix::~Matrix() // destructor
{
    deallocate();
}


char * Matrix::search(char const query, int& r, int& c) // search function
{
    char * found = NULL;
    for(int row=0; row < get_num_rows(); row++)
    {
        for(int col=0; col< get_num_cols(row); col++)
        {
            if (get(row, col) == query)
            {
                found = &matrix[row][col];
                r = row;
                c = col;
                return found;
            }
        }
    }
    return found;
}
