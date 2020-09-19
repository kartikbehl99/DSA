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

void levelOrderItr(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        cout << node->data << " ";

        for (TreeNode *child : node->children)
        {
            q.push(child);
        }
    }
}