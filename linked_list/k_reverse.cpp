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

Node *kReverse(Node *head, int k)
{
    if (!head || !head->next || k <= 1)
        return head;

    Node *temp = head;
    Node *prev = NULL;
    Node *next = NULL;
    int i = 0;
    while (i < k && temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        i++;
    }

    head->next = kReverse(temp, k);

    return prev;
}