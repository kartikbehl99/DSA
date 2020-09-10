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

Node *eliminateDuplicates(Node *head)
{
    if (!head)
        return head;

    Node *temp = head;

    while (temp->next)
    {
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
            continue;
        }
        temp = temp->next;
    }
    return head;
}