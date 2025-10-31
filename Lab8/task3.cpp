#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v; 
        left = right = NULL;
    }
};

class FullTree {
public:
    Node* create() {
        int v;
        cout << "Enter value (-1 for null): ";
        cin >> v;
        if (v == -1){
            return NULL;
        }
        Node* n = new Node(v);
        n->left = create();
        n->right = create();
        return n;
    }
    bool isFull(Node* r) {
        if (!r){
           return true; 
        } 
        if (!r->left && !r->right){
            return true;
        } 
        if (r->left && r->right) {
            return isFull(r->left) && isFull(r->right);
        }
        return false;
    }
};

int main() {
    FullTree t;
    Node* root = t.create();
    cout << (t.isFull(root) ? "Full Binary Tree" : "Not Full Binary Tree");
}
