#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void helper(TreeNode *root, int level, map<int, vector<int>> &traversal)
{
    if (!root)
        return;

    traversal[level].push_back(root->val);
    helper(root->left, level - 1, traversal);
    helper(root->right, level + 1, traversal);
}

void helperLevelOrder(TreeNode *root, map<int, vector<int>> &traversal)
{
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<TreeNode *, int> p = q.front();

        traversal[p.second].push_back(p.first->val);
        if (p.first->left)
            q.push({p.first->left, p.second - 1});
        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }
}