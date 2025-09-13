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

    void deletefront(){
        Node* temp=head;
        if(head==NULL){
            return;
        }
        head=temp->next;
        temp->next=NULL;
        delete temp;
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

     void search(string data){
        int idx=0;
        Node*temp=head;
        while (temp!=NULL)
        {
            
            if(temp->data==data){
                cout<<"Yes Found at idx "<<idx<<": "<<temp->data<<endl;
                return;
            }
            temp=temp->next;
             idx++;
           
        }
        cout<<"Not found"<<endl;
    }

    void search(int pos){
        int idx=0;
        Node*temp=head;
        while (temp!=NULL)
        {
           
            if(idx==pos){
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
    L1.insertend("Data Structures");
    L1.insertend("Operating System");
    L1.insertend("Computer Network");
    L1.insertend("Database Systems");
    cout<<"Initial List: "<<endl;
    L1.display();
    cout<<"Add book at the end of list. "<<endl;
    L1.insertend("Machine Learning");
    cout<<"Delete book from front. "<<endl;
    L1.deletefront();
    cout<<"Search by title: "<<endl;
    L1.search("Computer Network");
    cout<<"Search by index: "<<endl;
    L1.search(2);
    cout<<"Final list: "<<endl;
    L1.display();

}