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

Node *appendLastNToFirst(Node *head, int N)
{
    Node *lastNPrev = NULL;
    Node *lastNHead = head;
    Node *temp = head;

    for (int i = 0; i < N; i++)
    {
        temp = temp->next;
    }

    while (temp && lastNHead)
    {
        lastNPrev = lastNHead;
        temp = temp->next;
        lastNHead = lastNHead->next;
    }

    lastNPrev->next = NULL;
    temp = lastNHead;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = head;

    return lastNHead;
}