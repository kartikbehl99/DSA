#include <iostream>
using namespace std;

class TreeLinkNode
{
public:
    int val;
    TreeLinkNode *left, *right, *next;
};

void connect(TreeLinkNode *root)
{
    TreeLinkNode *currNode = root;
    currNode->next = NULL;

    TreeLinkNode *prevNode = NULL;

    while (currNode)
    {
        prevNode = currNode;
        currNode = currNode->left;

        TreeLinkNode *currLevelHead = currNode;
        TreeLinkNode *prevLevelHead = prevNode;
        bool left = false;
        while (currLevelHead)
        {
            if (!prevLevelHead)
            {
                currLevelHead->next = NULL;
            }
            else if (!left)
            {
                currLevelHead->next = prevLevelHead->right;
                prevLevelHead = prevLevelHead->next;
            }
            else
            {
                currLevelHead->next = prevLevelHead->left;
            }
            left = !left;
            currLevelHead = currLevelHead->next;
        }
    }
}