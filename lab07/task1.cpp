#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, nullptr};
    if (head == nullptr)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

int getMax(Node* head) {
    int max = 0;
    while (head != nullptr) {
        if (head->score > max)
            max = head->score;
        head = head->next;
    }
    return max;
}

int getDigit(int number, int place) {
    return (number / place) % 10;
}

Node* countingSort(Node* head, int place) {
    Node* buckets[10] = {nullptr};
    Node* tails[10] = {nullptr};
    Node* current = head;
    while (current != nullptr) {
        int digit = getDigit(current->score, place);
        Node* nextNode = current->next;
        current->next = nullptr; 

        if (buckets[digit] == nullptr)
            buckets[digit] = tails[digit] = current;
        else {
            tails[digit]->next = current;
            tails[digit] = current;
        }
        current = nextNode;
    }
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (buckets[i] != nullptr) {
            if (newHead == nullptr)
                newHead = buckets[i];
            else
                newTail->next = buckets[i];
            newTail = tails[i];
        }
    }

    return newHead;
}
void radixSort(Node*& head) {
    int maxScore = getMax(head);

    for (int place = 1; maxScore / place > 0; place *= 10) {
        head = countingSort(head, place);
    }
}
void display(Node* head) {
    cout << "\n--- Sorted Student Records by Score ---\n";
    while (head != nullptr) {
        cout << "Name: " << head->name << "\tScore: " << head->score << endl;
        head = head->next;
    }
    cout << "---------------------------------------\n";
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter score (0–100): ";
        cin >> score;
        cin.ignore();

        insert(head, name, score);
    }
    radixSort(head);
    display(head);

    return 0;
}
