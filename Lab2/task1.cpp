#include<iostream>
using namespace std;



class Dynamicarray{
    public:
    int n;
    int *arr;
    int count;

    Dynamicarray(){
        n=0;
        arr=NULL;
        count=0;
    }

    Dynamicarray(int size):n(n){
        arr=new int[n];
        count=0;
    }

    void push(int val){
        if(count<n){

            arr[count++]=val;
        }
        else{

            int size=n*2;
            int *temp=new int[n];

            for(int i=0;i<n;++i){
                temp[i]=arr[i];
            }

            delete []arr;
            arr=new int[size];

            for(int i=0;i<size;++i){
                arr[i]=temp[i];
            }

            arr[count++]=val;
            n=size;
            
            
        }
    }

    void printing(){
        
        for(int i=0;i<count;++i){
            cout<<arr[i]<<" ";
        }

    }

    ~Dynamicarray(){
        delete []arr;
        arr=NULL;
    }
};
int main(){

    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    Dynamicarray D(5);


    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);
    D.printing();
    cout<<endl;
    D.push(6);
    D.printing();




}