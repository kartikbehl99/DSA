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

void zigZagTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    stack<BinaryTreeNode<int> *> currLevel;
    stack<BinaryTreeNode<int> *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        BinaryTreeNode<int> *node = currLevel.top();
        currLevel.pop();

        cout << node->data << " ";

        if (leftToRight)
        {
            if (node->left)
                nextLevel.push(node->left);
            if (node->right)
                nextLevel.push(node->right);
        }
        else
        {
            if (node->right)
                nextLevel.push(node->right);
            if (node->left)
                nextLevel.push(node->left);
        }
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            stack<BinaryTreeNode<int> *> temp = currLevel;
            currLevel = nextLevel;
            nextLevel = temp;
        }
    }
}