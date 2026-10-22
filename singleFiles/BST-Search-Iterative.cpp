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

bool ricercaIterativa(Node* root, int val) {
    Node* current = root;

    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }

        if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    int numero;
    cout << "Inserisci il numero da cercare: ";
    cin >> numero;

    if (ricercaIterativa(root, numero)) {
        cout << "Ricerca: il numero " << numero << " e' presente" << endl;
    } else {
        cout << "Ricerca: il numero " << numero << " NON e' presente" << endl;
    }
    
    return 0;
}