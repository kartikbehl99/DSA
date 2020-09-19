#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
};

TreeNode<int> *maxDataNodeItr(TreeNode<int> *root)
{
    if (!root)
        return NULL;

    queue<TreeNode<int> *> q;
    q.push(root);

    TreeNode<int> *maxNode = NULL;

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();
        if (!maxNode)
        {
            maxNode = node;
        }
        else
        {
            maxNode = maxNode->data >= node->data ? maxNode : node;
        }

        for (TreeNode<int> *child : node->children)
        {
            q.push(child);
        }
    }
}

TreeNode<int> *maxDataNodeRec(TreeNode<int> *root)
{
    if (!root)
        return NULL;

    TreeNode<int> *maxNode = root;
    for (TreeNode<int> *child : root->children)
    {
        TreeNode<int> *tempNode = maxDataNodeRec(child);
        maxNode = maxNode->data >= tempNode->data ? maxNode : tempNode;
    }

    return maxNode;
}