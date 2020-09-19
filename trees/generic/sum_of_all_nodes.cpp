#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
};

int getSum(TreeNode *root)
{
    if (!root)
        return 0;

    queue<TreeNode *> q;
    q.push(root);

    int sum = 0;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        sum += node->data;

        for (TreeNode *child : node->children)
        {
            q.push(child);
        }
    }

    return sum;
}

int getSumRec(TreeNode *root)
{
    if (!root)
        return 0;

    int sum = root->data;

    for (TreeNode *child : root->children)
    {
        sum += getSumRec(child);
    }

    return sum;
}