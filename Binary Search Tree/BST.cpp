#include <bits/stdc++.h>
using namespace std;

/*------------------------------------Node Class Starts------------------------------------*/
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
/*------------------------------------Node Class Endss------------------------------------*/

/*------------------------------------Tree Construct Starts------------------------------------*/
// Node *construct(vector<int> a, int low, int high) {
//     if (low > high)
//         return NULL;
//     int mid = (low + high) / 2;
//     int data = a[mid];
//     Node *lc = construct(a, low, mid - 1);
//     Node *rc = construct(a, mid + 1, high);
//     Node *root = new Node(data);
//     root->left = lc;
//     root->right = rc;
//     return root;
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
/*------------------------------------Tree Construct Ends------------------------------------*/

/*------------------------------------Display Starts------------------------------------*/
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
/*------------------------------------Display Ends------------------------------------*/

/*------------------------------------Tree Size Starts------------------------------------*/
int treeSize(Node *root) {
    if (root == NULL)
        return 0;
    int sz = 0;
    sz += treeSize(root->left) + treeSize(root->right);
    return sz + 1;
}
/*------------------------------------Tree Size Ends------------------------------------*/

/*------------------------------------Tree Sum Starts------------------------------------*/
int treeSum(Node *root) {
    if (root == NULL)
        return 0;
    return (root->data + treeSum(root->left) + treeSum(root->right));
}
/*------------------------------------Tree Sum Ends------------------------------------*/

/*------------------------------------Tree Max Starts------------------------------------*/
int treeMax(Node *root) {
    if (root->right == NULL)
        return root->data;
    return treeMax(root->right);
}
/*------------------------------------Tree Max Ends------------------------------------*/

/*------------------------------------Tree Min Starts------------------------------------*/
int treeMin(Node *root) {
    if (root->left == NULL)
        return root->data;
    return treeMin(root->left);
}
/*------------------------------------Tree Min Ends------------------------------------*/

/*------------------------------------Tree Find Starts------------------------------------*/
bool treeFind(Node *root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    bool ok;
    if (root->data > key)
        ok = treeFind(root->left, key);
    else
        ok = treeFind(root->right, key);
    return ok;
}
/*------------------------------------Tree Find Ends------------------------------------*/

/*------------------------------------Add Node To leaf Starts------------------------------------*/
Node *addNodeToLeaves(Node *root, int data) {
    if (root == NULL)
        return new Node(data);
    if (data > root->data)
        root->right = addNodeToLeaves(root->right, data);
    else if (data < root->data)
        root->left = addNodeToLeaves(root->left, data);
    return root;
}
/*------------------------------------Add Node To leaf Ends------------------------------------*/

/*----------------------------------Remove Node of a BST Starts----------------------------------*/
Node *treeRemove(Node *root, int data) {
    if (root == NULL)
        return NULL;
    if (data > root->data)
        root->right = treeRemove(root->right, data);
    else if (data < root->data)
        root->left = treeRemove(root->left, data);
    else {
        if (root->left != NULL and root->right != NULL) {
            int lmax = treeMax(root->left);
            root->data = lmax;
            root->left = treeRemove(root->left, lmax);
            return root;
        } else if (root->left != NULL) {
            return root->left;
        } else if (root->right != NULL) {
            return root->right;
        } else {
            return NULL;
        }
    }
    return root;
}
/*----------------------------------Remove Node of a BST Ends----------------------------------*/

/*------------------------------------------LCA Starts------------------------------------------*/
int lca(Node *root, int d1, int d2) {
    if (root->data == d1 or root->data == d2)
        return root->data;
    if (d1 < root->data and d2 > root->data)
        return root->data;
    int ans = -1;
    if (d1 < root->data and d2 < root->data)
        ans = lca(root->left, d1, d2);
    else
        ans = lca(root->right, d1, d2);
    return ans;
}
/*-------------------------------------------LCA Ends-------------------------------------------*/

/*-----------------------------Replace Sum of larger in BST Starts-----------------------------*/
void rwsol(Node *root, int &sum) {
    if (root == NULL)
        return;
    rwsol(root->right, sum);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    rwsol(root->left, sum);
}
/*-----------------------------Replace Sum of larger in BST Ends-----------------------------*/

