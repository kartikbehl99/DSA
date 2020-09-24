#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
};

TreeNode<int> *maxSumNodeItr(TreeNode<int> *root)
{
    if (!root)
        return NULL;

    queue<TreeNode<int> *> q;

    q.push(root);

    int maxSum = INT_MIN;
    TreeNode<int> *maxNode = NULL;
    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        int sum = node->data;

        for (TreeNode<int> *child : node->children)
        {
            sum += child->data;
            q.push(child);
        }

        if (maxSum < sum)
        {
            maxNode = node;
            maxSum = sum;
        }
    }

    return maxNode;
}