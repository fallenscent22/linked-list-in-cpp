#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *convertArray2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node *insertAtHead(Node *head, int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
    return head;
}

Node* insertAtTheEnd(Node*head, int value) {
    Node* temp = new Node(value);
    Node* mover = head;
    while(mover->next){
        mover = mover->next;
    }
    mover->next = temp;
    return head;

}

Node* insertAtkthPos(Node* head, int value, int pos) {
    Node* temp = new Node(value);
    int count = 1;
    Node* mover = head;
    while(temp) {
        if(count == pos-1){
            temp->next = mover->next;
            mover->next = temp;
            return head;
        }
        mover = mover->next;
        count++;
    }
}

Node* insertingAfterGivenValue(Node* head, int givenValue, int value){
    Node* temp = new Node(givenValue);
    Node* mover = head;
    while(mover->next) {
        if(mover->data == value){
            temp->next = mover->next->next;
            mover->next = temp;
            return head;
        }
        mover = mover->next;
    }

}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    vector<int> arr = {11, 2, 34, 22};
    Node *head = convertArray2LL(arr);
    cout << "the LL is: ";
    printLL(head);
    cout << endl;
    head = insertAtHead(head, 1);
    // cout << head->data << endl;
    cout << "after inserting at head, the ll is: ";
    printLL(head);
    cout << endl;
    head = insertAtTheEnd(head, 16);
    cout << "after inserting at end, the ll is: ";
    printLL(head);
    cout << endl;
    head = insertAtkthPos(head, 8, 3);
    cout << "after inserting at given pos, the ll is: ";
    printLL(head);
    cout << endl;
    head = insertingAfterGivenValue(head, 7, 2);
    cout << "inserting after the given value, the ll is: ";
    printLL(head);

}
