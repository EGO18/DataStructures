#ifndef BTS_HPP
#define BTS_HPP
#include "BTNode.hpp"

template<typename T>
class BST
{
    public:
        BST();

        bool empty() const;
        void insert(const T& val);

        //Travesals of the tree
        void inorder() const;
    private:
        BTNode<T>* root;
        void inorder(BTNode<T>* node) const;
};


#endif