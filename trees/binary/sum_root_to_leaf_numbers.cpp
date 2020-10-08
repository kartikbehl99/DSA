#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void helper(TreeNode *root, long long number, int &sum)
{
    if (!root)
    {
        sum += number % 1003;
        sum %= 1003;
        return;
    }

    number *= 10;
    number += root->val;
    helper(root->left, number, sum);
    helper(root->right, number, sum);
}

int sumNumbers(TreeNode *root)
{
    int sum = 0;
    int number = 0;

    helper(root, number, sum);
    return sum;
}