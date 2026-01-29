#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    public:
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* convertArray2ll(vector<int> & array) {
    if (array.size() == 0) return nullptr;
    Node* head = new Node(array[0]);
    Node* mover = head;
    for(int i = 1; i < array.size(); i++) {
        Node* temp = new Node(array[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main() {
    vector<int> array = {1,2,3,4};
    Node* head = convertArray2ll(array);   
    Node* temp = head; 
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}