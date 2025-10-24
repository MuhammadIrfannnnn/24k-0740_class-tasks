#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    double price;
    string description;
    bool availability;
};
int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayProducts(Product arr[], int n) {
    cout <<endl<< "Sorted Product List by Price"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: "<<arr[i].name<<endl;
        cout << "Price: $" << arr[i].price<<endl;
        cout << "Description: " << arr[i].description << endl;
        cout << "Availability: " << (arr[i].availability ? "In stock" : "Out of stock")<<endl;
        cout << "-----------------------------------"<<endl;
    }
}

int main() {
    int n = 3;
    Product products[3];
    for (int i = 0;i<n; i++) {
        cout << "Enter details for product " << i + 1 <<endl;
        cout << "Name: ";
        getline(cin, products[i].name);
        cout << "Price: ";
        cin >> products[i].price;
        cin.ignore(); 
        cout << "Description: ";
        getline(cin, products[i].description);
        cout << "Availability (1 = In stock, 0 = Out of stock): ";
        cin >> products[i].availability;
        cin.ignore();
        cout << endl;
    }
    quickSort(products, 0,n-1);
    displayProducts(products,n);

    return 0;
}
