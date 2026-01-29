#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next; // a pointer to next address

    // constructor
    public:
    Node(int x, Node *y)
    {
        data = x;
        next = y;
    }
    
    public:
    Node(int x)    // when we pass only data to the node
    {
        data = x;
        next = nullptr;
    }
};

int main()
{
    // we can also take an array of nodes
    // vector<int> array = {1,2,3};
    // Node* z = new Node(array[0], nullptr);
    Node *y = new Node(2, nullptr); // a node with data = 2 and next = NULL
    Node *x = new Node(1, y);
    cout << y->data << endl; // 2
    cout << y->next << endl; // 0
    cout << x->data << endl; // 1
    cout << x->next << endl; // 0xfc17a0
}



//execution: g++ creation.cpp -o creation
// .\creation
