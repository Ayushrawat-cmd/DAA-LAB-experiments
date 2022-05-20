#include<bits/stdc++.h>
using namespace std;
int main(){
    clock_t start,end;
    start = clock();
    int capacity;
    cout<<"Enter the capacity of bag:- ";
    cin>>capacity;
    int n;
    cout<<"\nEnter the number of items:- ";
    cin>>n;
    int cost[n], wt[n];
    cout<<"\nEnter the Weight and cost of each item respectively:- \n";
    for(int i =0; i<n; i++){
        cout<<"Enter weight of item "<<i+1<<":- ";
        cin>>wt[i];
        cout<<"Enter cost of item "<<i+1<<":- ";
        cin>>cost[i];
    }
    cout<<"\nYour input is:- \n";
    cout<<"Items\tValue\tWeight\n";
    for(int i =0; i<n; i++){
        cout<<i+1<<"\t"<<cost[i]<<"\t"<<wt[i]<<endl;
    }
    int mat[n+1][capacity+1] ;
    for(int i=0 ; i<=capacity; i++){
        mat[0][i]= 0;
    }
    for(int i=0 ; i<=n; i++){
        mat[i][0]= 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(j<wt[i-1]){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = max(cost[i-1]+mat[i-1][j-wt[i-1]],mat[i-1][j]);
            }
        }
    }
    cout<<"Maximum Cost:- "<<mat[n][capacity];
    end = clock();
    int j=capacity, i =n, maxm=0;
    vector<int>items;
    while(maxm!=mat[n][capacity]){
        if(mat[i][j] == mat[i-1][j]){
            i--;
        }
        else{
            maxm+=cost[i-1];
            items.push_back(i);
            j = j-wt[i-1];
            i--;
        }
    }
    cout<<"\n\nItems which are included:- \n";
    for(int i=0; i<items.size(); i++){
        cout<<items[i]<<"\t";
    }
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
}