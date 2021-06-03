#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node *> child;
    Node(int val) {
        this->val = val;
    }
};

// d(10) -> 10 will print itself and it's family
// d(20), d(30), d(40) will print themselves and their families
// d(10) = s(10) + d(20) + d(30) + d(40)
void display(Node *node) {
    string str = to_string(node->val) + " -> ";
    for (Node *nodes : node->child)
        str += to_string(nodes->val) + " -> ";
    str.push_back('.');
    cout << str << endl;
    for (Node *nodes : node->child)
        display(nodes);
}

int main() {
    Node *root;
    stack<Node *> st;
    vector<int> a = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == -1)
            st.pop();
        else {
            Node *newNode = new Node(a[i]);
            if (st.empty())
                root = newNode;
            else
                (st.top()->child).push_back(newNode);
            st.push(newNode);
        }
    }
    display(root);
    return 0;
}