#ifndef MIN_HEAP
#define MIN_HEAP
#include <vector>

template<typename T>
class MinHeap
{
    public:
        void insert(const T& val);
        void print() const;

    private:
        std::vector<T> data;
        void percolateUp();
};


#endif