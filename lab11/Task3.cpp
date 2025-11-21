#include <iostream>
using namespace std;

class Hash {
private:
    int tableSize;
    int* table;

public:
    Hash(int size = 10) {
        tableSize = size;
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);

        int originalIndex = index;
        while (table[index] != -1 && table[index] != -2) {
            index = (index + 1) % tableSize;

            if (index == originalIndex) {
                cout << "Hash Table is full! Cannot insert."<<endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted: " << key << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);

        int originalIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex){
                break;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);

        int originalIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -2; 
                cout << "Deleted: " << key << endl;
                return;
            }
            index = (index + 1) % tableSize;

            if (index == originalIndex){
                break;
            }
        }
        cout << "Key " << key << " not found!"<<endl;
    }

    void display() {
        cout << endl<<"Hash Table:"<<endl;
        for (int i = 0; i < tableSize; i++) {
            if (table[i] == -1)
                cout << i << " : EMPTY"<<endl;
            else if (table[i] == -2)
                cout << i << " : DELETED"<<endl;
            else
                cout << i << " : " << table[i] << endl;
        }
        cout << endl;
    }

    ~Hash() {
        delete[] table;
    }
};

int main() {
    Hash h(10);
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);
    h.display();
    h.remove(4);
    h.display();
    if(h.search(5)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    if(h.search(6)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    

}
