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

Node *merge(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    if (head1 == head2)
        return head1;

    Node *newHead = NULL;
    Node *tail = NULL;

    cout << "here1\n";

    while (head1 != head2 && head2)
    {
        if (head1->data <= head2->data)
        {
            if (!newHead)
            {
                newHead = tail = head1;
            }
            else
            {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if (!newHead)
            {
                newHead = tail = head2;
            }
            else
            {
                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }
    }

    cout << "here2\n";

    while (head1 != head2)
    {
        tail->next = head1;
        tail = head1;
        head1 = head1->next;
    }

    cout << "here3\n";

    while (head2)
    {
        tail->next = head2;
        tail = head2;
        head2 = head2->next;
    }

    cout << "here4\n";

    return newHead;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *slow = head;
    Node *fast = head;

    cout << "lol\n";
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "lol2`\n";
    Node *mid = slow->next;
    slow->next = NULL;
    Node *head1 = mergeSort(head);
    Node *head2 = mergeSort(mid);
    return merge(head1, head2);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < 10; i++)
    {
        int data;
        cin >> data;
        if (!head)
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            Node *newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = mergeSort(head);
}