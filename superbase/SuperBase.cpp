#include "SuperBase.h"
#include <cstring>
#include <iostream>

using namespace std;

int str_len(const char* str);

SuperBase::SuperBase()
{
    size = 1;
    allocate(size);
    *num = 0;
    base = 10;
}

SuperBase::SuperBase(const char val[])
{
    base = 10;
    num = str_to_intarray(val);
    // destroy?
}

SuperBase::SuperBase(const char val[], const int b)
{
    base = b;
    num = str_to_intarray(val);
}
SuperBase::SuperBase(const int val[], const int array_size, const int base)
{
    size = array_size;
    allocate(size);
    int* walker = num;
    for (int c = 0; c < size; c++, walker++)
    {
        *walker = val[c];
    }
}

int* SuperBase::get_num_pntr() const
{
    // DANGEROUS!!!
    return num;
}

int SuperBase::get_base() const
{
    return base;
}

int SuperBase::get_size() const
{
    return size;
}

void SuperBase::allocate(int size) //CREATES NEW SPACE, MUST BE DESTROYED!
{
    num = new int[size];
    return;
}

int* SuperBase::str_to_intarray(const char str[]) // calls allocate, MUST BE DESTROYED!
{
    // also sets the size!
    size = str_len(str);
    allocate(size);
    int* walker = num;
    for (int count = 0; count < size; count++, walker++)
    {
        if (isalpha(str[count]))
        {
            *walker = toupper(str[count]) - 55;
        }
        else
        {
            *walker = str[count] - '0';
        }
    }
    return num;
}

int str_len(const char * str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

ostream& operator <<(ostream& outs, const SuperBase& Number)
{
    int* walker = Number.get_num_pntr();
    for (int c = 0; c < Number.get_size(); c++, walker++)
    {
        if (*walker >= 10)
        {
            char num = *walker + 55;
            outs << num;
        }
        else
            outs << *walker;
    }
        return outs;
}

SuperBase operator +(SuperBase& left, SuperBase& right)
{

    int* big_num;
    int* small_num;
    int base = left.get_base();
    SuperBase sum;
    int big_walker, small_walker, sum_walker, sum_size;
    if (left.get_base() != right.get_base())
    {
        SuperBase sum = SuperBase();
        return sum;
    }

    if (left.get_size() > right.get_size())
    {
        big_num = left.get_num_pntr();
        small_num = right.get_num_pntr();

        big_walker = left.get_size()-1;
        small_walker = right.get_size()-1;
    }
    else
    {
        big_num = right.get_num_pntr();
        small_num = left.get_num_pntr();

        big_walker = right.get_size()-1;
        small_walker = left.get_size()-1;
    }
    sum_size = big_walker+2;

    sum_walker = sum_size-1;

    // create the sum array filled with zeros
    int sum_array[sum_size];
    for (int i = 0; i < sum_size; i++)
        sum_array[i] = 0;


    while (small_walker >= 0 && big_walker >=0)
    {
        sum_array[sum_walker] = 
            big_num[big_walker] + small_num[small_walker];
        sum_walker--;
        small_walker--;
        big_walker--;
    }
    while(big_walker >=0)
    {
        sum_array[sum_walker] = big_num[big_walker];
        big_walker--;
        sum_walker--;
    }
    // carry
    for (int walker = 0; sum_walker < sum_size; sum_walker++)
    {
        if (sum_array[walker] >= base)
        {
            sum_array[walker-1] += sum_array[walker] / base;
            sum_array[walker] = sum_array[walker] % base;
        }
    }

    // delete preceding 0 if necessary;
    // 
    /*
    int zero_count = 0;
    for (int c = 0; c < sum_size && c==0; c++)
    {
        zero_count++;
    }
    if (zero_count > 0)
    {
        int new_sum_size = sum_size-zero_count;
        int new_sum[new_sum_size];
        for(int c = zero_count; c < new_sum_size; c++)
        {
            new_sum[c - zero_count] = sum_array[c];
        }
        sum = SuperBase(new_sum, new_sum_size, left.get_base());
    }
    else
    {
        sum = SuperBase(sum_array, sum_size, left.get_base());
    }
    */
    sum = SuperBase(sum_array, sum_size, left.get_base());
    return sum;
}
