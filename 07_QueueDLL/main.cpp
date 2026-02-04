#include"QueueDLL.hpp"
#include"QueueDLL.cpp"

int main()
{
    QueueDLL<int> q;

    q.enqueue(1);

    q.print();
}