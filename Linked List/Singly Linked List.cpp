#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
};
int main() {
    Node* head;
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();

    one->val = 1;
    two->val = 2;
    three->val = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
    return 0;
}