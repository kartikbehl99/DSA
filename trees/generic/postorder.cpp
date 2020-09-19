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

void postorder(TreeNode<int> *root)
{
    if (!root)
        return;

    for (TreeNode<int> *child : root->children)
    {
        postorder(child);
    }

    cout << root->data << " ";
}