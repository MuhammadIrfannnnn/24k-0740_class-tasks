#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable {
private:
    static const int size = 50;
    struct Employee {
        string name;
        bool isOccupied;
        Employee() : name(""), isOccupied(false) {}
    };

    Employee table[size];
    int primaryHash(const string& name) {
        int sum = 0;
        for (char ch : name) {
            sum += int(ch);
        }
        return sum % size;
    }

    int secondaryHash(const string& name) {
        int sum = 0;
        for (char ch : name) {
            sum += int(ch);
        }
        return 7 - (sum % 7);
    }

public:
    void Add_Employee(const string& name) {
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);

        int i = 0;
        while (i <size) {
            int newIndex = (h1 + i * h2) %size;
            if (!table[newIndex].isOccupied) {
                table[newIndex].name = name;
                table[newIndex].isOccupied = true;
                cout << "Inserted " << name << " at index " << newIndex << endl;
                return;
            }
            i++;
        }

        cout << "Hash table is full! Cannot insert employee." << endl;
    }
    void Search_Employee(const string& name) {
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);

        int i = 0;
        while (i < size) {
            int newIndex = (h1 + i * h2) % size;
            if (table[newIndex].isOccupied && table[newIndex].name == name) {
                cout << "Employee found at index " << newIndex << ": " << table[newIndex].name << endl;
                return;
            }
            if (!table[newIndex].isOccupied) {
                break;
            }
            i++;
        }

        cout << "Employee not found in the directory." << endl;
    }
    void Display_Table() {
        cout <<endl<< "Employee Hash Table:"<<endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].isOccupied)
                cout << table[i].name;
            else
                cout << "Empty";
            cout << endl;
        }
    }
};

int main() {
    EmployeeHashTable eht;

    eht.Add_Employee("Irfan");
    eht.Add_Employee("Huzaifa");
    eht.Add_Employee("Hasan");
    eht.Add_Employee("Ahmed");
    eht.Add_Employee("Mehda");
    eht.Display_Table();
    cout << endl;
    eht.Search_Employee("Irfan"); 
    return 0;
}
