#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *convertArray2ll(vector<int> &array)
{
    if (array.size() == 0)
        return nullptr;
    Node *head = new Node(array[0]);
    Node *temp = head;
    for (int i = 1; i < array.size(); i++)
    {
        Node *newNode = new Node(array[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

Node *deleteHeadNode(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp; // or free(temp), but here we are using "new" so use delete
    return head;
}

Node *deleteLastNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return temp;
}

Node* deletekthNode(Node* head, int k)
{
    if (head == nullptr || k <= 0)
        return head;

    if (k == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    int count = 1;

    while (temp != nullptr)
    {
        if (count == k)
        {
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
        count++;
    }

    return head;
}

Node* deleteByValue(Node* head, int value) {
    if(head == nullptr) return head;
    Node* temp = head;
    if (value == temp->data)
    {
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = nullptr;

    int count = 1;

    while (temp != nullptr)
    {
        if (value == temp->data)
        {
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
        count++;
    }

    return head;

}
Node* printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = deleteHeadNode(head);
    cout << head->data << endl;
    Node *temp = deleteLastNode(head);
    cout << temp->data << endl;
    printLL(head);
    cout << endl;
    head = deletekthNode(head, 1);
    cout << "after deleting kth node the linked list is:" << " ";
    printLL(head);
    cout << endl;
    head = deleteByValue(head, 3);
    cout << "after deleting by value the linked list is:" << " " << endl;
    printLL(head);
    return 0;
}