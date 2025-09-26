#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(int players, int target, int turn) {
    int currentPlayer = (turn%players)+1; 
    int guess;
    cout<<"Player "<<currentPlayer<<" enter your guess (1-100): ";
    cin>>guess;
    if (guess==target) {
        cout<<"Player "<<currentPlayer<<" wins! The correct number was "<<target<<endl;
        return; 
    } 
    else if (guess<target) {
        cout<< "Too low Try again"<<endl;
    } 
    else {
        cout<< "Too high Try again"<<endl;
    }

    guessGame(players,target,turn+1);
}
int main() {
    srand(time(0)); 
    int target = rand() % 100 + 1; 
    int players;
    cout << "Enter number of players: ";
    cin >> players;
    cout<<"guess the number between 1 and 100"<<endl;
    guessGame(players, target,0); 

    return 0;
}