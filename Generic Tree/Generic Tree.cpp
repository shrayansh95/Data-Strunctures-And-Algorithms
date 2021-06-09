#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int val;
    vector<Node *> child;
    Node(int val) {
        this->val = val;
    }
};

Node *construct(vector<int> a) {
    Node *root;
    stack<Node *> st;
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
    return root;
}

// Display Function
// d(10) -> 10 will print itself and it's family
// d(20), d(30), d(40) will print themselves and their families
// d(10) = s(10) + d(20) + d(30) + d(40)
void display(Node *node) {
    string str = to_string(node->val) + " -> ";
    for (Node *nodes : node->child)
        str += to_string(nodes->val) + ", ";
    str.push_back('.');
    cout << str << endl;
    for (Node *nodes : node->child)
        display(nodes);
}

// Size Calculation of the tree
int size(Node *root) {
    int countNodes = 1;
    for (Node *children : root->child)
        countNodes += size(children);
    return countNodes;
}

// Maximum value node
int maxValueNode(Node *root) {
    int maxTillNow = root->val;
    for (Node *children : (root->child))
        maxTillNow = max(maxTillNow, maxValueNode(children));
    return maxTillNow;
}

// Height of the Generic Tree = Depth of the tree
// If we count the edges height and depth will start from 0
// If we count the nodes then height and depth will start from 1
// For edges keep ht = -1 and for nodes keep ht = 0
int height(Node *root) {
    int ht = -1;
    for (Node *children : (root->child))
        ht = max(ht, height(children));
    ht += 1;
    return ht;
}

// Preorder Postorder Traversals in Generic Tree
void traversal(Node *root) {
    cout << "Node Pre " << root->val << "\n";
    for (Node *children : (root->child)) {
        cout << "Edge Pre " << root->val << "--" << children->val << "\n";
        traversal(children);
        cout << "Edge Post " << root->val << "--" << children->val << "\n";
    }
    cout << "Node Post " << root->val << "\n";
}

// Level Order Traversal - We need a queue for this
// RPA - Remove Print Add
void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    Node *temp;
    while (q.size() != 0) {
        temp = q.front();
        q.pop();
        cout << temp->val << " ";
        for (Node *children : temp->child)
            q.push(children);
    }
    cout << ".\n";
}

// Level Order Traversal nd printng in next line
// Process 1
// void levelOrderLineWise(Node *root) {
//     queue<Node *> parentQ;
//     queue<Node *> childQ;
//     parentQ.push(root);
//     Node *temp;
//     while (!parentQ.empty()) {
//         temp = parentQ.front();
//         parentQ.pop();
//         cout << temp->val << " ";
//         for (Node *children : (temp->child))
//             childQ.push(children);
//         if (parentQ.empty()) {
//             cout << "\n";
//             parentQ = childQ;
//             while (childQ.size() > 0) {
//                 childQ.pop();
//             }
//         }
//     }
// }

// Process 2
void levelOrderLineWise(Node *root) {
    queue<Node *> parentQ;
    queue<Node *> childQ;
    parentQ.push(root);
    Node *temp;
    while (!parentQ.empty()) {
        while (!parentQ.empty()) {
            temp = parentQ.front();
            parentQ.pop();
            cout << temp->val << " ";
            for (Node *children : (temp->child)) {
                childQ.push(children);
            }
        }
        cout << "\n";
        parentQ = childQ;
        while (childQ.size() > 0) {
            childQ.pop();
        }
    }
}

// Level order Line Wise and Zig Zag
void levelOrderZigZag(Node *root) {
    stack<Node *> parentS;
    stack<Node *> childS;
    Node *temp;
    int flag = 0;
    parentS.push(root);
    while (!parentS.empty()) {
        temp = parentS.top();
        parentS.pop();
        cout << temp->val << " ";
        if (flag == 0) {
            for (Node *children : (temp->child)) {
                childS.push(children);
            }
        } else {
            for (int i = (temp->child).size() - 1; i >= 0; i--) {
                childS.push(temp->child[i]);
            }
        }
        if (parentS.empty()) {
            cout << "\n";
            parentS = childS;
            while (childS.size() > 0) {
                childS.pop();
            }
            flag ^= 1;
        }
    }
}

// Mirror Transformation
void mirror(Node *root) {
    int i = 0, j = (root->child).size() - 1;
    while (i < j) {
        swap((root->child[i]), (root->child[j]));
        ++i;
        --j;
    }
    for (Node *children : (root->child))
        mirror(children);
}

void removeLeaves(Node *root) {
    if (root == NULL)
        return;
    Node *temp;
    for (int i = 0; i < root->child.size(); i++) {
        temp = root->child[i];
        if (temp->child.size() == 0) {
            for (int j = i; j < root->child.size() - 1; j++) {
                root->child[j] = root->child[j + 1];
            }
            root->child.pop_back();
            i--;
        }
    }
    for (Node *children : root->child)
        removeLeaves(children);
}

