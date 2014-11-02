#include <iostream>
using namespace std;
class SuperBase
{
    public:
        SuperBase();
        SuperBase(const char val[]);
        SuperBase(const char val[], const int base);
        SuperBase(const int val[], const int size, const int base);
        int* get_num_pntr() const;
        int get_size() const;
        int get_base() const;
        char* get_val(); //returns the value of the num as a charrary

        // helper func
        int* str_to_intarray(const char str[]); // calls allocate, MUST BE DESTROYED!

        //operator overloading
        friend ostream& operator <<(ostream& outs, const SuperBase& Number);
        friend SuperBase operator +(SuperBase& left, SuperBase& right);
    private:
        void allocate(int size); // creates new space, MUST BE DESTORYED!
        int* num;
        int base;
        int size;
}; 
