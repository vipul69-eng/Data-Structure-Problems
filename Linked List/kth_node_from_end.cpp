#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int length(Node *head)
{
    Node *current = head;
    int len = 0;
    if (!current)
        return len;
    while (current)
    {
        len += 1;
        current = current->next;
    }
    return len;
}

Node *kth_from_end(Node *head, int position)
{
    int k = (length(head) - position) - 1;
    Node *current = head;
    if (k == 0)
    {
        return head;
    }
    while (--k && current)
    {
        current = current->next;
    }
    return current->next;
}

// Another efficient method.

Node *kth(Node *head, int k)
{
    Node *current = head, *temp = head;
    while (k--)
    {
        current = current->next;
    }
    while (current->next)
    {
        current = current->next;
        temp = temp->next;
    }
    return temp;
}
