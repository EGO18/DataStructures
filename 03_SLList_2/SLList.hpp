#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.hpp"

class SLList
{
    public:
        // No-arg constructor
        SLList();

        // The copy constructor (TODO)
        SLList(const SLList& other);

        // Assignment operator (TODO)
        SLList& operator = (const SLList& other);

        // The destructor
        ~SLList();

        unsigned size() const; // Returns the size of the list
        bool empty() const; // Returns true if list is empty
        void push_front(int val); // Insert the new node at the beginning
        void print() const; // Print the list
        // TODO
        void push_back(int val); // Insert the new node at the end

        void pop_front(); // Remove the first element (node)
        void clear(); // Clear the list

        //TODO
        void pop_back(); // Remove the last element (node)

    private:
        SLLNode* head;
        SLLNode* tail;
        unsigned list_size;
};

#endif