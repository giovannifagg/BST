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

Node* insert(Node* root, int val);
int countNodes(Node* root);
int countLeaves(Node* root);

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    int nodi = countNodes(root);
    int foglie = countLeaves(root);

    if (nodi != 0) {
        cout << "Numero di nodi: " << nodi << "\n";
    } else {
        cout << "L'albero e' vuoto.\n";
    }

    if (foglie != 0) {
        cout << "Numero di foglie: " << foglie << "\n";
    } else {
        cout << "L'albero e' vuoto.\n";
    }
    
    system("PAUSE");
    return 0;
}

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

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}