#include"QueueDLL.hpp"

template<typename T>
void QueueDLL<T>::QueueDLL()
{
    data = new DLList<T>;
}

void QueueDLL<T>::enqueue(const T& val)
{
    data.push_back(val);
}

template<typename T>
void QueueDLL<T>::print() const
{
    data.print_backwards();
}

template<typename T>
void QueueDLL<T>::size() const
{
    return data.size();
}

template<typename T>
void QueueDLL<T>::empty() const
{
    return data.empty();
}

template<typename T>
void QueueDLL<T>::clear()
{
    data.clear();
}

template<typename T>
T QueueDLL<T>::dequeue()
{
    if (!empty())
    {
        T temp = data.front();
        data.pop_front();
        return temp;
    }

}

template<typename T>
const T& QueueDLL<T>::front() const
{
    return data.front();
}