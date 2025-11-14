#include<iostream>

using namespace std;
class Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
        height = 0; 
    }
};

int height(Node *N){
    if (N == nullptr)
        return -1;
    return N->height;
}

int getBalance(Node *N){
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

void inorder(Node*root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void BF(Node*root){
    if(root==nullptr){
        return;
    }
    BF(root->left);
    cout<<"Balance factor of: "<<root->key<< " is: "<<getBalance(root)<<endl;
    BF(root->right);
}




Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}


 Node *insert(Node *node, int key){
    if (node == nullptr){
        Node *newNode = new Node(key); 
        return newNode;
    }
    if (key<node->key){
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main(){
    
    Node *root = nullptr;
    int rollno[] = {10,5,15,3,7};
    for (int i=0;i<5;i++ ){
        root=insert(root,rollno[i]);
    }
    cout<<"Inserting 12"<<endl;
    root=insert(root,12);
    
    cout<<endl;
    cout<<"height of the tree is: "<<root->height;
    BF(root);

    cout<<"Final balanced AVL Tree"<<endl;
    inorder(root);

}