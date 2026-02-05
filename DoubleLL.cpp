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
        Node* newNode = new Node(array[i]);
        prev->next = newNode;
        newNode -> prev = prev;
        prev = newNode;
    }
    return head;
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    Node *head = convert2DLL(array);
    cout << head->data << endl;
    printDLL(head);
}