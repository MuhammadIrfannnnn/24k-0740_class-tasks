#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = nullptr;
    }
};

class Dictionary {
private:
    Node* table[100];

    int hashFunction(const string& w) {
        int sum = 0;
        for (char c : w)
            sum += int(c);
        return sum % 100;
    }

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = nullptr;
    }

    void insert(const string& w) {
        int index = hashFunction(w);
        Node* newNode = new Node(w);

        newNode->next = table[index];
        table[index] = newNode;

        cout << "Word " << w << " added successfully!"<<endl;
    }

    void Search(const string& w) {
        int index = hashFunction(w);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->word == w) {
                cout << "Word " << w << " found in dictionary"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Word " << w << " NOT found"<<endl;
    }

    void display() {
        cout <<endl<<"Dictionary Contents"<<endl;
        for (int i = 0; i<100; i++) {
            cout << "Bucket "<<i<<": ";
            Node* temp = table[i];
            if (!temp) {
                cout << "NULL"<<endl;
                continue;
            }
            while (temp) {
                cout << temp->word << "->";
                temp=temp->next;
            }
            cout << "NULL"<<endl;
        }
        cout<<endl;
    }
};

int main() {
    Dictionary dict;
    int choice;
    string input;

    while (true) {
        cout << endl<<"ASCII Dictionary Menu"<<endl;
        cout << "1. Add Record"<<endl;
        cout << "2. Search Word"<<endl;
        cout << "3. Print Dictionary"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter word to add: ";
            cin >> input;
            dict.insert(input);
            break;
        case 2:
            cout << "Enter word to search: ";
            cin >> input;
            dict.Search(input);
            break;
        case 3:
            dict.display();
            break;
        case 4:
            cout<<"Exiting program"<<endl;
            return 0;
        default:
            cout<<"Invalid choice! Try again"<<endl;
        }
    }
}
