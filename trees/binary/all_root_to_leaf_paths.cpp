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

void helper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &allPaths)
{
    if (!root)
        return;
    if (!root->left && !root->right && (sum - root->val == 0))
    {
        path.push_back(root->val);
        allPaths.push_back(path);
        return;
    }
    path.push_back(root->val);
    helper(root->left, sum - root->val, path, allPaths);
    helper(root->right, sum - root->val, path, allPaths);
}

vector<vector<int>> allPaths(TreeNode *root, int sum)
{
}