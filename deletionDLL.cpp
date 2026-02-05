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
Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteAfterHead(Node* head) {
    Node* temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if(head == nullptr) return head;
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteBeforeTail(Node* head) {
    Node* temp = head;
    if(head == nullptr || head->next == nullptr) return head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return head;
}

Node* deleteAtKthNode(Node* head, int pos){
    Node* temp = head;
    int count = 1;
    while(temp) {
        if(count == pos-1) {
            temp->next = temp->next->next;
            temp->next->prev = temp;
            return head;
        }
        temp = temp->next;
        count++;
    }
}

Node* deleteAfterGivenValue(Node* head, int value) {
    Node* temp = head;
    while(temp) {
        if(temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev->next;
            return head;
        }
        temp = temp->next;
    }
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
        Node* newNode = new Node(array[i]);
        prev->next = newNode;
        newNode -> prev = prev;
        prev = newNode;
    }
    return head;
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = convert2DLL(array);
    head = deleteHead(head);
    cout << "deleting head: ";
    printDLL(head);
    head = deleteAfterHead(head);
    cout << "deleting a value after head: ";
    printDLL(head);
    head = deleteTail(head);
    cout << "deleting tail: ";
    printDLL(head);
    head = deleteBeforeTail(head);
    cout << "deleting a value before tail: ";
    printDLL(head);
    head = deleteAtKthNode(head, 3);
    cout << "deleting a value at kth node: ";
    printDLL(head);
    head = deleteAfterGivenValue(head, 4);
    cout << "deleting after a given value: ";
    printDLL(head);
}

/*All edge cases handled
Node* deleteBeforeTail(Node* head) {

    // Case 1: Empty list or only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* temp = head;

    // Move to tail
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // temp is tail
    Node* nodeToDelete = temp->prev;

    // Case 2: Only two nodes (delete head)
    if (nodeToDelete->prev == nullptr) {
        head = temp;
        temp->prev = nullptr;
        delete nodeToDelete;
        return head;
    }

    // Normal case
    nodeToDelete->prev->next = temp;
    temp->prev = nodeToDelete->prev;

    delete nodeToDelete;

    return head;
}*/