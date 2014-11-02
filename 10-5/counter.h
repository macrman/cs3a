#ifndef COUNTER_H
#define COUNTER_H
int const MAX = 9999

class Counter
{
    public:
        Counter();
        Counter(int c);
        int Inc();
        int Dec();
        void Reset();
        void Show();
        bool OverFlow();
    private:
        int count; // should stay between 0 and 9999
        bool error;
};
#endif
