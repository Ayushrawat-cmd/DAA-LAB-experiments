#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&a, int l,int h){
    int pivot_idx = l +rand()%(h-l);
    swap(a[l],a[pivot_idx]);
    int i=l,j =h, pivot =a[l] ;
    do{
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<j);
    swap(a[l],a[j]);
    return j;
}
void quick_sort(vector<int>&a, int l, int h){
    if(l<h){
        int pivot = partition(a,l,h);
        quick_sort(a, l, pivot);
        quick_sort(a, pivot+1, h);
    }
}
int main(){
    clock_t start,end;
    start = clock();
    int n;
    vector<int>a ;
    cout<<"Enter the size of array:- ";
    cin>>n;
    cout<<"Enter "<<n<<" elements in the array:- ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    quick_sort(a,0,n);
    cout<<"Elements after sorted:- ";
    for(auto i :a){
        cout<<i<<" ";
    }
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
}
// 3 4 2 1 5
// 3 2 1 4 5
// 3 1 2 4 5
// 1 2 3 4 5