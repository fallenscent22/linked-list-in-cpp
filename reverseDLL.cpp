/*
we can reverse a Double linked list using 2 approaches:
1. using a stack: o(n) we just traverse through the ll and push into the stack and then insert elements by popping from stack O(n) and O(n)
2. using recursion: O(n) time and O(n) space
3. reversing the links O(n) time and O(1) space - best method (I will be implemeting this)
4. rebuilding the LL O(n) time and O(1) space - here we operate on data rather than links
*/
#include <iostream>
#include <list>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
void insertEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
Node *reverse(Node *head)
{
    if (!head)
        return nullptr;

    Node *current = head;
    Node *temp = nullptr;

    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp)
        head = temp->prev;

    return head;
}
void print(Node *head)
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
int main()
{
    Node *head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    print(head);
    head = reverse(head);
    cout << "dll after reversing: ";
    print(head);
}
