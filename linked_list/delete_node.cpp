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

Node *deleteNode(Node *head, int pos)
{
    if (!head || pos < 0)
        return head;

    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete[] temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp && pos--)
    {
        prev = temp;
        temp = temp->next;
    }

    if (pos > 0)
        return head;

    prev->next = temp->next;
    delete[] temp;
    return head;
}