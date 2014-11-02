#include <cstddef>
#include <iostream>

using namespace std;

//
// todo
// ====

template <typename type> class BaseList 
{
    private:
        /* **************************************************************
         * NODE
         * **************************************************************/
        class Node
        {
            public:
                friend class BaseList;
                friend class Iterator;
                type data;
            private:
                Node * next_node;
                Node * prev_node;
        };
        // PRIVATE VARS
        Node * head;
        Node * tail;
        /* **************************************************************
         * UNSAFE FUNCS
         * **************************************************************/
        // these functions (which only deal w/pntrs) are unsafe because
        // they do no checking. Ex. del(node*) does no checking to see if
        // it even exists, but the del(int) does. these funcs are called 
        // by safe funcs after checking Ex. del(int) calls del(node*) 
        // after checking that target exists.
        void insert_before(Node * next_one, Node * insert_me)
        {
            // get the prev one;
            Node * prev_one = next_one->prev_node;

            // if theres no prev (we're inserting before what head pnts 
            // to... aka we're inserting in the beginning)
            if (head == next_one)
            {
                // set our prev to null, cuz we're the first one
                insert_me->prev_node = NULL;
                // point head to us
                head = insert_me;
            }
            else
            {
                // point the prev one to us
                prev_one->next_node = insert_me;
                // point our prev to the prev one
                insert_me->prev_node = prev_one;
            }
            // point the next one to us
            next_one->prev_node = insert_me;
            // point our next to the next one
            insert_me->next_node = next_one;
            return;
        }
        void insert_after(Node * prev_one, Node * insert_me)
        {
            // get the next one
            Node * next_one = prev_one->next_node;
            // if there's no next, (we're inserting after what tail pnts
            // to aka appending)
            if (tail == prev_one)
            {
                // point us to null cuz we're the last one
                insert_me->next_node = NULL;
                // point tail to us
                tail = insert_me;
            }
            else
            {
                // point the next one to us
                next_one->prev_node = insert_me;
                // point to the next one
                insert_me->next_node = next_one;
            }
            // point to the prev one
            insert_me->prev_node = prev_one;
            // point the prev one to us
            prev_one->next_node = insert_me;
            return;
        }
        void insert_into_empty_list(Node * node_pntr)
        {
            head = node_pntr;
            tail = node_pntr;
            node_pntr->prev_node = NULL;
            node_pntr->next_node = NULL;
        }
        void del(Node * node)
        {
            // get the next one
            Node * next_one = node->next_node;
            // get the prev one
            Node * prev_one = node->prev_node;

            if(node == head)
            {
                head = next_one;
                next_one->prev_node = NULL;
            }
            else if (node == tail)
            {
                tail = prev_one;
                prev_one->next_node = NULL;
            }
            else
            {
                prev_one->next_node = next_one;
                next_one->prev_node = prev_one;
            }
            delete [] node;
        }

    public:
        /* **************************************************************
         * CONSTRUCTORS / DESTRUCTORS / OP OVERLOAD
         * **************************************************************/
        BaseList()
        {
            head = NULL;
            tail = NULL;
        }
        ~BaseList()
        {
            Node * walker = NULL;
            Node * next_one = NULL;
            for(walker=head; walker != NULL; walker=next_one)
            {
                next_one = walker->next_node;
                delete [] walker;
            }
        }

        BaseList(type init_list[], int size)
        {
            Node * walk = NULL;

            for(int i = 0; i < size; i++)
            {
                // finish this
                next = create_new_node(init_list[i])
            }

        }
        // copy constructor
        BaseList(const BaseList& copy_me)
        {
            head = NULL;
            tail = NULL;
            tail = copy_nodes(head, copy_me.head);
        }
        BaseList& operator = (const BaseList& rhs)
        {
            if (this != &rhs)
            {
                // delete old stuff
                if (this->head)
                {
                    this->del_list(this->head);
                    this->head = NULL;
                    this->tail = NULL;
                }
                // copy contents
                this->tail = copy_nodes(this->head, rhs.head);
            }
            return *this;
        }

        type& operator [] (const int position)
        {
            return (get_node(position)->data);
        }

        /****************************************************************
         * INSERT FUNCS
         * **************************************************************/
        void prepend(const type item)
        {
            Node * node = create_node(item);
            if (is_empty())
                insert_into_empty_list(node);
            else
                insert_before(head, node);
        }
        void append(const type item)
        {
            Node * node = create_node(item);
            if (is_empty())
                insert_into_empty_list(node);
            else
                insert_after(tail, node);
        }
        void insert(const int position, const type item)
        {
            // catch exceptions?
            Node * insert_me = create_node(item);
            Node * next_one = get_node(position);
            insert_before(next_one, insert_me);
            return;
        }
        // test this
        void insert_ascend(type insert_me)
        {
            Node * walk = NULL;
            for(walk = head; walk !=NULL; walk=walk->next)
            {
                if (walk->item > insert_me)
                {
                    Node * node = create_node(insert_me);
                    insert_after(walk, node);
                }
            }
        }
        // test this
        void insert_descend(type insert_me)
        {
            Node * walk = NULL;
            for(walk = head; walk !=NULL; walk=walk->next)
            {
                if (walk->item < insert_me)
                {
                    Node * node = create_node(insert_me);
                    insert_before(walk, node);
                }
            }
        }

        /* **************************************************************
         * GETTERS
         * **************************************************************/
        type get(const int position)
        {
            Node * node = get_node(position);
            return node->data;
        }
        Node * get_node(int position) const
        {
            if(position >= len() || position < len() * -1)
            {
                // replace w/ exception
                cout << "OUT OF BOUNDS" << endl;
            }
            Node * walk = head;
            int pos;
            if(position < 0)
            {
                pos = position + len();
            }
            else
            {
                pos = position;
            }
            for(int c=0; c != pos; c++)
                walk=walk->next_node;
            return walk;
        }
        Node * find_node_pntr(Node * node) // returns NULL if not found
        {
            Node * walker = NULL;
            for(walker = head; walker != NULL; walker = walker->next_node)
            {
                if (walker == node)  
                {
                    return walker;
                }
            }
            return walker;
        }

        /****************************************************************
         * HELPERS
         * **************************************************************/
        Node * create_node(type item)
        {
            Node * node = new Node;
            node->data = item;
            node->next_node = NULL;
            node->prev_node = NULL;
            return node;
        }
        bool is_empty()
        {
            if(!head && !tail)
                return true;
            return false;
        }
        int len() const
        {
            int count = 0;
            for(Node * walk = head; walk != NULL; walk = walk->next_node)
                count = count + 1;
            return count;
        }
        void print()
        {
            Node * walker = NULL; 
            Node * next_one = head;
            cout << "[head: " << head << ']' << endl << endl;
            while (next_one != NULL)
            {
                walker = next_one;
                next_one = walker->next_node;
                cout << "prev: " << walker->prev_node << endl;
                cout << "val: " << walker->data << endl;
                cout << "mem: " << walker << endl;
                cout << "next: " << walker->next_node << endl;
                cout << endl;
            }
            cout << "[tail: " << tail << "]\n";
            cout << endl << endl;
        }

        Node * copy_nodes(Node * & copy_to, Node * copy_from)
        {
            // what if it's size 0
            if(!copy_to && !copy_from)
                return NULL;

            // first one, passing in null head
            if (!copy_to && copy_from)
            {
                // copy the first one
                copy_to = create_node(copy_from->data);
                copy_to->prev_node = NULL;
                return copy_nodes(copy_to, copy_from->next_node);
            }
            else if (copy_to && copy_from)
            {
                Node * next_one = create_node(copy_from->data);
                next_one->prev_node = copy_to;
                copy_to->next_node = next_one;
                return copy_nodes(next_one, copy_from->next_node);
            }
            else if (!copy_from)
            {
                copy_to->next_node = NULL;
                return copy_to;
            }
        }

        /* **************************************************************
         * DELETERS
         * **************************************************************/
        void del(int pos)
        {
            Node * node = get_node(pos);
            // if null? / catch exception?
            del(node);
        }
        void del_first()
        {
            del(head);
        }
        void del_last()
        {
            del(tail);
        }
        void del_list(Node * &node)
        {
            if(node->next_node)
            {
                del_list(node->next_node);
            }
            delete [] node;
        }

        /* **************************************************************
         * ITERATOR
         * **************************************************************/
        class Iterator
        {
            private:
                Node * node;
            public:
                Iterator()
                {
                    node = NULL;
                }
                // make this a private constructor?
                Iterator(Node * init_node)
                {
                    node = init_node;
                }

                type& operator *(){
                    return (node->data);
                }
                Iterator operator ++()
                {
                    //exception or just do nothing?
                    node = node->next_node;
                    return *this;
                }
                Iterator operator ++(int)
                {
                    //exception or just do nothing?
                    node = node->next_node;
                    return *this;
                }
                Iterator operator --()
                {
                    //exception or just do nothing?
                    node = node->prev_node;
                    return *this;
                }
                Iterator operator --(int)
                {
                    //exception or just do nothing?
                    node = node->prev_node;
                    return *this;
                }
        }; // end iterator class
        // iterator funcs
        Iterator begin()
        {
            Iterator iter(head);
            return iter;
        }
        Iterator end()
        {
            Iterator iter(tail);
            return iter;
        }
}; // end list class
