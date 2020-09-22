#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class Path
{
public:
    bool val1Path;
    bool val2Path;
    BinaryTreeNode<int> *lca;

    Path()
    {
        val1Path = false;
        val2Path = false;
    }

    Path(bool val1Path, bool val2Path)
    {
        this->val1Path = val1Path;
        this->val2Path = val2Path;
    }
};

Path lcaBinaryTreeUtil(BinaryTreeNode<int> *root, int val1, int val2)
{
    if (!root)
    {
        Path p = Path();
        p.lca = NULL;
        return p;
    }

    Path left = lcaBinaryTreeUtil(root->left, val1, val2);
    Path right = lcaBinaryTreeUtil(root->right, val1, val2);

    if (root->data == val1 && root->data == val2)
    {
        Path p = Path(true, true);
        p.lca = root;
        return p;
    }

    if (root->data == val1)
    {
        Path p = Path(true, false);
        p.lca = root;
        if (left.val2Path || right.val2Path)
            p.val2Path = true;
        return p;
    }

    if (root->data == val2)
    {
        Path p = Path(false, true);
        p.lca = root;
        if (left.val1Path || right.val1Path)
            p.val1Path = true;
        return p;
    }

    if (left.val1Path && left.val2Path)
    {
        return left;
    }
    else if (right.val1Path && right.val2Path)
    {
        return right;
    }
    else if ((left.val1Path && right.val2Path) || (left.val2Path && right.val1Path))
    {
        Path p = Path(true, true);
        p.lca = root;
        return p;
    }
    Path p = Path(left.val1Path || right.val1Path, left.val2Path || right.val2Path);
    p.lca = NULL;
    return p;
}

int lcaBinaryTree(BinaryTreeNode<int> *root, int val1, int val2)
{
    BinaryTreeNode<int> *lca = NULL;

    Path p = lcaBinaryTreeUtil(root, val1, val2);
    return p.lca != NULL ? p.lca->data : -1;
}