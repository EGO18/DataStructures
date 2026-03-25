#ifndef MIN_HEAP
#define MIN_HEAP
#include <vector>

template<typename T>
class MinHeap
{
    public:
        //Constructors
        MinHeap();
        MinHeap(const std::vector<T>& v);
        void insert(const T& val);
        void print() const;


        T deleteMin();

    private:
        std::vector<T> data;
        void heapify();

        void percolateUp();
        void percolateDown(int i = 0);
        int getLeftKidIndex(int i);
        int getRightKidIndex(int i);
        int getParentKidIndex(int i);
        int getLastWithKidsIndex();
};


#endif