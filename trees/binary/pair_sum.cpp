#include <iostream>
#include <unordered_map>
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

void nodesSumToS(BinaryTreeNode<int> *root, int X, unordered_map<int, int> &present)
{
    if (!root)
        return;

    if (present[X - root->data])
    {
        cout << min(root->data, X - root->data) << " " << max(root->data, X - root->data) << "\n";
    }

    present[root->data]++;
    nodesSumToS(root->left, X, present);
    nodesSumToS(root->right, X, present);
}

void nodesSumToS(BinaryTreeNode<int> *root, int X)
{
    if (!root)
        return;

    unordered_map<int, int> present;
    nodesSumToS(root, X, present);
}