#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool checkPalindrome(Node *head)
{
    if (!head || !head->next)
    {
        return true;
    }

    Node *midPoint = head;
    Node *fastPt = head;
    int length = 0;

    Node *temp = head;
    while (temp)
    {
        length += 1;
        temp = temp->next;
    }

    while (midPoint && fastPt && fastPt->next)
    {
        midPoint = midPoint->next;
        fastPt = fastPt->next->next;
    }

    if (length % 2 == 0)
    {
        midPoint = reverse(midPoint);
    }
    else
    {
        midPoint->next = reverse(midPoint->next);
        midPoint = midPoint->next;
    }

    temp = head;
    while (temp && midPoint)
    {
        if (temp->data != midPoint->data)
        {
            return false;
        }
        temp = temp->next;
        midPoint = midPoint->next;
    }

    return true;
}