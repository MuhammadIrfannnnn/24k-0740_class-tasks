#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
        Node*prev;
    Node(int data):data(data){
         next=NULL;
         prev=NULL;
    }
    Node(){
        next=NULL;
        prev=NULL;
    }
};

class DoubleLL{
    public:
    Node*head;
    Node*tail;

    DoubleLL(){
        head=NULL;
        tail=NULL;
    }

    void insertend(int val){
        Node*temp=new Node(val);
        if(head==NULL){
            head=tail=temp;
            return;
        }
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    void deletefront(){
        if(head==NULL){
            return;
        }
        Node*temp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        if(head!=NULL){
        head->prev=NULL;
        }
         temp->next=NULL;
         delete temp;
    }

         void search(int val){
        int idx=0;
        Node*temp=head;
        while (temp!=NULL)
        { 
            if(temp->data==val){
                cout<<"Yes Found at idx "<<idx<<": "<<temp->data<<endl;
                return;
            }
            temp=temp->next;
            idx++;
        }
        cout<<"Not found"<<endl;
    }


    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        return;
         }
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoubleLL L;
    L.insertend(45);
    L.insertend(49);
    L.insertend(52);
    L.insertend(53);
    L.insertend(61);
    cout<<"Initial Train compartments: "<<endl;
    L.display();
    cout<<"Add new compartment at end. "<<endl;
    L.insertend(65);
    cout<<"Delete first compartment. "<<endl;
    L.deletefront();
    cout<<"Search for a compartment: "<<endl;
    L.search(52);
    cout<<"Final train compartment (front to end): "<<endl;
    L.display();
    return 0;
}