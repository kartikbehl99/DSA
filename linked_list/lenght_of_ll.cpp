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

int getLength(Node *head)
{
    int length = 0;
    while (head)
    {
        head = head->next;
        ++length;
    }
    return length;
}

int getLengthRec(Node *head)
{
    if (!head)
        return 0;
    return 1 + getLengthRec(head->next);
}