#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void preorderRec(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void preorderItr(TreeNode *root)
{
    stack<TreeNode *> s;
    unordered_map<int, int> m;

    s.push(root);
    m[root->val] += 1;

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        if (!curr)
        {
            s.pop();
            continue;
        }

        if (m[curr->val] == 0)
        {
            cout << curr->val << " ";
            m[curr->val]++;

            s.push(curr->left);
            m[curr->val]++;
            continue;
        }

        if (m[curr->val] == 2)
        {
            s.push(curr->right);
            m[curr->val]++;
            continue;
        }

        if (m[curr->val] > 2)
        {
            s.pop();
            m[curr->val] = 0;
        }
    }
}

void postorderRec(TreeNode *root)
{
    if (!root)
        return;

    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->val << " ";
}

void postorderItr(TreeNode *root)
{
    stack<TreeNode *> s;
    unordered_map<int, int> m;

    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();

        if (!curr)
        {
            s.pop();
            continue;
        }

        if (m[curr->val] == 0)
        {
            m[curr->val]++;
            s.push(curr->left);
            continue;
        }

        if (m[curr->val] == 1)
        {
            m[curr->val]++;
            s.push(curr->right);
            continue;
        }

        if (m[curr->val] == 2)
        {
            m[curr->val]++;
            cout << curr->val << " ";
            s.pop();
        }
    }
}

void inorderRec(TreeNode *root)
{
    if (!root)
        return;
    inorderRec(root->left);
    cout << root->val << " ";
    inorderRec(root->right);
}

void inorderRec(TreeNode *root)
{
    stack<TreeNode *> s;
    unordered_map<int, int> m;

    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();

        if (!curr)
        {
            s.pop();
            continue;
        }

        if (m[curr->val] == 0)
        {
            s.push(curr->left);
            m[curr->val]++;
            continue;
        }

        if (m[curr->val] == 1)
        {
            cout << curr->val << " ";
            m[curr->val]++;
            s.push(curr->right);
            m[curr->val]++;
            continue;
        }

        if (m[curr->val] > 2)
        {
            s.pop();
            m[curr->val] = 0;
        }
    }
}