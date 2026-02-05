#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
Node *insertBeforHead(Node *head, int value)
{
    Node *newNode = new Node(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertAfterHead(Node *head, int value, Node *temp)
{
    Node *newNode = new Node(value);
    newNode->prev = head;
    head->next = newNode;
    newNode->next = temp;
    return head;
}
Node *insertAfterTail(Node *head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    return head;
}

Node *insertBeforeTail(Node *head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    Node *lastNode = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    lastNode = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = lastNode;
    return head;
}

Node *insertAtKthNode(Node *head, int k, int value) 
{
    Node *newNode = new Node(value); 
    Node *temp = head;
    if (k == 1)
    {
        return insertBeforHead(head, value);
    }
    int count = 1;
    while (temp && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
        return head;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

Node *insertAfterGivenValue(Node *head, int value, int givenValue)
{
    Node *newNode = new Node(value); 
    Node *mover = head;
    while (mover->next)
    {
        if (mover->data == givenValue)
        {
            newNode->next = mover->next;
            newNode->prev = mover;
            if (mover->next)
                mover->next->prev = newNode;

            mover->next = newNode;

            return head;
                }
        mover = mover->next;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    if (head == nullptr)
        return;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *convert2DLL(vector<int> &array)
{
    if (array.size() == 0)
        return nullptr;
    Node *head = new Node(array[0]);
    Node *prev = head;
    for (int i = 1; i < array.size(); i++)
    {
        Node *newNode = new Node(array[i]);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
    }
    return head;
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    Node *head = convert2DLL(array);
    head = insertBeforHead(head, 0);
    cout << "inserting a value before head: ";
    printDLL(head);
    head = insertAfterHead(head, 6, head->next);
    cout << "inserting a value after head: ";
    printDLL(head);
    head = insertAfterTail(head, 7);
    cout << "inserting a value after tail: ";
    printDLL(head);
    head = insertBeforeTail(head, 8);
    cout << "inserting a value before tail: ";
    printDLL(head);
    head = insertAtKthNode(head, 3, 22);
    cout << "inserting a value at kth node: ";
    printDLL(head);
    head = insertAfterGivenValue(head, 11, 5);
    cout << "inserting a value after a given value: ";
    printDLL(head);
}

/*Whenever you insert a node:
You must update 4 links:
prev -> next
next -> prev
new -> prev
new -> next
*/