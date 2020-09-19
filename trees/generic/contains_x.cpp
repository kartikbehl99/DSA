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

bool containsXRec(TreeNode<int> *root, int x)
{
    if (!root)
        return false;

    if (root->data == x)
        return true;

    for (TreeNode<int> *child : root->children)
    {
        if (containsXRec(child, x))
            return true;
    }

    return false;
}

bool containsXItr(TreeNode<int> *root, int x)
{
    if (!root)
        return false;

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();
        if (node->data == x)
            return true;

        for (TreeNode<int> *child : node->children)
        {
            q.push(child);
        }
    }

    return false;
}