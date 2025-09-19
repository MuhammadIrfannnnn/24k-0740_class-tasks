#include <iostream>
using namespace std;

class BinarySearch {
    int arr[100], n;
public:
    void input() {
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter " << n << " elements: ";
        for(int i=0;i<n;i++) cin >> arr[i];
    }

    void sort() {
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-i-1;j++) {
                if(arr[j]>arr[j+1]){
                     swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    int binarySearch(int key) {
        int low=0, high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]<key) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }

    void searchKey() {
        int key;
        cout << "Enter key to search: ";
        cin >> key;
        int result=binarySearch(key);
        if(result!=-1){
             cout << "Element found at index " << result << endl;
        }
        else{
             cout << "Element not found" << endl;
        }
    }
};

int main() {
    BinarySearch bs;
    bs.input();
    bs.sort();
    bs.searchKey();
    return 0;
}