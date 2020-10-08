#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void invertTree(TreeNode *root)
{
    if (!root)
        return;

    invertTree(root->left);
    invertTree(root->right);
    TreeNode *tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;
}