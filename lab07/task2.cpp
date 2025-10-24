#include<iostream>
using namespace std;

struct runner{
    string name;
    int time;
};
void merge(runner r[10],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    runner*L=new runner[n1];
    runner*R=new runner[n2];

    for(int i=0;i<n1;i++){
        L[i]=r[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=r[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i].time<=R[j].time){
            r[k]=L[i];
            i++;
        }else{
            r[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        r[k]=L[i];
        i++;
        k++;
    }
     while(j<n2){
        r[k]=R[j];
        j++;
        k++;
    }
    delete []L;
    delete []R;
}

void mergesort(runner r[10],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(r,left,mid);
        mergesort(r,mid+1,right);
        merge(r,left,mid,right);
    }
}

int main(){
    int n=10;
    runner r[10];
    for(int i=0;i<n;i++){
        cout<<"Runner" <<i+1<< "name:";
        cin>>r[i].name;
        cout<<"Finish Time(in seconds): ";
        cin>>r[i].time;
    }
    mergesort(r,0,n-1);
    cout<<"Top 5 fastest runners: "<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<" "<<r[i].name<<" "<<r[i].time<<"sec"<<endl;
    }

}