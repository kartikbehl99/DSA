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

void printElement(Node *head, int i)
{
    int index = 0;
    while (head && index < i)
    {
        head = head->next;
        index++;
    }

    if (!head)
        return;
    cout << head->data;
}