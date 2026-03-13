#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include<iostream>
#include<cstdlib>

int main ()
{
    MinHeap<int> heap;

    for(int i = 0; i < 10; i++)
    {
        heap.insert(rand() % 1000);
    }

    return 0;
}