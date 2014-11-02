#ifndef list_h
#define list_h
#include <cstddef> //NULL in default arg

using namespace std;

typedef int type;

struct node
{
    int item;
    node * next;
};

class List
{
    public:
        /* CONSTRUCTORS **************************************************/
        List(); // default constructer
        List(node * first_node); // constructer w/ a node
        List(type num); // constructer w/ an int
        List(type const new_list[], const int size);
        List(const List& copythis); // copy constructor

        /* DESTRUCTORS ***************************************************/
        ~List();

        /* HELPER FUNCS **************************************************/
        void print();
        int length() const;

        /* INSERT FUNCS **************************************************/
        void insert_head(type num); //insert w/num
        void insert(int position, type num);
        void append(type num);

        /* DELETE FUNCS **************************************************/
        void del(const int position);
        void del_head();
        void del_last();
        void delete_list();

        /* GETTER FUNCS **************************************************/
        type get(const int position) const;
        int search(type query, int start=0, int end=-1);

        // warning! retruns a reference!
        type& index(const int position);


        /* OP OVERLOAD ***************************************************/
        List operator=(const List & rhs);
        type& operator[](const int position);

        /******************************************************************
        * POINTER FUNCS  
        ******************************************************************
        *   These functions should not be used at a higher level (or by
        *   other classes that inherit from this) In fact, they should be
        *   made private.
        */

        // helpers
        node * get_node(int position) const;
        node * create_new_node(type num, node * next_node=NULL);

        // getters
        node * get_first();
        node * get_last();
        node * find(type const num);
        node * find(node * pointer);
        node * prev(node *);

        // insert funcs

    private:
        node* head;
};

#endif
