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

Node *nthFromLast(Node *head, int n)
{
    if (!head)
        return head;

    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    if (!temp)
        return temp;

    Node *ans = head;
    while (ans && temp->next)
    {
        ans = ans->next;
        temp = temp->next;
    }

    return ans;
}