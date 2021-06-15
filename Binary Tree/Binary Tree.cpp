#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Construct Tree
// Node *constructTree() {
//     int d;
//     cin >> d;
//     if (d == -1)
//         return NULL;
//     Node *n = new Node(d);
//     n->left = constructTree();
//     n->right = constructTree();
//     return n;
// }

Node *constructTree() {
    string d;
    cin >> d;
    if (d == "n")
        return NULL;
    int dd = stoi(d);
    Node *n = new Node(dd);
    n->left = constructTree();
    n->right = constructTree();
    return n;
}

// Display
void display(Node *root) {
    if (root == NULL)
        return;
    string l, r;
    if (root->left == NULL)
        l = ".";
    else
        l = to_string(root->left->data);
    if (root->right == NULL)
        r = ".";
    else
        r = to_string(root->right->data);
    cout << l << " <- " << root->data << " -> " << r << "\n";
    display(root->left);
    display(root->right);
}

// Size of the tree
int sizeTree(Node *root) {
    if (root == NULL)
        return 0;
    int lcs = sizeTree(root->left);
    int rcs = sizeTree(root->right);
    return 1 + lcs + rcs;
}

// Sum of all nodes
int sumTree(Node *root) {
    if (root == NULL)
        return 0;
    int lcs = sumTree(root->left);
    int rcs = sumTree(root->right);
    return root->data + lcs + rcs;
}

// Max value node in the tree
int maxNode(Node *root) {
    if (root == NULL)
        return 0;
    int lmv = maxNode(root->left);
    int rmv = maxNode(root->right);
    return max(root->data, max(lmv, rmv));
}

// Height according to edges
// int height(Node *root) {
//     if (root == NULL)
//         return -1;
//     int lth = height(root->left);
//     int rth = height(root->right);
//     return (max(lth, rth) + 1);
// }

// Preorder, Inorder and Postorder Traversal
void traversal(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << " - In Preorder\n";
    traversal(root->left);
    cout << root->data << " - In Inorder\n";
    traversal(root->right);
    cout << root->data << " - In Postorder\n";
}

// Iterative Preorder, Inorder, & Postorder
void iterativeTraversal(Node *root) {
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    string pre = "", in = "", post = "";
    pair<Node *, int> temp;
    while (!st.empty()) {
        temp = st.top();
        if (temp.second == 1) {
            pre += to_string(temp.first->data) + " ";
            st.top().second++;
            if (temp.first->left != NULL)
                st.push({temp.first->left, 1});
        } else if (temp.second == 3) {
            post += to_string(temp.first->data) + " ";
            st.pop();
        } else {
            in += to_string(temp.first->data) + " ";
            st.top().second++;
            if (temp.first->right != NULL)
                st.push({temp.first->right, 1});
        }
    }
    cout << pre << "\n";
    cout << in << "\n";
    cout << post << "\n";
}

// Level Order Traversal
void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    Node *temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == NULL) {
            if (q.size() > 0)
                q.push(NULL);
            cout << "\n";
        } else {
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            cout << temp->data << " ";
        }
    }
}

// Find Node
bool findNode(Node *root, int data) {
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    bool ok = findNode(root->left, data);
    if (ok)
        return true;
    ok = findNode(root->right, data);
    if (ok)
        return true;
    return false;
}

// Node to Root Path
// vector<int> nodeToRootPath(Node *root, int data) {
//     if (root == NULL) {
//         vector<int> ans;
//         return ans;
//     }
//     vector<int> ans;
//     if (root->data == data) {
//         ans.push_back(data);
//         return ans;
//     }
//     ans = nodeToRootPath(root->left, data);
//     if (ans.size() > 0) {
//         ans.push_back(root->data);
//         return ans;
//     }
//     ans = nodeToRootPath(root->right, data);
//     if (ans.size() > 0) {
//         ans.push_back(root->data);
//     }
//     return ans;
// }

vector<Node *> nodeToRootPath(Node *root, int data) {
    if (root == NULL) {
        vector<Node *> ans;
        return ans;
    }
    vector<Node *> ans;
    if (root->data == data) {
        ans.push_back(root);
        return ans;
    }
    ans = nodeToRootPath(root->left, data);
    if (ans.size() > 0) {
        ans.push_back(root);
        return ans;
    }
    ans = nodeToRootPath(root->right, data);
    if (ans.size() > 0) {
        ans.push_back(root);
    }
    return ans;
}

// K level down
void kLevelDown(Node *root, int k, Node *block) {
    if (root == NULL or k < 0 or root == block)
        return;
    if (k == 0) {
        cout << root->data << "\n";
        return;
    }
    kLevelDown(root->left, k - 1, block);
    kLevelDown(root->right, k - 1, block);
}

// Print node at a distance k from node
void printKNodesFar(Node *root, int data, int k) {
    vector<Node *> path = nodeToRootPath(root, data);
    for (int i = 0; i < path.size(); i++) {
        kLevelDown(path[i], k - i, i == 0 ? NULL : path[i - 1]);
    }
}

// Path to leaf from root in range
void pathToLeafFromRoot(Node *root, string ans, int sum, int lo, int hi) {
    if (root == NULL or sum + root->data > hi)
        return;
    if (root->left == NULL and root->right == NULL and (sum + root->data) >= lo and (sum + root->data) <= hi) {
        cout << ans << root->data << "\n";
        return;
    }
    ans += to_string(root->data) + " ";
    sum += root->data;
    pathToLeafFromRoot(root->left, ans, sum, lo, hi);
    pathToLeafFromRoot(root->right, ans, sum, lo, hi);
}

