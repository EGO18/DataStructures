#include "BTNode.hpp"
#include"BST.hpp"
#include"BST.cpp"
#include<iostream>


int main()
{
    // BTNode<int>* root = new BTNode<int> (23);

    BST<int> root;
    root.insert(2);
    root.insert(1);
    root.insert(3);
    root.insert(4);
    root.insert(6);

    root.print();

    //TODO check with search as an assignment
    BTNode<int>* r = root.search(2);
    root.rotateRight(r);
    root.print();

    // root.deleteNode(2);
    // root.print();
    // root.deleteNode(3);
    // root.print();

    //TODO make it work

    // root.inorder();

    //TODO test isFullTree
    // std::cout << "Is Full Tree? " << (root.isFullTree() ? "Yes" : "No") << std::endl;

    //TODO search_parent
    // int target = 3;
    // BTNode<int>* parent = root.searchParent(target);
    // if(parent) {
    //     std::cout << "Parent of " << target << " is: " << parent->data << std::endl;
    // } else {
    //     std::cout << "No parent found for " << target << " (might be root or missing)." << std::endl;
    // }
    
    // root.insert(4);
    // std::cout << "Added 4. Is Full Tree now? " << (root.isFullTree() ? "Yes" : "No") << std::endl;

    // BTNode<int>* node = root.search(2);
    // if(node)
    // {
    //     std::cout << "Found" << std::endl;
    // }

    return 0;
}