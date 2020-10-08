#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class augTree
{
public:
    int h;
    bool balanced;
    augTree()
    {
        this->h = 0;
        this->balanced = true;
    }
};

augTree isBalancedUtil(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        augTree node = augTree();
        return node;
    }

    augTree left = isBalancedUtil(root->left);
    augTree right = isBalancedUtil(root->right);

    augTree node = augTree();
    node.h = 1 + max(left.h, right.h);
    if (!left.balanced || !right.balanced || (abs(left.h - right.h) > 1))
    {
        node.balanced = false;
    }
    return node;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    return isBalancedUtil(root).balanced;
}