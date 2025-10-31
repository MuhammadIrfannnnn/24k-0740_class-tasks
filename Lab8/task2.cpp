#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = NULL; }
};

class Tree {
public:
    Node* create() {
        int v;
        cout << "Enter value (-1 for null): ";
        cin >> v;
        if (v == -1) return NULL;
        Node* n = new Node(v);
        n->left = create();
        n->right = create();
        return n;
    }
    int count(Node* r) {
        return r ? 1 + count(r->left) + count(r->right) : 0;
        }
    int leaves(Node* r) {
        if (!r) return 0;
        if (!r->left && !r->right) return 1;
        return leaves(r->left) + leaves(r->right);
    }
    int height(Node* r) {
        if (!r){
            return 0;
        } 
        int l = height(r->left), h = height(r->right);
        return 1 + (l > h ? l : h);
    }
};

int main() {
    Tree t;
    Node* root = t.create();
    cout << "Nodes: " << t.count(root) << endl;
    cout << "Leaves: " << t.leaves(root) << endl;
    cout << "Height: " << t.height(root) << endl;
}
