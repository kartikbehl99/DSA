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

void helper(TreeNode *root, TreeNode *parent, int node, int k, vector<int> &v)
{
    if (!root)
        return;
    if (k == 0)
    {
        if (parent)
        {
            if (parent->left)
                if (parent->left->val == node)
                    return;
            if (parent->right)
                if (parent->right->val == node)
                    return;
            v.push_back(root->val);
        }
        return;
    }

    helper(root->left, root, node, k - 1, v);
    helper(root->right, root, node, k - 1, v);
}

bool findLevel(TreeNode *root, int node, int &level)
{
    if (!root)
        return 0;
    if (root->val == node)
        return true;
    bool left = findLevel(root->left, node, level);
    bool right = findLevel(root->right, node, level);
    if (left || right)
        level += 1;
    return left || right;
}

vector<int> solve(TreeNode *root, int node)
{
    vector<int> ans;
    int level = 0;
    findLevel(root, node, level);
    helper(root, NULL, node, level, ans);
    return ans;
}