#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *solve(TreeNode *root)
{
    if (!root)
        return NULL;
    if (!root->left && !root->right)
        return root;

    root->left = solve(root->left);
    root->right = solve(root->right);

    if (!root->left || !root->right)
    {
        if (!root->left)
        {
            return root->right;
        }
        else
        {
            return root->left;
        }
    }
    return root;
}