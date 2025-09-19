#include <iostream>
using namespace std;

class InterpolationSearch{
    int arr[100];
    int n;
public:
    void input() {
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter " << n << " elements (unsorted): ";
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

    int interpolationSearch(int key) {
        int low=0, high=n-1;
        while(low<=high && key>=arr[low] && key<=arr[high]) {
            if(low==high) {
                if(arr[low]==key) return low;
                return -1;
            }
            int pos=low+((double)(high-low)/(arr[high]-arr[low]))*(key-arr[low]);
            if(arr[pos]==key){
                 return pos;
            }
            if(arr[pos]<key){
                 low=pos+1;
            }
            else{
                 high=pos-1;
            }
        }
        return -1;
    }

    void searchKey() {
        int key;
        cout << "Enter key to search: ";
        cin >> key;
        int result=interpolationSearch(key);
        if(result!=-1) {
            cout<<"Element found at index "<<result<<endl;
        }
        else{
             cout << "Element not found" << endl;
        }
    }
};

int main() {
    InterpolationSearch is;
    is.input();
    is.sort();
    is.searchKey();
    return 0;
}