/*------------------------------------Print in range Starts-------------------------------------*/
void printInRange(Node *root, int d1, int d2) {
    if (root == NULL)
        return;
    if (d1 < root->data and d2 < root->data) {
        printInRange(root->left, d1, d2);
    } else if (d1 > root->data and d2 > root->data) {
        printInRange(root->right, d1, d2);
    } else {
        printInRange(root->left, d1, d2);
        cout << root->data << "\n";
        printInRange(root->right, d1, d2);
    }
}
/*--------------------------------------Print in range Ends--------------------------------------*/

/*------------------------------------Target Sum Pair Starts-------------------------------------*/
void targetSumPair(Node *root, Node *node, int target) {
    if (root == NULL)
        return;
    targetSumPair(root->left, node, target);
    int comp = target - root->data;
    if (root->data < comp) {
        if (treeFind(node, comp)) {
            cout << root->data << " " << comp << "\n";
        }
    }
    targetSumPair(root->right, node, target);
}

// Function to get the next bigger number than the current number
Node *getNextFromNormalInorder(stack<pair<Node *, int>> &st) {
    while (!st.empty()) {
        pair<Node *, int> topp = st.top();
        if (topp.second == 0) {
            st.top().second++;
            if (topp.first->left != NULL)
                st.push({topp.first->left, 0});
        } else if (topp.second == 1) {
            st.top().second++;
            if (topp.first->right != NULL)
                st.push({topp.first->right, 0});
            return topp.first;
        } else {
            st.pop();
        }
    }
    return NULL;
}

// Function to get a smaller number just before the current biggest number
Node *getNextFromReverseInorder(stack<pair<Node *, int>> &st) {
    while (!st.empty()) {
        pair<Node *, int> topp = st.top();
        if (topp.second == 0) {
            st.top().second++;
            if (topp.first->right != NULL)
                st.push({topp.first->right, 0});
        } else if (topp.second == 1) {
            st.top().second++;
            if (topp.first->left != NULL)
                st.push({topp.first->left, 0});
            return topp.first;
        } else {
            st.pop();
        }
    }
    return NULL;
}

// We basically use two pointer in the tree by getting the next number from normal inorder and
// getting the next greater number that is smaller than the current greater from reverse inorder
void bestApproach(Node *root, int target) {
    stack<pair<Node *, int>> ls;
    stack<pair<Node *, int>> rs;
    ls.push({root, 0});
    rs.push({root, 0});
    Node *left = getNextFromNormalInorder(ls);
    Node *right = getNextFromReverseInorder(rs);
    while (left->data < right->data) {
        if (left->data + right->data < target) {
            left = getNextFromNormalInorder(ls);
        } else if (left->data + right->data > target) {
            right = getNextFromReverseInorder(rs);
        } else {
            cout << left->data << " " << right->data << "\n";
            left = getNextFromNormalInorder(ls);
            right = getNextFromReverseInorder(rs);
        }
    }
}
/*------------------------------------Target Sum Pair Ends-------------------------------------*/

/*------------------------------------Main Function Starts------------------------------------*/
int main() {
    int n;
    cin >> n;
    // vector<int> a(n);
    // for (int &it : a)
    // cin >> it;
    // Node *root = constructTree(a, 0, n - 1);

    Node *root = constructTree();
    // cout << treeSize(root) << "\n";
    // cout << treeSum(root) << "\n";
    // cout << treeMax(root) << "\n";
    // cout << treeMin(root) << "\n";
    // int key;
    // cin >> key;
    // cout << (treeFind(root, key) == true ? "true\n" : "false\n");

    // int d;
    // cin >> d;
    // root = addNodeToLeaves(root, d);
    // display(root);

    // int d;
    // cin >> d;
    // root = treeRemove(root, d);
    // display(root);

    // int sum = 0;
    // rwsol(root, sum);
    // display(root);

    // int d1, d2;
    // cin >> d1 >> d2;
    // int l = lca(root, d1, d2);
    // cout << l << "\n";

    // int d1, d2;
    // cin >> d1 >> d2;
    // printInRange(root, d1, d2);

    int target;
    cin >> target;
    bestApproach(root, target);
    return 0;
}
/*------------------------------------Main Function Ends------------------------------------*/