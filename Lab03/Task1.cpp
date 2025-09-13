#include<iostream>
using namespace std;

class Node{
    public:
    string data;
    Node*next;

    Node(){
        next=NULL;
    }
    Node(string data):data(data){
        next=NULL;
    }
};

class List{
    public:
    Node*head;
    Node*tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    void insertfront(string data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void insertend(string data){
        Node* newnode=new Node(data); 
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void insert(string data,string pos){
        Node*newnode=new Node(data);
        Node * temp=head;
        while (temp->data!=pos)
        {
            temp=temp->next;
        }
        
        Node*t2=temp->next;
        temp->next=newnode;
        newnode->next=t2;
    }

     void search(string data){
        int idx=0;
        Node*temp=head;
        while (temp!=NULL)
        {
            if(temp->data==data){
                cout<<"Yes Found: "<<temp->data<<endl;
                return;
            }
            temp=temp->next;
            idx++;
        }
        cout<<"Not found"<<endl;
    }

    void display(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" | ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    List L1;
    L1.insertfront("Data Structures");
    L1.insertend("Operating System");
    L1.insertend("Computer Network");
    L1.insertend("Database Systems");
    cout<<"Initial List: "<<endl;
    L1.display();
    cout<<"Add New Book at front of list. "<<endl;
    L1.insertfront("Artificiall Intelligence");
    cout<<"Add New Book at end of list. "<<endl;
    L1.insertend("Machine Learning");
    cout<<"Insert after operating system. "<<endl;
    L1.insert("Cyber Security","Operating System");
    cout<<"Search for book: "<<endl;
    L1.search("Database Systems");
    cout<<"Final List: "<<endl;
    L1.display();
    return 0;

}