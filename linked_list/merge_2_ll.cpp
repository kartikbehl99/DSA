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

Node *merge2SortedLLItr(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head2;

    Node *newHead = NULL;
    Node *newTail = NULL;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            if (!newHead)
            {
                newHead = newTail = head1;
            }
            else
            {
                newTail->next = head1;
                newTail = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if (!newHead)
            {
                newHead = newTail = head2;
            }
            else
            {
                newTail->next = head2;
                newTail = head2;
            }
            head2 = head2->next;
        }
    }

    if (head1)
    {
        newTail->next = head1;
    }
    if (head2)
    {
        newTail->next = head2;
    }

    return newHead;
}

Node *merge2SortedLLRec(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    else if (!head2)
        return head1;

    Node *newHead = NULL;
    if (head1->data <= head2->data)
    {
        newHead = head1;
        newHead->next = merge2SortedLLRec(head1->next, head2);
    }
    else
    {
        newHead = head2;
        newHead->next = merge2SortedLLRec(head1, head2->next);
    }
}
