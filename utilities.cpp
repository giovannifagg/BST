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
bool iterativeSearch(Node* root, int val);
Node* findMin(Node* root);
Node* findMax(Node* root);

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    int numero;
    cout << "Inserisci il numero da cercare: ";
    cin >> numero;

    if (iterativeSearch(root, numero)) {
        cout << "Ricerca: il numero " << numero << " e' presente" << endl;
    } else {
        cout << "Ricerca: il numero " << numero << " NON e' presente" << endl;
    }

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

    int nodes = countNodes(root);
    int leaves = countLeaves(root);

    if (nodes != 0) {
        cout << "Numero di nodi: " << nodes << "\n";
    } else {
        cout << "L'albero e' vuoto.\n";
    }

    if (leaves != 0) {
        cout << "Numero di foglie: " << leaves << "\n";
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

bool iterativeSearch(Node* root, int val) {
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