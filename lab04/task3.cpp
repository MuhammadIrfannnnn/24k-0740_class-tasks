#include <iostream>
using namespace std;

class Sort{
    int arr[100];
    int n;
public:
    void input() {
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter " << n << " elements: ";
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
    }

    void shellSort() {
        for(int gap=n/2; gap>0; gap/=2) {
            for(int i=gap;i<n;i++) {
                int temp=arr[i], j=i;
                while(j>=gap && arr[j-gap]>temp) {
                    arr[j]=arr[j-gap];
                    j-=gap;
                }
                arr[j]=temp;
            }
        }
    }

    void display() {
        cout << "Sorted Array: ";
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Sort ss;
    ss.input();
    ss.shellSort();
    ss.display();
    return 0;
}