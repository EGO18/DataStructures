#include"QueueArray.hpp"
#include"QueueArray.cpp"

int main()
{
    QueueArray<int, 10> q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    q.print();

    while(!q.empty())
    {
        std::cout << q.dequeue() << std::endl;
    }

    try
    {
        q.dequeue();
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    

    return 0;
}