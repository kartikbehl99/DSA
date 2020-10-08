#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void rightView(TreeNode *root, int currLevel, int &maxLevel)
{
    if (!root)
        return;
    if (currLevel > maxLevel)
    {
        cout << root->val << " ";
        maxLevel = currLevel;
    }

    rightView(root->right, currLevel + 1, maxLevel);
    rightView(root->left, currLevel + 1, maxLevel);
}

void solve(TreeNode *root)
{
    int maxLevel = -1;
    rightView(root, 0, maxLevel);
}