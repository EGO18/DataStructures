#include "SLList.hpp"
#include <iostream>

SLList::SLList()
{
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

SLList::~SLList()
{
    clear();
}

unsigned SLList::size() const
{
    return list_size;
}

bool SLList::empty() const
{
    return(size() == 0);
}

void SLList::push_front(int val)
{
    // Add new node at the beginning 
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    // Alternative way
    head = new SLLNode(val, head);

    // Increase the list size
    list_size++;

    if (size() == 1)
    {
        tail = head;
    }
}

// void SLList::push_back(int val)
// {
//     if(empty ())
//     {
//         head = new SLLNode(val);
//     }
//     else
//     {
//         SLLNode* cur = head;
//         while (cur->next)
//         {
//             cur = cur->next;
//         }
//         cur->next = new SLLNode(val);
//     }
// }

void SLList::print() const
{
    std::cout << "{ ";

    SLLNode* cur = head;

    while (cur) 
    {
        std::cout << cur->data;
        if (cur->next)
        {
            std::cout << " -> ";
        }
        cur = cur->next; // Goes to the next node
    }
    std::cout << " }\n";
}

void SLList::push_back(int val)
{
    if(empty())
    {
        push_front(val);
        return;
    }
    tail->next = new SLLNode(val); // Add the node to the end
    tail = tail->next; // Move the tail

    list_size++;
}

 void SLList::pop_front()
 {
    if(!empty())
    {
        SLLNode* old_head = head;
        head = head->next;

        delete old_head; // Free the memory

        list_size--;
        if(empty())
        {
            tail = head;
        }
    }
 }

 void SLList::clear()
 {
    while (!empty())
    {
        pop_front();
    }
    
 }
 