// Linearize a generic tree O(N^2)
// Node *getTail(Node *root) {
//     while (root->child.size() == 1) {
//         root = root->child[0];
//     }
//     return root;
// }
// void linearize(Node *root) {
//     for (Node *children : root->child)
//         linearize(children);
//     Node *lc, *sl, *slt;
//     while (root->child.size() > 1) {
//         lc = root->child[root->child.size() - 1];
//         root->child.pop_back();
//         sl = root->child[root->child.size() - 1];
//         slt = getTail(sl);
//         slt->child.push_back(lc);
//     }
// }

// Linearize a generic Tree O(N)
Node *linearize(Node *root) {
    if (root->child.size() == 0)
        return root;
    Node *lkt = linearize(root->child[root->child.size() - 1]);
    Node *last, *slast;
    while (root->child.size() > 1) {
        last = root->child.back();
        root->child.pop_back();
        slast = linearize(root->child.back());
        slast->child.push_back(last);
    }
    return lkt;
}

bool find(Node *root, int data) {
    if (root->val == data)
        return true;
    bool ok = false;
    for (Node *children : root->child) {
        ok = find(children, data);
        if (ok)
            return true;
    }
    return false;
}

// Path from node to root
vector<int> findPath(Node *root, int data) {
    if (root->val == data) {
        vector<int> ans;
        ans.push_back(root->val);
        return ans;
    }
    for (Node *children : root->child) {
        vector<int> ans = findPath(children, data);
        if (ans.size() > 0) {
            ans.push_back(root->val);
            return ans;
        }
    }
    vector<int> ans;
    return ans;
}

// Lowest Common Ancestor
int LCA(Node *root, int d1, int d2) {
    vector<int> p1 = findPath(root, d1);
    vector<int> p2 = findPath(root, d2);
    int i = p1.size() - 1, j = p2.size() - 1;
    int ans = 0;
    while (i >= 0 and j >= 0) {
        if (p1[i] != p2[j]) {
            break;
        }
        ans = p1[i];
        --i, --j;
    }
    return ans;
}

// Distance between two nodes
int distanceBetween(Node *root, int d1, int d2) {
    vector<int> p1 = findPath(root, d1);
    vector<int> p2 = findPath(root, d2);
    int i = p1.size() - 1, j = p2.size() - 1;
    while (i >= 0 and j >= 0) {
        if (p1[i] != p2[j]) {
            break;
        }
        --i, --j;
    }
    ++i, ++j;
    return i + j;
}

// Checks if two trees are similar in shape
bool isSimilar(Node *root1, Node *root2) {
    if (root1->child.size() != root2->child.size())
        return false;
    for (int i = 0; i < root1->child.size(); i++) {
        Node *c1 = root1->child[i];
        Node *c2 = root2->child[i];
        if (isSimilar(c1, c2) == false)
            return false;
    }
    return true;
}

// Checks if the two trees are mirror image of each other
bool isMirror(Node *root1, Node *root2) {
    if (root1->child.size() != root2->child.size())
        return false;
    int i = 0, j = root1->child.size() - 1;
    while (i <= j) {
        Node *temp1 = root1->child[i];
        Node *temp2 = root2->child[j];
        bool ok = isMirror(temp1, temp2);
        if (!ok)
            return false;
        ++i;
        --j;
    }
    return true;
}

// Checks if the tree is Symmetric
// Just check if the tree is a mirror image of itself
bool isSymmetric(Node *root) {
    return isMirror(root, root);
}

// Multisolver
int sz, mini, maxi, ht;
void multiSolver(Node *root, int depth) {
    ++sz;
    mini = min(mini, root->val);
    maxi = max(maxi, root->val);
    ht = max(depth, ht);
    for (Node *children : root->child)
        multiSolver(children, depth + 1);
}

// Predecessor And Successor of a given value in the generic tree
Node *predecessor, *successor;
int state;
void predecessorAndSuccessor(Node *root, int data) {
    if (state == 0) {
        if (root->val == data) {
            state = 1;
        } else {
            predecessor = root;
        }
    } else if (state == 1) {
        successor = root;
        state = 2;
    }
    for (Node *children : root->child)
        predecessorAndSuccessor(children, data);
}

// Ceil and Floor of a given value in a genric tree
int upper;
int lower;
void ceilAndFloor(Node *root, int data) {
    if (root->val < data)
        lower = max(lower, root->val);
    else if (root->val > data)
        upper = min(upper, root->val);
    for (Node *children : root->child)
        ceilAndFloor(children, data);
}

// Kth Largest Element in the Generic Tree
int kth;
void kthLargest(Node *root, int k) {
    lower = INT_MIN;
    int factor = INT_MAX;
    for (int i = 0; i < k; i++) {
        ceilAndFloor(root, factor);
        factor = lower;
        lower = INT_MIN;
    }
    kth = factor;
}

