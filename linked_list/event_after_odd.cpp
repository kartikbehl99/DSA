#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *evenAfterOdd(node *head)
{
    if (!head || !head->next)
        return head;

    node *itr = head;
    node *evenHead = NULL;
    node *evenTail = NULL;
    node *oddHead = NULL;
    node *oddTail = NULL;

    while (itr)
    {
        if (itr->data % 2 == 0)
        {
            if (!evenHead)
            {
                evenHead = evenTail = itr;
            }
            else
            {
                evenTail->next = itr;
                evenTail = itr;
            }
        }
        else
        {
            if (!oddHead)
            {
                oddHead = oddTail = itr;
            }
            else
            {
                oddTail->next = itr;
                oddTail = itr;
            }
        }

        itr = itr->next;
    }

    if (!oddHead)
        return evenHead;
    if (!evenHead)
        return oddHead;

    oddTail->next = evenHead;
    return oddHead;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int data = 0;
    while (true)
    {
        cin >> data;
        if (data == -1)
            break;
        if (!head)
        {
            head = new node(data);
            tail = head;
        }
        else
        {
            node *newNode = new node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    evenAfterOdd(head);
}