// Create left clone of the tree
Node *createLeftCloneTree(Node *root) {
    if (root == NULL)
        return NULL;
    Node *L = createLeftCloneTree(root->left);
    Node *R = createLeftCloneTree(root->right);
    root->right = R;
    Node *temp = new Node(root->data);
    temp->left = L;
    root->left = temp;
    return root;
}

// From left clone to normal
Node *transBackFromLeftClone(Node *root) {
    if (root == NULL)
        return NULL;
    Node *L = transBackFromLeftClone(root->left->left);
    Node *R = transBackFromLeftClone(root->right);
    root->right = R;
    root->left = L;
    return root;
}

// Print Single Child Nodes
void printSingleChildNodes(Node *root, Node *parent) {
    if (root == NULL)
        return;
    if (parent != NULL and ((parent->left != NULL and parent->right == NULL) or (parent->left == NULL and parent->right != NULL))) {
        cout << root->data << "\n";
    }
    printSingleChildNodes(root->left, root);
    printSingleChildNodes(root->right, root);
}

// Remove Leaf Nodes
Node *removeLeaves(Node *root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL and root->right == NULL) {
        delete root;
        return NULL;
    }
    Node *L = removeLeaves(root->left);
    Node *R = removeLeaves(root->right);
    root->left = L;
    root->right = R;
    return root;
}

// Calculate Diameter of the tree
int height(Node *root, int &ans) {
    if (root == NULL)
        return -1;
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    ans = max(ans, 2 + lh + rh);
    return max(lh, rh) + 1;
}

int diameter(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    int ht = height(root, ans);
    return ans;
}

// Tilt of a Binary Tree
int sumLeftRight(Node *root, int &t) {
    if (root == NULL)
        return 0;
    int ls = sumLeftRight(root->left, t);
    int rs = sumLeftRight(root->right, t);
    t += abs(ls - rs);
    return (root->data + ls + rs);
}

int tilt(Node *root) {
    if (root == NULL)
        return 0;
    int t = 0;
    int c = sumLeftRight(root, t);
    return t;
}

// Is a Binary search tree
bool isBST(Node *root, int mini, int maxi) {
    if (root == NULL)
        return true;
    if (root->data < mini or root->data > maxi)
        return false;
    return (isBST(root->left, mini, root->data - 1) && isBST(root->right, root->data + 1, maxi));
}

// Is a balanced tree
int findHeight(Node *root, bool &ok) {
    if (root == NULL)
        return 0;
    int lh = findHeight(root->left, ok);
    int rh = findHeight(root->right, ok);
    if (abs(lh - rh) > 1) {
        ok = false;
        return -1;
    }
    return (lh + rh + 1);
}

bool isBalanced(Node *root) {
    if (root == NULL) {
        return true;
    }
    bool ok = true;
    int ht = findHeight(root, ok);
    return ok;
}

// Largest BST in a subtree
class LBST {
public:
    int mini;
    int adata;
    int asize;
    bool isBST;
    int sz;
    int maxi;
    LBST() {
        mini = INT_MIN;
        maxi = INT_MAX;
        isBST = true;
        sz = 0;
        adata = -1;
        asize = -1;
    }
};

LBST largestBSTBT(Node *root) {
    if (root == NULL) {
        LBST ans;
        ans.sz = 0;
        ans.adata = -1;
        ans.mini = INT_MAX;
        ans.maxi = INT_MIN;
        ans.asize = -1;
        ans.isBST = true;
        return ans;
    }
    if (root->left == NULL and root->right == NULL) {
        LBST ans;
        ans.sz = 1;
        ans.mini = ans.maxi = ans.adata = root->data;
        ans.asize = 1;
        ans.isBST = true;
        return ans;
    }
    LBST l = largestBSTBT(root->left);
    LBST r = largestBSTBT(root->right);
    LBST ret;
    ret.sz = (1 + l.sz + r.sz);
    if (l.isBST and r.isBST and l.maxi < root->data and r.mini > root->data) {
        ret.mini = l.mini;
        ret.maxi = r.maxi;
        ret.isBST = true;
        ret.adata = root->data;
        ret.asize = ret.sz;
        return ret;
    }
    if (l.asize > r.asize) {
        ret.asize = l.asize;
        ret.adata = l.adata;
    } else {
        ret.asize = r.asize;
        ret.adata = r.adata;
    }
    ret.isBST = false;
    return ret;
}

int main() {
    int n;
    cin >> n;

    Node *root = constructTree();

    // display(root);

    // int sizeT = sizeTree(root);
    // cout << sizeT << "\n";

    // int sumT = sumTree(root);
    // cout << sumT << "\n";

    // int maxT = maxNode(root);
    // cout << maxT << "\n";

    // int ht = height(root);
    // cout << ht << "\n";

    // traversal(root);

    // levelOrder(root);

    // iterativeTraversal(root);

    // int k;
    // cin >> k;
    // kLevelDown(root, k);

    // int data, k;
    // cin >> data >> k;
    // printKNodesFar(root, data, k);

    // int lower, upper;
    // cin >> lower >> upper;
    // pathToLeafFromRoot(root, "", 0, lower, upper);

    // root = createLeftCloneTree(root);
    // display(root);

    // root = transBackFromLeftClone(root);
    // display(root);

    // printSingleChildNodes(root, NULL);

    // root = removeLeaves(root);
    // display(root);

    // int dia = diameter(root);
    // cout << dia << "\n";

    // int t = tilt(root);
    // cout << t << "\n";

    // bool ok = isBST(root, INT_MIN, INT_MAX);
    // cout << (ok ? "true\n" : "false\n");

    // bool ok = isBalanced(root);
    // cout << (ok ? "true\n" : "false\n");
    LBST ans;
    ans = largestBSTBT(root);
    cout << ans.adata << "@" << ans.asize << "\n";
    return 0;
}