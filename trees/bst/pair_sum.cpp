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

void printNodesSumToS(BinaryTreeNode<int> *rootS, BinaryTreeNode<int> *rootE, int s)
{
    if (!rootS || !rootE)
        return;
    if (rootS == rootE)
        return;

    printNodesSumToS(rootS->left, rootE->right, s);

    int sum = rootS->data + rootE->data;
    if (sum == s)
    {
        cout << rootS->data << " " << rootE->data << "\n";
    }
    else if (sum < s)
    {
        printNodesSumToS(rootS->right, rootE, s);
    }
    else if (sum > s)
    {
        printNodesSumToS(rootS, rootE->left, s);
    }
    else
    {
        printNodesSumToS(rootS->right, rootE->left, s);
    }
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    // Write your code here
}
