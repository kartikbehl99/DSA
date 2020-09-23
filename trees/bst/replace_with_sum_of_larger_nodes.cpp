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

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int &sum)
{
    if (!root)
        return;

    replaceWithLargerNodesSum(root->right, sum);
    int temp = root->data;
    root->data += sum;
    sum += temp;
    replaceWithLargerNodesSum(root->left, sum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    int sum = 0;
    replaceWithLargerNodesSum(root, sum);
}