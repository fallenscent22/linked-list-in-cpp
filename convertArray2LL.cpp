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
        next = NULL;
    }
};

Node *convertArray2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp = temp->next;
        mover = temp;
    }

    return head;
}
int main()
{
    vector<int> arr = {11, 2, 34, 22};
    Node *head = convertArray2LL(arr);
    cout << head->data;
}