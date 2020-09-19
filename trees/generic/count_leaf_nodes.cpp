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
    vector<TreeNode<T> *> children;
};

int countLeafNodesRec(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (!root->children.size())
        return 1;

    int count = 0;
    for (TreeNode<int> *child : root->children)
    {
        count += countLeafNodesRec(child);
    }

    return count;
}

int countLeadNodesItr(TreeNode<int> *root)
{
    int count = 0;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();

        if (!node->children.size())
            count++;

        for (TreeNode<int> *child : node->children)
        {
            q.push(child);
        }
    }

    return count;
}