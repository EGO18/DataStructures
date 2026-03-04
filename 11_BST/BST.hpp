#ifndef BTS_HPP
#define BTS_HPP
#include "BTNode.hpp"
#include<string>

template<typename T>
class BST
{
    public:
        BST();

        bool empty() const;
        void insert(const T& val);

        //Travesals of the tree
        void inorder() const;
        void preorder() const;
        void postorder() const;

        bool isFullTree() const;
        BTNode<T>* getMinNode () const;
        void deleteNode(const T& val);

        BTNode<T>* search(const T& val) const;
        BTNode<T>* searchParent(const T& val) const;

        void print() const;

        int getHeight(const BTNode<T>* node) const;
        int getBalance(const BTNode<T>* node) const;

        void rotateRight(BTNode<T>* & node);

    private:
        BTNode<T>* root;
        void inorder(BTNode<T>* node) const;
        bool isFullTree(BTNode<T>* node) const;
        BTNode<T>* searchParent(BTNode<T>* node, const T& val) const;
        void preorder(BTNode<T>* node) const;
        void postorder(BTNode<T>* node) const;
        BTNode<T>* getMinNode (BTNode<T>* node) const;
        void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
        void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);
        void deleteNodeWithTwoChild(BTNode<T>* node);

        void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
};


#endif