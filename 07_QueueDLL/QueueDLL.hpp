#ifndef QUEUEDLL_H
#define QUEUEDLL_H
#include"DLList.hpp"

template <typename T>
class QueueDLL {
    public:
        int size() const; // TODO
        bool empty() const;
        void print() const;
        void clear(); // TODO
       
        void enqueue(const T& val);
        T dequeue(); // Throws std::out_of_range exception
        const T& front() const; // Return the first element in the queue
    private:
        DLList<T> data;

};
#endif
