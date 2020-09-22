#include <iostream>
#include <vector>
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

bool isLeaf(BinaryTreeNode<int> *root)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return true;
    return false;
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int> path)
{
    if (!root || k < 0)
        return;

    path.push_back(root->data);

    if (k - root->data == 0 && isLeaf(root))
    {
        int size = path.size();
        for (int i = 0; i < size; i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }

    rootToLeafPathsSumToK(root->left, k - root->data, path);
    rootToLeafPathsSumToK(root->right, k - root->data, path);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    vector<int> path;
    rootToLeafPathsSumToK(root, k, path);
}