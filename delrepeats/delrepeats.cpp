#include <iostream>

using namespace std;
int del(char a[], int pos);
void delete_repeats(char phrase[]);
bool already_exists(char phrase[], int pos);

int main(){
    char input[9999];
    cout << ':';
    cin >> input;
    delete_repeats(input);
    cout << input << endl;
}

void delete_repeats(char phrase[])
// takes a char array, deletes anything that repeats
{
    int i = 0;
    while(phrase[i] != '\0')
    {
        if(already_exists(phrase, i))
        {
            del(phrase, i);
        }
        else
            i++;
    }
}

int del(char phrase[], int pos)
// dels the char @ pos by moving everything left into that pos
{
    for (int i = pos; phrase[i] != '\0' ; i++)
    {
        phrase[i] = phrase[i+1];
    }
}

bool already_exists(char phrase[], int pos) 
// takes num @ position, see if that num previous exists
{
    for(int i = 0; i < pos; i++)
    {
        if (phrase[i] == phrase[pos])
        {
            return true;
        }
    }
    return false;
}
