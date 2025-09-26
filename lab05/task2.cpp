#include <iostream>
using namespace std;

void printSolution(int sol[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool Safe(int maze[5][5], int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1);
}

bool solve(int maze[5][5], int x, int y, int sol[5][5]) {
    if (x==4 && y==4 && maze[x][y]==1) {
        sol[x][y] = 1;
        return true;
    }
    if (Safe(maze, x, y)) {
        sol[x][y] = 1;

        if (solve(maze, x, y + 1, sol)){
            return true;
        }
        if (solve(maze, x + 1, y, sol)){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void solveMaze(int maze[5][5]) {
    int sol[5][5] = {0}; 
    if (!solve(maze, 0, 0, sol)) {
        cout << "No path exists for the lion to reach meat"<<endl;
    } else {
        cout << "Solution path 1's show the lion's path:" << endl;
        printSolution(sol);
    }
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 1, 1}
    };
    cout<<"Initial Maze to reach meat"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    solveMaze(maze);
    return 0;
}
