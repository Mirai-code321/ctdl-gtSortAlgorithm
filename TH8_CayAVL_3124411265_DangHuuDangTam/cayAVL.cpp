#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
    int height;
    int count;
};

Node* CreateNode(int theKey, Node* left = nullptr, Node* right = nullptr) {
    Node* p = new Node;
    p->info = theKey;
    p->height = 1;
    p->right = right;
    p->left = left;
    p->count = 1;
    return p;
}

void DisplayNode(Node* p, int indent) {
    for (int j = 0; j < indent; j++)
        cout << " ";
    cout << "{" << p->info << ":" << p->height << "}\n";
}

typedef Node* AVLTree;

void InitTree(AVLTree& root) {
    root = NULL;
}

int GetHeight(Node* p) {
    return (p == NULL) ? 0 : p->height;
}

int GetBalanceFactor(Node* p) {
    return (p == NULL) ? 0 : GetHeight(p->left) - GetHeight(p->right);
}

Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
    x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;
    return x;
}

Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;
    y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
    return y;
}

Node* Insert(Node* root, int key) {
    if (root == NULL)
        return CreateNode(key);
    if (key < root->info)
        root->left = Insert(root->left, key);
    else if (key > root->info)
        root->right = Insert(root->right, key);
    else {
        root->count++;
        return root;
    }
    root->height = 1 + max(GetHeight(root->left), GetHeight(root->right));
    int balance = GetBalanceFactor(root);
    if (balance > 1 && key < root->left->info)
        return RotateRight(root);
    if (balance < -1 && key > root->right->info)
        return RotateLeft(root);
    if (balance > 1 && key > root->left->info) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && key < root->right->info) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }
    return root;
}

Node* Find(Node* root, int key) {
    if (root == NULL || root->info == key)
        return root;
    if (key < root->info)
        return Find(root->left, key);
    return Find(root->right, key);
}

Node* FindMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* Delete(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->info)
        root->left = Delete(root->left, key);
    else if (key > root->info)
        root->right = Delete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node* temp = FindMin(root->right);
            root->info = temp->info;
            root->right = Delete(root->right, temp->info);
        }
    }
    if (root == NULL)
        return root;
    root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
    int balance = GetBalanceFactor(root);
    if (balance > 1 && GetBalanceFactor(root->left) >= 0)
        return RotateRight(root);
    if (balance > 1 && GetBalanceFactor(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && GetBalanceFactor(root->right) <= 0)
        return RotateLeft(root);
    if (balance < -1 && GetBalanceFactor(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }
    return root;
}

void PreOrder(AVLTree root, int indent) {
    if (root != NULL) {
        DisplayNode(root, indent);
        PreOrder(root->left, indent + 3);
        PreOrder(root->right, indent + 3);
    }
}

int main() {
    AVLTree root;
    InitTree(root);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);
    cout << "Cay AVL sau khi chen:\n";
    PreOrder(root, 0);
    root = Delete(root, 30);
    cout << "Cay AVL sau khi xoa:\n";
    PreOrder(root, 0);

    int searchKey = 25;
    Node* foundNode = Find(root, searchKey);
    if (foundNode) {
        cout << "\nTim thay node co gia tri " << searchKey << ":\n";
        DisplayNode(foundNode, 0);
    }
    else {
        cout << "\nKhong tim thay node co gia tri " << searchKey << ".\n";
    }
    return 0;
}