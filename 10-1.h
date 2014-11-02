// 10.1-10.2
class Grades
{
    public:
        //constructors
        Grades(int quiz_one);
        Grades(int quiz_one, int quiz_two);
        Grades(int quiz_one, int quiz_two, int midterm);
        Grades(int quiz_one, int quiz_two, int midterm, int finalEx);
        //mutators
        void set(int assign, int score); // sets an score to an assignment
        //accessors
        double calc_avg_score();
        char final_letter_grade();
    private:
        int quiz_one;
        int quiz_two;
        int midterm;
        int finalEx;
};

// 10.3-10.4
class CDAccount
{
    public:
        //constructors
        CDAccount(double init_bal; double int_rate; int term);
        //mutators
        double calc_new_bal();
        //acessors
        double get_init_bal();
        int get_int_rate();
    private:
        double init_bal;
        double new_bal;
        double int_rate;
        int term;
};

// 10.5
class Counter
{
    public:
        //constructors
        Month();
        //mutators
        void increment();
        void decrement();
        //accessors
        void show();
        void stream(ostream& a);
    private:
        int counter;
};

//10.6
class Month
{
    public:
        //constructors
        Month();
        Month(int m);
        //mut
        //accessors
        void input_eng_month();
        Month get_next_month();
        int get_month();
    private:
        int month;
};
