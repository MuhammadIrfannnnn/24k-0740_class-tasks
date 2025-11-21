#include <iostream>
using namespace std;

class StudentHashTable {
private:
    struct Student {
        int rollNumber;
        string name;
        bool isOccupied; 
        Student() : rollNumber(0), name(""), isOccupied(false) {}
    };

     static const int size = 15;
    Student table[size];


    int hashFunction(int rollNumber) {
        return rollNumber%size;
    }
public:
    void InsertRecord(int rollNumber, const string& name) {
        int index = hashFunction(rollNumber);
        int attempt = 0;

        while (attempt < size) {
            int newIndex = (index + attempt * attempt) %size;
            if (!table[newIndex].isOccupied) {
                table[newIndex].rollNumber = rollNumber;
                table[newIndex].name = name;
                table[newIndex].isOccupied = true;
                cout << "Inserted " << name << " at index " << newIndex << endl;
                return;
            }
            attempt++;
        }
        cout << "Hash table is full! Cannot insert record." << endl;
    }

    void SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;

        while (attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if (table[newIndex].isOccupied && table[newIndex].rollNumber == rollNumber) {
                cout << "Student found: " << table[newIndex].name << endl;
                return;
            }
            if (!table[newIndex].isOccupied) {
                break;
            }
            attempt++;
        }

        cout << "Record not found" << endl;
    }

    void DisplayTable() {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i <size; i++) {
            cout << i << ": ";
            if (table[i].isOccupied) {
                cout << table[i].rollNumber << " - " << table[i].name;
            } else {
                cout << "Empty";
            }
            cout << endl;
        }
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(10, "Irfan");
    sht.InsertRecord(25, "Hasan");
    sht.InsertRecord(40, "Huzaifa");
    sht.InsertRecord(55, "Ahmed");
    sht.DisplayTable();
    cout << endl;
    sht.SearchRecord(25); 
    sht.SearchRecord(50);

    return 0;
}
