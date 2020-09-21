#include <iostream>
#include <vector>
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

template <typename T>
class node
{
public:
    T data;
    node *next;
    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void levelWiseLLUtil(BinaryTreeNode<int> *root, int level, vector<vector<node<int> *>> &levels)
{
    if (!root)
    {
        return;
    }

    node<int> *newNode = new node<int>(root->data);
    if (levels.size() > level)
    {
        if (levels[level].size() > 0)
        {
            if (levels[level][0])
            {
                levels[level][1]->next = newNode;
                levels[level][1] = newNode;
            }
            else
            {
                levels[level][0] = levels[level][1] = newNode;
            }
        }
        else
        {
            levels[level].push_back(newNode);
            levels[level].push_back(newNode);
        }
    }

    else
    {
        levels.push_back({newNode, newNode});
    }

    levelWiseLLUtil(root->left, level + 1, levels);
    levelWiseLLUtil(root->right, level + 1, levels);
}

vector<node<int> *> levelWiseLL(BinaryTreeNode<int> *root)
{
    vector<vector<node<int> *>> levels;
    levelWiseLLUtil(root, 0, levels);

    vector<node<int> *> levelHeads;

    for (vector<node<int> *> level : levels)
    {
        levelHeads.push_back(level[0]);
    }

    return levelHeads;
}