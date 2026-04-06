#include"Graph.hpp"
#include<string>

int main()
{
    Graph<std::string> knowledge;

    knowledge.insertVertex("A");
    knowledge.insertVertex("B");
    knowledge.insertVertex("C");
    knowledge.insertVertex("D");
    knowledge.insertVertex("E");
    knowledge.insertVertex("F");
    knowledge.insertVertex("G");
    knowledge.insertVertex("S");

    knowledge.insertEdge("A", "B");
    knowledge.insertEdge("A", "S");
    knowledge.insertEdge("C", "S");
    knowledge.insertEdge("G", "S");
    knowledge.insertEdge("C", "F");
    knowledge.insertEdge("C", "E");
    knowledge.insertEdge("C", "D");
    knowledge.insertEdge("E", "H");
    knowledge.insertEdge("G", "H");

    knowledge.print();
    knowledge.DFS();

    knowledge.BFS();

    std::cout << "A, F" << knowledge.shortestPath("A", "F") << std::endl;
    std::cout << "A, D" << knowledge.shortestPath("A", "D") << std::endl;

    //TODO
    //1. Create a disconnected Graph
    //2. Update DFS to transverse all the nodes of this Graph
    return 0;
}