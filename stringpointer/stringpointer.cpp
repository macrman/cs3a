#include <iostream>
using namespace std;
int str_len(char* str);
void str_copy(char* target_str, char* original_str);
int str_find(char* source_str, char target);
void str_cat(char* target_str, char* obj_str);
void print_str(char* str);
bool str_cmp(char* str1, char* str2);
int find(char* str1, char* str2);
char* sub_str(char* str, int begin);
char* str_reverse(char* orig_str);
char* delete_repeats(char* orig_str);

int main()
{
    char hello[100] = "hello", empty[100] = "", world[100] = "world";
    cout << "We have a string 'hello'. Here's the length: "
         << str_len(hello) << endl;


    str_copy(empty, hello);
    cout << "We have an empty string, lets copy 'hello' into it: ";
    print_str(empty);
    cout << endl;

    cout << "Are the 2 strings we made equal: " 
         << str_cmp(hello, empty) << endl;

    cout << "We now have another string 'world'. Lets combine 'hello' and 'world': ";
    str_cat(hello, world);
    print_str(hello);
    cout << endl;

    cout << "Where is the letter 'e' in 'hello'?: " 
         << str_find(hello, 'e') << endl;

    cout << "Are 'hello' and 'helloworld' equal?: " 
         << str_cmp(hello, empty) << endl;

    char* charpoint = sub_str(hello, 2);
    cout << "Lets cut up our string from position 2 onwards: ";
    print_str(charpoint);
    cout << endl;


    cout << "Lets delete the repeats: ";
    char* deletedrepeats = delete_repeats(charpoint);
    print_str(deletedrepeats);
    cout << endl;

    cout << "Lets reverse it now: ";
    char* reversehello = str_reverse(deletedrepeats);
    print_str(reversehello);
    cout << endl;

    delete[] reversehello;
    delete[] charpoint;
    delete[] deletedrepeats;


    return 0;
}

int str_len(char* str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

char* delete_repeats(char* orig_str)
{
    char* new_str = new char[str_len(orig_str)+1];
    *new_str = '\0';
    char* orig_str_walk = orig_str; //walker and original at the begin of array
    char* new_str_walk = new_str;

    while (*orig_str_walk != '\0')
    {
        if (str_find(new_str, *orig_str_walk) >= 0)
        {
            orig_str_walk++;
        }
        else
        {
            *new_str_walk = *orig_str_walk;
            orig_str_walk++;
            new_str_walk++;
            *new_str_walk = '\0';
        }
    }
    return new_str;
}

char* str_reverse(char* orig_str)
{
    char* new_str = new char[str_len(orig_str)];
    char* orig_str_walk = (orig_str + (str_len(orig_str)-1));
    char* new_str_walk = new_str;
    while(orig_str_walk >= orig_str)
    {
        *new_str_walk = *orig_str_walk;
        orig_str_walk--;
        new_str_walk++;
    }
    *new_str_walk = '\0';
    return new_str;
}

void str_copy(char* target_str, char* original_str)
{
    while(*original_str != '\0')
    {
        *target_str = *original_str;
        original_str++;
        target_str++;
    }
}

void str_cat(char* target_str, char* obj_str)
{
    target_str += str_len(target_str);
    while(*obj_str != '\0')
    {
        *target_str = *obj_str;
        target_str++;
        obj_str++;
    }
    *target_str = '\0';
}

int str_find(char* source_str, char target)
{
    int source_str_pos = 0;
    while (*source_str != '\0')
    {
        if (*source_str == target)
        {
            return source_str_pos;
        }
        else
        {
            source_str_pos++;
            source_str++;
        }
    }
    return -1;
}

bool str_cmp(char* str1, char* str2)
{
    if (str_len(str1) != str_len(str2))
    {
        return false;
    }
    else
    {
        while(*str1 != '\0' )
        {
            if (*str1 != *str2)
            {
                return false;
            }
            str1++;
            str2++;
        }
    }
    return true;
}

char* sub_str(char* str, int begin)
{
    char* new_str = new char[str_len(str)];
    char* walker = new_str;
    str+=(begin);
    while(*str != '\0')
    {
        *walker = *str;
        str++;
        walker++;
    }
    *walker = '\0';
    return new_str;
}

void print_str(char* str)
{
    while(*str != '\0')
    {
        cout << *str;
        str++;
    }
}
