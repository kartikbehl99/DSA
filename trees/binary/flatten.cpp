#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void insertToRight(TreeNode *root, TreeNode *temp)
{
    if (!root)
        return;
    if (!root->right)
    {
        root->right = temp;
        return;
    }
    insertToRight(root->right, temp);
}

TreeNode *flatten(TreeNode *root)
{
    if (!root)
        return root;

    root->left = flatten(root->left);
    root->right = flatten(root->right);

    if (root->left)
    {
        TreeNode *temp = root->left;
        root->left = NULL;
        TreeNode *tempRight = root->right;
        root->right = temp;
        insertToRight(temp, tempRight);
    }
    return root;
}