#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[], int key, int first ,int last){
    int mid = (first+last)/2;
    if(first<last){
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid]>key){
            return binary_search(a,key,first,mid);
        }
        else{
            return binary_search(a,key,mid+1,last);
        }
    }
    return -1;
}
int main(){
    clock_t start,end;
    start = clock();
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:: \n";
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    int key;
    cout<<"\nEnter the element you want to search:- ";
    cin>>key;
    if(binary_search(a,key, 0, n) ==-1){
        cout<<key<<" not found";
    }
    else{
        cout<<key<<" found at position "<<binary_search(a,key,0,n)+1<<" in array";
    }
    end = clock();
    double time_taken = double(end -start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
}
