#include <iostream>
using namespace std;

class Matrix {
private:
    int** mat;
    int row, col;

    void allocate(int r, int c) {
        row = r;
        col = c;
        mat = new int*[row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }

public:
    Matrix(int r, int c) {
        allocate(r, c);
    }

    void fillMatrix() {
        cout << "Enter values row by row:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void resize(int newR, int newC, int fillVal) {
        int** newMat = new int*[newR];
        for (int i = 0; i < newR; i++) {
            newMat[i] = new int[newC];
            for (int j = 0; j < newC; j++) {
                if (i < row && j < col)
                    newMat[i][j] = mat[i][j];
                else
                    newMat[i][j] = fillVal;
            }
        }

        for (int i = 0; i < row; i++){
             delete[] mat[i];
            delete[] mat;
        }

        mat = newMat;
        row =newR;
        col =newC;
    }

    void transpose() {
        int** trans = new int*[col];
        for (int i = 0; i < col; i++) {
            trans[i] = new int[row];
            for (int j = 0; j < row; j++) {
                trans[i][j] = mat[j][i];
            }
        }

        for (int i = 0; i < row; i++) delete[] mat[i];
        delete[] mat;

        mat = trans;
        int temp = row;
        row = col;
        col = temp;
    }

    void printMatrix() {
        cout << "Matrix:"<<endl;
        for (int i = 0; i<row; i++) {
            for (int j = 0; j < col; j++) {
                int val = mat[i][j];
                if ((i + j) % 2 == 1) val += 2;
                cout << val << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < row; i++) delete[] mat[i];
        delete[] mat;
    }
};

int main() {
    int r, c;
    cout << "Enter number of row and col: ";
    cin >> r;
    cin>>c;

    Matrix M(r, c);
    M.fillMatrix();
    cout << "Original Matrix:"<<endl;
    M.printMatrix();

    M.transpose();
    cout << "Transpose matrix:"<<endl;
    M.printMatrix();

    M.resize(r + 1, c + 1, 0);
    cout << "Resize:"<<endl;
    M.printMatrix();

    return 0;
}