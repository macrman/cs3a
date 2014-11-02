#ifndef plane_h
#define plane_h
#include "Matrix.h"

using namespace std;

class Plane
{
    public:
        Plane();
        Plane(int row, int col);
        void reserve(int row, int col);
        void cancel(int row, int col);
        bool is_avail(int row, int col);
        void show();
        Matrix Seats;
    private:
};

#endif
