#include <iostream>
#include <climits>
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

#include <bits/stdc++.h>
using namespace std;

class BST
{
public:
    bool isBST;
    int height;
    int maxHeight;

    BST(bool isBST)
    {
        this->isBST = isBST;
        height = 0;
        maxHeight = INT_MIN;
    }
};

bool isStillBST(int data, BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left && right)
    {
        return data > left->data && data < right->data;
    }
    if (left)
    {
        return data > left->data;
    }
    if (right)
    {
        return data < right->data;
    }
    return true;
}

BST largestBSTSubtreeUtil(BinaryTreeNode<int> *root, int minNode, int maxNode)
{
    if (!root)
    {
        BST bst = BST(true);
        return bst;
    }

    BST left = largestBSTSubtreeUtil(root->left, minNode, root->data);
    BST right = largestBSTSubtreeUtil(root->right, root->data, maxNode);

    if (left.isBST && right.isBST)
    {
        if (isStillBST(root->data, root->left, root->right))
        {
            BST bst = BST(true);
            bst.height = max(left.height, right.height) + 1;
            bst.maxHeight = bst.height;
            return bst;
        }
    }

    BST bst = BST(false);
    bst.height = max(left.height, right.height) + 1;
    bst.maxHeight = max(left.maxHeight, right.maxHeight);
    return bst;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBSTSubtreeUtil(root, INT_MIN, INT_MAX).maxHeight;
}