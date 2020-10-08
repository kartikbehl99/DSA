#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool helper(TreeNode *root, int node, vector<int> &path)
{
    if (!root)
        return false;
    if (root->val == node)
    {
        path.push_back(node);
        return true;
    }
    bool hasPathOnLeft = helper(root->left, node, path);
    bool hasPathOnRight = helper(root->right, node, path);

    if (hasPathOnLeft || hasPathOnRight)
    {
        path.push_back(root->val);
        return true;
    }
    return false;
}

vector<int> solve(TreeNode *root, int B)
{
    vector<int> path;
    helper(root, B, path);
    reverse(path.begin(), path.end());
    return path;
}