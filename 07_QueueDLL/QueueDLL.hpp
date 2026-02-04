#ifndef QUEUEDLL_H
#define QUEUEDLL_H
#include"DLList.hpp"

template <typename T>
class QueueDLL {
    public:
        QueueDLL();
        int length() const; // TODO
        bool empty() const;
        bool full() const;
        void print() const;
        void clear(); // TODO
       
        void enqueue(const T& val);
        const T& dequeue(); // Throws std::out_of_range exception
        const T& front(); // Return the first element in the queue
    private:
        DLList<T>* data;

};
#endif
