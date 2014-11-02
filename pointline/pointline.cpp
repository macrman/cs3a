#include <iostream>
using namespace std;

class Point
{
    public:
        Point(int i, int j);
        Point();
        int getx();
        int gety();
        int x;
        int y;
};

class Line
{
    public:
        Line(int x1, int x2, int y1, int y2);
        int get_slope();
        int get_length();
    private:
        Point P1;
        Point P2;
};

int main()
{
    Point hello(0,10);
    Point world(0,0);
    //Line foo(hello, world);
    Line foo(0, 10, 0, 0);
    cout << hello.getx();
    cout << foo.get_slope();
}

Line::Line(int x1, int x2, int y1, int y2)
{
    P1.x = x1;
    P1.y = y1;
    P2.x = x2;
    P2.y = y2;
}

int Line::get_slope()
{
    int x1, x2, y1, y2, slope;
    x1 = P1.getx();
    x2 = P2.getx();
    y1 = P1.gety();
    y2 = P2.gety();
    slope = (y2 - y1)/(x2 - x1);
    return slope;
}

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int i, int j)
{
    x = i;
    y = j;
}

int Point::getx()
{
    return x;
}
int Point::gety()
{
    return y;
}
