#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class HashTable {
private:
    int bucketCount;
    Node** table;  

    int hashFunction(const string& key) {
        int sum = 0;
        for (int i=0;i<key.length();i++){
            sum += int(key[i]);
        }
        int index=sum%bucketCount;
        return index;
    }

public:
    HashTable(int size) {
        bucketCount = size;
        table = new Node*[bucketCount];
        for (int i = 0; i < bucketCount; i++)
            table[i] =NULL;
    }

    void insert(const string& key) {
        int index = hashFunction(key);
        Node* newnode = new Node(key);
        newnode->next = table[index];
        table[index] = newnode;
    }

    bool search(const string& key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->data == key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            if (!curr) {
                cout << "NULL"<<endl;
                continue;
            }
            while (curr) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL"<<endl;
        }
        cout << endl;
    }

    ~HashTable() {
        for (int i = 0; i < bucketCount; i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() {
    HashTable ht(10);
    ht.insert("apple");
    ht.insert("mango");
    ht.insert("apple");
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");
    ht.display();

    cout << "Searching apple: ";
    if(ht.search("apple")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout << "Searching orange: ";
    if(ht.search("orange")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}
