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

int getHeight(TreeNode<int> *root)
{
    if (!root)
        return 0;

    int height = INT_MIN;

    for (TreeNode<int> *child : root->children)
    {
        height = 1 + max(height, getHeight(child));
    }

    return height;
}