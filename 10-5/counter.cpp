#include "counter.h"

Counter::Counter()
{
    count = 0;
    error = false;
}
Counter::Counter(int c):{
    if (c > MAX){
        error = true;
    }
    else
        error = false;
}
int Counter::Inc(){
    if (c > MAX){
        error = ture;
    }
}
