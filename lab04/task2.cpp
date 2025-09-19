#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sort{
    int arr[100];
    int n;
public:
    Sort(int size) {
        n = size;
        srand(time(0));
        for(int i=0;i<n;i++)
            arr[i] = rand()%100 + 1; 
    }

    void copyArray(int dest[]) {
        for(int i=0;i<n;i++){
            dest[i]=arr[i];
        }
    }

    void display(int a[]) {
        for(int i=0;i<n;i++){ 
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort() {
        int a[100];
        int comparisons=0;
        copyArray(a);
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-i-1;j++) {
                comparisons++;
                if(a[j] > a[j+1]){
                 swap(a[j],a[j+1]);
                }
            }
        }
        cout << "Bubble Sort: "; display(a);
        cout << "Comparisons: " << comparisons << endl;
    }

    void insertionSort() {
        int a[100];
        int comparisons=0;
        copyArray(a);
        for(int i=1;i<n;i++) {
            int key=a[i], j=i-1;
            while(j>=0 && (++comparisons && a[j]>key)) {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
        cout << "Insertion Sort: "; display(a);
        cout << "Comparisons: " << comparisons << endl;
    }

    void selectionSort() {
        int a[100], comparisons=0;
        copyArray(a);
        for(int i=0;i<n-1;i++) {
            int minIdx=i;
            for(int j=i+1;j<n;j++) {
                comparisons++;
                if(a[j]<a[minIdx]) minIdx=j;
            }
            swap(a[i],a[minIdx]);
        }
        cout << "Selection Sort: "; display(a);
        cout << "Comparisons: " << comparisons << endl;
    }

    void shellSort() {
        int a[100], comparisons=0;
        copyArray(a);
        for(int gap=n/2; gap>0; gap/=2) {
            for(int i=gap;i<n;i++) {
                int temp=a[i], j=i;
                while(j>=gap && (++comparisons && a[j-gap]>temp)) {
                    a[j]=a[j-gap];
                    j-=gap;
                }
                a[j]=temp;
            }
        }
        cout << "Shell Sort: "; display(a);
        cout << "Comparisons: " << comparisons << endl;
    }
};

int main() {
    cout << "Sorting 20 Random Integers" << endl;
    Sort s20(20);
    s20.bubbleSort();
    s20.insertionSort();
    s20.selectionSort();
    s20.shellSort();

    cout<<"Sorting 100 Random Integers"<< endl;
    Sort s100(100);
    s100.bubbleSort();
    s100.insertionSort();
    s100.selectionSort();
    s100.shellSort();
    return 0;
}