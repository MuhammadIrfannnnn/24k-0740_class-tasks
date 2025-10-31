#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int quantity;
    Node* left;
    Node* right;
    Node(int pid, int qty) {
        id = pid;
        quantity = qty;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int pid, int qty) {
        if (node == nullptr) return new Node(pid, qty);
        if (pid < node->id)
            node->left = insert(node->left, pid, qty);
        else if (pid > node->id)
            node->right = insert(node->right, pid, qty);
        else
            node->quantity += qty;
        return node;
    }

    void addProduct(int pid, int qty) {
        root = insert(root, pid, qty);
    }

    Node* search(Node* node, int pid) {
        if (node == nullptr || node->id == pid) return node;
        if (pid < node->id) return search(node->left, pid);
        return search(node->right, pid);
    }

    Node* findLCA(Node* node, int id1, int id2) {
        if (node == nullptr) return nullptr;

        if (id1 < node->id && id2 < node->id)
            return findLCA(node->left, id1, id2);

        if (id1 > node->id && id2 > node->id)
            return findLCA(node->right, id1, id2);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "Product ID: " << node->id << "  Quantity: " << node->quantity << endl;
        inorder(node->right);
    }
};

int main() {
    BST tree;

    tree.addProduct(30, 15);
    tree.addProduct(70, 25);
    tree.addProduct(20, 18);
    tree.addProduct(60, 30);
    tree.addProduct(40, 12);
    tree.addProduct(20, 10);
    tree.addProduct(50, 20);

    tree.addProduct(60, 5); 

    cout << "All Products:\n";
    tree.inorder(tree.root);

    int emp1 = 50, emp2 = 20;
    Node* manager = tree.findLCA(tree.root, emp1, emp2);

    if (manager)
        cout << "\nClosest common manager for Employee "
             << emp1 << " and " << emp2 << " is Employee ID: "
             << manager->id << endl;
    else
        cout << "\nNo common manager found.\n";
    
    return 0;
}
