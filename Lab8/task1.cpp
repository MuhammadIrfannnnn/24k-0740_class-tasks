#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;
    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
public:
    Node* create() {
        string val;
        cout << "Enter package name (or 'none'): ";
        cin >> val;
        if (val == "none"){
            return NULL;
        } 
        Node* node = new Node(val);
        cout << "Left of " << val << endl;
        node->left = create();
        cout << "Right of " << val << endl;
        node->right = create();
        return node;
    }
    void display(Node* root, int space = 0) {
        if (!root) return;
        space += 5;
        display(root->right, space);
        cout << endl;
        for (int i = 5; i < space; i++){
            cout << " ";
        } 
        cout << root->data << endl;
        display(root->left, space);
    }
};

int main() {
    Tree t;
    Node* root = t.create();
    cout <<"Tour Hierarchy:"<<endl;
    t.display(root);
}
