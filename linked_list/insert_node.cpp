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

Node *insertNode(Node *head, int pos, int data)
{
    if (pos < 0)
        return head;
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
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

    Node *newNode = new Node(data);
    prev->next = newNode;
    newNode->next = temp;

    return head;
}