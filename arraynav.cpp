#include <iostream>
using namespace std;
void show(int a[], int size, int cursor_pos);

void cursor_left(int size, int &cursor_pos);
void cursor_right(int size, int &cursor_pos);

void append(int a[], int &size, int item);
int search(int a[], int size, int item);
void shiftright(int a[], int &size, int pos);
int del(int a[], int &size, int pos);
void insert(int a[], int &size, int pos, int item);
void swap(int a[], int first, int second);
void sort(int a[], int size);
int find_from(int a[], int size, int item, int pos);
void help();
int findlowest(int a[], int size, int start = 0);

int main()
{
    int max = 999;
    int array[max];
    int size = 0, cursor = 0;
    bool done = false;

    help();
    do
    {
        char choice;
        show(array, size, cursor);
        cin >> choice;
        choice = toupper(choice);

        switch(choice)
        {
            case 'A':
                int num;
                cout << "Enter a number: ";
                cin >> num;
                append(array, size, num);
                cursor = size - 1;
                break;
            case 'D':
                int sucess;
                sucess = del(array, size, cursor);
                if (sucess == 1 && cursor == size && cursor > 0)
                {
                    cursor--;
                }
                break;
            case 'F':
                int find, loc;
                cout << "Enter a number to find: ";
                cin >> find;
                loc = find_from(array, size, find, cursor);
                if (loc != -1)
                {
                    cursor = loc;
                }
                else
                {
                    loc = find_from(array, size, find, 0);
                    if (loc != -1)
                    {
                        cursor = loc;
                    }
                }
                break;
            case 'H':
                help();
                break;
            case 'I':
                cout << "Enter a number: ";
                cin >> num;
                insert(array, size, cursor, num);
                break;
            case 'L':
                cursor_left(size, cursor);
                break;
            case 'R':
                cursor_right(size, cursor);
                break;
            case 'S':
                sort(array, size);
                break;
            case 'Q':
                done = true;
                break;
        }
    } while(!done);

    return 0;
}

void help()
{
    cout << "[A]ppend: append a number to the end of the array\n"
         << "[D]elete: delete the number at the cursor's position\n"
         << "[H]elp: display this help message\n"
         << "[I]nsert: insert a number at the cursor's position\n"
         << "[F]ind: finds the a number, and moves cursor to the position of that number\n"
         << "[L]eft: move the cursor left\n"
         << "[R]ight: move the cursor right\n"
         << "[S]ort: auto-magically sort the array for you\n"
         << "[Q]uit: quit the program\n";
}

void show(int a[], int size, int cursor_pos)
{
    cout << endl << '{';
    if (size == 0 && cursor_pos == 0)
    {
        cout << "[]";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i == cursor_pos)
            {
                cout << '[' << a[i] << ']';
            }
            else
            {
                cout << a[i];
            }
            cout << ',';
        }
    }
    cout << '}' << endl << endl << "Enter your command: ";
}

void cursor_left(int size, int &cursor_pos)
{
    if (cursor_pos == 0)
    {
        cursor_pos = size - 1;
    }
    else
    {
        cursor_pos--;
    }
}

void cursor_right(int size, int &cursor_pos)
{
    if (cursor_pos == size - 1)
    {
        cursor_pos = 0;
    }
    else
    {
        cursor_pos++;
    }
}

void append(int a[], int &size, int item)
{
    a[size] = item;
    size++;
}

// returns the position of the first instance of an item in list. If not found,
// it returns -1
int search(int a[], int size, int item)
{
    for (int i = 0; i < size; i++)
        if (a[i] == item)
        {
            return i;
        }
    return -1;
}

void shiftright(int a[], int &size, int pos)
{
    for (int i = size; i>= pos; i--)
    {
        a[i+1] = a[i];
    }
    size++;
}

int del(int a[], int &size, int pos)
{
    // returns 0 if error
    if (size < 1)
    {
        return 0;
    }
    else
    {
        for (int i = pos; i < size; i++)
        {
            a[i] = a[i+1];
        }
    size--;
    return 1;
    }
}

void insert(int a[], int &size, int pos, int item)
{
    shiftright(a, size, pos);
    a[pos] = item;
}

void swap(int a[], int first, int second)
{
    int temp = a[second];
    a[second] = a[first];
    a[first] = temp;
}

int findlowest(int a[], int size, int start)
{
    if (size == 0)
    {
        return -1;
    }
    else if (size == 1)
    {
        return a[0];
    }
    else
    {
        int lowestpos = start;
        for (int i = start; i < size; i++)
        {
            if (a[i] < a[lowestpos])
            {
                lowestpos = i;
            }
        }
        return lowestpos;
    }
}

void sort(int a[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        int lowestnum = findlowest(a, size, i+1);
        if (a[i] > a[lowestnum])
        {
            swap(a, i, lowestnum);
        }
    }
}

int find_from(int a[], int size, int item, int pos)
{
    for (int i = pos; i < size; i++)
    {
        if(a[i] == item)
            return i;
    }
    return -1;
}
