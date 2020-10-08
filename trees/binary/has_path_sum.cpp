#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

int hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return 0;
    if (!root->left && !root->right && sum - root->val == 0)
        return 1;

    int hasLeftPathSum = hasPathSum(root->left, sum - root->val);
    int hasRightPathSum = hasPathSum(root->right, sum - root->val);

    if (hasLeftPathSum || hasRightPathSum)
        return 1;
    return 0;
}