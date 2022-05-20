#include<bits/stdc++.h>
using namespace std;
void merge_sorted_arrays(vector<int>&a,int l, int r, int mid){
    vector<int>left;
    vector<int>right;
    for(int i=l; i<=mid; i++){
        left.push_back(a[i]);
            // cout<<left[i];
    }
    for(int j=mid+1; j<=r; j++){
        right.push_back(a[j]);
    }
    int i=0,j=0, k=l;
    while(i<left.size() and j<right.size()){
        if(left[i]<right[j]){
            a[k] = left[i];
            k++;i++;
        }
        else{
            a[k] = right[j];
            k++;j++;
        }
    }
    while(i<left.size()){
        a[k] = left[i];
        k++;i++;
    }
    while(j<right.size()){
        a[k] = right[j];
        k++;j++;
    }
}
void merge_sort(vector<int>& a,int i, int j){
    int mid = i+(j-i)/2;
    if(i<j){
        merge_sort(a,i,mid);
        merge_sort( a,mid+1,j);
        merge_sorted_arrays(a,i,j,mid);
    }
    return;
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
    merge_sort(a,0,n-1);
    cout<<"Elements after sorted:- ";
    for(auto i :a){
        cout<<i<<" ";
    }
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);

}