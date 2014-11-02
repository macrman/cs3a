#ifndef matrix_h
#define matrix_h
#include <iostream>

using namespace std;

class Matrix
{
    public:
        Matrix();
        Matrix(int sizes[]);
        // takes an array that ends w/-1. the size up to -1 determines the num
        // of rows, each individual num determines the num of columns for that
        // row;
        void show();
        int get_num_rows() const;
        // gets the num of rows for the matrix
        int get_num_cols(int row) const;
        // the the num of cols in that row
        void fill_null();
        // fills the entire matrix with null chars
        void insert(const int row, const int col, const char val);
        void fill_row(const int row, const char val);
        void clear_row(const int row);
        void remove(const int row, const int col);
        void deallocate();
        bool cell_exists(int row, int col) const;
        char get(int row, int col) const;
        friend ostream& operator <<(ostream& outs, Matrix& array);

        ~Matrix(); // destructor
        Matrix(const Matrix& copythis); // copy constructer
        Matrix& operator =(const Matrix& copythis); //overload assignment opp
        // TODOS ===================================================//////
        char * search(char const query, int& row, int& col); // search function

        // cell exists
        // braket operator overload
        void set_matrix_layout(int rows[]); //ALLOCATES SPACE!
        void allocate2d(); //ALLOCATES SPACE!

    private:

        int row_size;
        char** matrix;
        int* matrix_layout; 
};

#endif
