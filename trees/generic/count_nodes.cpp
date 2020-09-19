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

int getCountRec(TreeNode<int> *root, int x)
{
    if (!root)
        return 0;

    int count = root->data > x ? 1 : 0;

    for (TreeNode<int> *child : root->children)
    {
        if (child->data > x)
        {
            count += 1 + getCountRec(child, x);
        }
        else
        {
            count += getCountRec(child, x);
        }
    }

    return count;
}