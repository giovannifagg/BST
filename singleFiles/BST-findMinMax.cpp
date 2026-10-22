#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node * current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    return current;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    Node* minVal = findMin(root);
    Node* maxVal = findMax(root);

    if (minVal != nullptr) {
        cout << "Valore minimo: " << minVal->data << "\n";
    } else {
        cout << "L'albero e' vuoto.";
    }

    if (maxVal != nullptr) {
        cout << "Valore massimo: " << maxVal->data << "\n";
    } else {
        cout << "L'albero e' vuoto.";
    }
    
    system("PAUSE");
    return 0;
}