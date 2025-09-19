#include <iostream>
using namespace std;

class Sort{
    int arr[100];
    int n;
    int comparisons;

public:
    Sort(int a[], int size){
        n = size;
        for(int i = 0; i < n; i++)
            arr[i] = a[i];
        comparisons = 0;
    }

    void bubbleSort() {
         for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

    void display() {
        cout<<"Sorted Array: ";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "Total Comparisons: " << comparisons << endl;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n=7;
    Sort bs(arr, n);
    bs.bubbleSort();
    bs.display();
    return 0;
}
