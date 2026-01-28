#include "SLList.hpp"
#include "SLList.cpp"
#include <string>

int main()
{
    SLList <std::string> list;
    list.push_front("abc");
    list.push_front("edf");
    list.push_front("123");
    list.push_front("hello");

    list.print();
    return 0;
}