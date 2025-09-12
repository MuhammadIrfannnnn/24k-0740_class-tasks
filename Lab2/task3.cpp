#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Enter number of teams: ";
    cin >> t;

    int** scores = new int*[t];
    int* n = new int[t];

    for (int i = 0; i < t; i++) {
        cout << "Enter number of player in team " << i + 1 << ": ";
        cin >> n[i];
        scores[i] = new int[n[i]];

        cout << "Enter score: ";
        for (int j = 0; j <n[i]; j++) {
            cin >> scores[i][j];
        }
    }

    cout <<endl<<"Team Sum:"<<endl;
    for (int i=0;i<t;i++) {
        int sum = 0;
        for (int j = 0; j <n[i];j++) {
            sum += scores[i][j];
        }
        cout <<"Team " << i + 1 << ": " << sum << endl;
    }

    for (int i =0;i<t;i++) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] n;

    return 0;
}