// Node with maximum sum subtree
int msn, ms;
int maxSumSubtree(Node *root) {
    int sum = 0;
    for (Node *children : root->child) {
        sum += maxSumSubtree(children);
    }
    sum += root->val;
    if (sum > ms) {
        ms = sum;
        msn = root->val;
    }
    return sum;
}

// Diameter of the tree
int dia;
int calculateDiaReturnHeight(Node *root) {
    int dht = -1;
    int sdht = -1;
    for (Node *children : root->child) {
        int cht = calculateDiaReturnHeight(children);
        if (cht > dht) {
            sdht = dht;
            dht = cht;
        } else if (cht > sdht)
            sdht = cht;
    }
    if (sdht + dht + 2 > dia)
        dia = sdht + dht + 2;
    return dht + 1;
}

// Iterative Preorder and Postorder
string pre = "", post = "";
void IterativePrePost(Node *root) {
    stack<pair<Node *, int>> st;
    st.push({root, -1});
    while (!st.empty()) {
        pair<Node *, int> top = st.top();
        if (top.second == -1) {
            pre += to_string(top.first->val) + " ";
            st.top().second++;
        } else if (top.second == top.first->child.size()) {
            post += to_string(top.first->val) + " ";
            st.pop();
        } else {
            st.top().second++;
            st.push({top.first->child[top.second], -1});
        }
    }
}

int main() {
    Node *root;

    int n;
    cin >> n;
    // vector<int> a = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    root = construct(a);

    // int m;
    // cin >> m;
    // vector<int> b(m);
    // for (int i = 0; i < m; i++)
    //     cin >> b[i];
    // Node *root2 = construct(b);
    // display(root);

    // int count = size(root);
    // cout << count << endl;

    // int maxNode = maxValueNode(root);
    // cout << maxNode << endl;

    // int ht = height(root);
    // cout << ht << endl;

    // traversal(root);

    // levelOrder(root);

    // levelOrderLineWise(root);

    // levelOrderZigZag(root);

    // display(root);
    // mirror(root);
    // display(root);

    // removeLeaves(root);
    // display(root);

    // Node *last = linearize(root);
    // display(root);

    // int data;
    // cin >> data;
    // bool ok = find(root, data);
    // if (ok)
    //     cout << "true\n";
    // else
    //     cout << "false\n";

    // int data;
    // cin >> data;
    // vector<int> path = findPath(root, data);
    // cout << '[';
    // for (int i = 0; i < path.size(); i++) {
    //     if (i == path.size() - 1)
    //         cout << path[i];
    //     else
    //         cout << path[i] << ", ";
    // }
    // cout << "]\n";

    // int d1, d2;
    // cin >> d1 >> d2;
    // int ans = LCA(root, d1, d2);
    // cout << ans << "\n";

    // int d1, d2;
    // cin >> d1 >> d2;
    // int ans = distanceBetween(root, d1, d2);
    // cout << ans << endl;

    // bool ok = isSimilar(root, root2);
    // if (ok)
    //     cout << "true\n";
    // else
    //     cout << "false\n";

    // bool ok = isMirror(root, root2);
    // if (ok)
    //     cout << "true\n";
    // else
    //     cout << "false\n";

    // bool ok = isSymmetric(root);
    // if (ok)
    //     cout << "true\n";
    // else
    //     cout << "false\n";

    // sz = 0;
    // ht = 0;
    // mini = INT_MAX;
    // maxi = INT_MIN;
    // multiSolver(root, 0);
    // cout << "Size = " << sz << '\n';
    // cout << "Height = " << ht << "\n";
    // cout << "Maximum = " << maxi << "\n";
    // cout << "Minimum = " << mini << "\n";

    // int data;
    // cin >> data;
    // predecessor = NULL;
    // successor = NULL;
    // state = 0;
    // predecessorAndSuccessor(root, data);
    // if (predecessor == NULL)
    //     cout << "Predecessor = Not found\n";
    // else
    //     cout << "Predecessor = " << predecessor->val << "\n";

    // if (successor == NULL)
    //     cout << "Successor = Not found\n";
    // else
    //     cout << "Successor = " << successor->val << "\n";

    // int data;
    // cin >> data;
    // upper = INT_MAX;
    // lower = INT_MIN;
    // ceilAndFloor(root, data);
    // cout << "CEIL = " << upper << "\n";
    // cout << "FLOOR = " << lower << "\n";

    // int k;
    // cin >> k;
    // kth = INT_MAX;
    // kthLargest(root, k);
    // cout << kth << endl;

    // msn = -1, ms = INT_MIN;
    // int s = maxSumSubtree(root);
    // cout << msn << "@" << ms << endl;

    // dia = 0;
    // int ht = calculateDiaReturnHeight(root);
    // cout << dia << endl;

    IterativePrePost(root);
    cout << pre << "\n"
         << post << "\n";

    return 0;
}
