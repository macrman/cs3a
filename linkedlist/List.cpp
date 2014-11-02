#include "List.h"
#include <iostream>

using namespace std;

/*************************************************************************
 * Constructors/Destructors
 * **********************************************************************/

List::List()
{
    head = NULL;
}

List::List(node * first_node)
{
    head=first_node;
}

List::List(type num)
{
    head = create_new_node(num);
}

List::List(const List& copythis) // copy constructor
{
    head = NULL;
    for(int i=0; i < copythis.length(); i++)
    {
        append(copythis.get(i));
    }
}

List::List(const type new_list[], const int size)
{
    head = NULL;
    for(int c = 0; c < size; c++)
        append(new_list[c]);
}

List::~List()
{
    delete_list();
}

/* ***********************************************************************
 * HELPER FUNCS
 * **********************************************************************/

void List::print()
{
    node * walker = NULL; 
    node * next_node = head;
    while (next_node != NULL)
    {
        walker = next_node;
        next_node = walker->next;
        cout << '[' << walker->item << ']';
    }
    cout << endl << endl;
}

int List::length() const
{

    int count = 0;
    for(node * walk = head; walk != NULL; walk=walk->next)
        count = count +1;
    return count;
}

/*************************************************************************
 * INSERT FUNCS
 * **********************************************************************/

void List::insert_head(type num)
{
    head = create_new_node(num, head);
}

void List::insert(int position, type num)
{
    node * loc = get_node(position-1);
    loc->next = create_new_node(num, loc->next);
}

void List::append(type num)
{
    if (head == NULL)
    {
        head = create_new_node(num);
    }
    else
    {
        node * found = get_last();
        found->next = create_new_node(num);
    }
}

/*************************************************************************
 * DELETE FUNCS
 * **********************************************************************/

void List::del(const int position)
{
    node * target = get_node(position);
    if (target == head)
    {
        head = target->next;
        delete [] target;
    }
    else
    {
        node * previous_node = prev(target);
        previous_node->next = target->next;
        delete [] target;
    }
}

void List::del_head()
{
    del(0);
}

void List::del_last()
{
    del(length()-1);
}

void List::delete_list()
{
    node * next_node = head;
    node * walker;
    while(next_node != NULL)
    {
        walker = next_node;
        next_node = walker->next;
        delete [] walker;
    }
    head = NULL;
}

/*************************************************************************
 * GETTER FUNCS
 * **********************************************************************/

type List::get(const int position) const
{
    node * target = get_node(position);
    return target->item;
}

int List::search(type query, int start, int end)
{
    int count = start;

    if (end<0)
        end = end + length();

    for(node * walk = get_node(count); count < end; count++)
    {
        if (walk->item == query)
            return count;
        walk=walk->next;
    }
    return -1;
}

type& List::index(int position)
{
    node * target = get_node(position);
    return target->item;
}
/* OP OVERLOAD ***************************************************/

List List::operator=(const List & rhs)
{
    if (this == &rhs)
        return *this;
    if (head)
        delete_list();
    for(int i=0; i < rhs.length(); i++)
        append(rhs.get(i));
    return *this;
}

type& List::operator[](const int position)
{
    int pos = position;
    return index(pos);
}

/*************************************************************************
 * POINTER FUNCS
 * **********************************************************************/

node * List::get_node(const int position) const
{
    node * walk = head;
    int pos;
    if(position < 0)
    {
        pos = position + length();
    }
    else
    {
        pos = position;
    }
    for(int c=0; c != pos; c++)
        walk=walk->next;
    return walk;
}

node * List::prev(node * target)
{
    node * walk = NULL;
    for (walk = head; walk != NULL; walk = walk->next)
    {
        if (walk->next == target)
            return walk;
    }
    return walk;
}

node * List::get_first()
{
    return head;
}

node * List::get_last()
{
    node * walk = NULL;
    for(walk = head; walk != NULL; walk = walk->next)
    {
        if( walk->next == NULL)
        {
            return walk; 
        }
    }
    return NULL;
}

node * List::create_new_node(type num, node * next_node)
{
    node * new_node = new node;
    new_node->item = num;
    new_node->next = next_node;
    return new_node;
}

node * List::find(const type num)
{
    node * walk = NULL;
    for(walk = head; walk != NULL; walk = walk->next)
    {
        if (walk->item == num)
            return walk;
    }
    return walk;
}

node * List::find(node * pointer)
{
    node * walk = NULL;
    for (walk = head; walk != NULL; walk = walk->next)
    {
        if (walk == pointer)
            return walk;
    }
    return walk;
}
