#include "BST.hpp"
#include<iostream>
#include<string>

template<typename T>
BST<T>::BST()
{
    root = nullptr;
}

template<typename T>
bool BST<T>::empty() const
{
    return root == nullptr;
}

template<typename T>
void BST<T>::insert(const T& val)
{
    if (empty())
    {
        root = new BTNode<T>(val);
        return;
    }

    //Iterative approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    while(cur)
    {
        prev = cur;
        if (cur->data > val)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    if (prev->data > val)
    {
        prev->left = new BTNode<T>(val);
    }
    else
    {
        prev->right = new BTNode<T>(val);
    }
}

template<typename T>
void BST<T>::inorder() const
{
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template<typename T>
void BST<T>::inorder(BTNode<T>* node) const
{
    if (!node)
    {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}

template<typename T>
bool BST<T>::isFullTree() const
{
    return isFullTree(root);
}

template<typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const
{
    if (!node) return true; // Empty tree is full
    
    // If a node has exactly one child, it's not a full tree
    if (node->hasOneChild()) return false; 
    
    // Recurse for both children
    return isFullTree(node->left) && isFullTree(node->right);
}

template<typename T>
BTNode<T>* BST<T>::search(const T& val) const
{
    BTNode<T>* cur = root;
    
    while (cur)
    {
        if(cur->data == val) // Found the value
        {
            return cur;
        }
        if(cur->data > val) // Value is less than current
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return nullptr;
}

template<typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const
{
    // If the tree is empty or the root is the value, there is no parent
    if (!root || root->data == val) return nullptr;
    return searchParent(root, val);
}

template<typename T>
BTNode<T>* BST<T>::searchParent(BTNode<T>* node, const T& val) const
{
    if (!node) return nullptr;

    // Check if current node is the parent of the target value
    if ((node->left && node->left->data == val) || 
        (node->right && node->right->data == val)) 
    {
        return node;
    }

    // Standard BST navigation
    if (node->data > val)
        return searchParent(node->left, val);
    else
        return searchParent(node->right, val);
}

template <typename T>
BTNode<T>* BST<T>::getMinNode() const
{
    if (!root)
    {
        return nullptr;
    }
   
    BTNode<T>* cur = root;
   
    while (cur)
    {
        cur = cur->left;
    }
    return cur;
}

template<typename T>
void BST<T>::print() const
{
    std::cout << "========================\n";
    print("", root, false);
    std::cout << "========================\n";
}

template<typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const
{
    if(!node)
    {
        return;
    }
    
    std::cout << prefix;

    if(node != root)
    {
        std::cout << (isRight ? "R----" : "L----");
    }
    else
    {
        std::cout << "---";
    }

    //Print the value of the node
    std::cout << '[' << node->data << ", " << getHeight(node) << "," << getBalance(node) << ']' << std::endl;

    //Go to the next level of the tree
    print(prefix + "  ", node->right, true);
    print(prefix + "  ", node->left, false);
}

template<typename T>
void BST<T>::deleteNode(const T& val)
{
    BTNode<T>* node = search(val);

    if(!node)
    {
        std::cout << "Delete: No value in the BST\n";
        return;
    }
    BTNode<T>* parent = searchParent(val);

    if (node->isLeaf())
    {
        deleteLeaf(node, parent);
    }
    else if (node->hasOneChild())
    {
        deleteNodeWithOneChild(node, parent);
    }
    else
    {
        // The node has 2 children
        deleteNodeWithTwoChild(node);
    }
}

template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent)
{
    BTNode<T>* targetChild;

    if (child->left != nullptr)
    {
        targetChild = child->left;
    }
    else
    {
        targetChild = child->right;
    }

    if (parent == nullptr)
    {
        root = targetChild;
    }
    else
    {
        if (parent->left == child)
        {
            parent->left = targetChild;
        }
        else
        {
            parent->right = targetChild;
        }
    }

    delete child;
}

template<typename T>
void BST<T>::deleteNodeWithTwoChild(BTNode<T>* node)
{
    BTNode<T>* min_right_node = getMinNode(node->right);
    T min_val = min_right_node->data;

    if(min_right_node->isLeaf())
    {
        deleteLeaf(min_right_node, searchParent(min_val));
    }
    else if (min_right_node->hasOneChild())
    {
        deleteNodeWithOneChild(min_right_node, searchParent(min_val));
    }
    node->data = min_val;
}

template<typename T>
int BST<T>::getHeight(const BTNode<T>* node) const
{
    if(!node)
    {
        return 0;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    return(left_height > right_height) ? left_height + 1 : right_height + 1;
}

template<typename T>
int BST<T>::getBalance(const BTNode<T>* node) const
{
    if(!node)
    {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

template<typename T>
void BST<T>::rotateRight(BTNode<T>* & node)
{
    if(!node || !node->left)
    {
        return;
    }
    BTNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    node = left_kid;
}