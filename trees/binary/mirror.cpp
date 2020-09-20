#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void mirrorBT(TreeNode<int> *root)
{
    if (!root)
        return;

    mirrorBT(root->left);
    mirrorBT(root->right);

    TreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;
}