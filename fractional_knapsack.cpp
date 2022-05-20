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
    double ratio[n];
    vector<pair<double,pair<int,int>>>help;
    cout<<"\nEnter the Weight and cost of each item respectively:- \n";
    for(int i =0; i<n; i++){
        cout<<"Enter weight of item "<<i+1<<":- ";
        cin>>wt[i];
        cout<<"Enter cost of item "<<i+1<<":- ";
        cin>>cost[i];;
        ratio[i] = (double)cost[i]/(double)wt[i];
    }
    cout<<"\nYour input is:- \n";
    cout<<"Items\tValue\tWeight\tRatio\n";
    for(int i =0; i<n; i++){
        cout<<i+1<<"\t"<<cost[i]<<"\t"<<wt[i]<<"\t"<<ratio[i]<<endl;
    }
    for(int i=0; i<n; i++){
        help.push_back(make_pair(ratio[i],make_pair(wt[i],cost[i])));
    }
    sort(help.begin(),help.end());
    // for(int i=0; i<n; i++){
    //     cout<<help[i].second.second<<" ";
    // }
    int i = n-1;
    double ans=0.0;
    while(capacity!=0 and i>=0){
        if(capacity>=help[i].second.first){
            ans+=(double)help[i].second.second;
            capacity-=help[i].second.first;
        }
        else{
            ans+=((double)help[i].second.second)*((double)capacity/(double)help[i].second.first);
            capacity = 0;
        }
        i--;
    }
    cout<<"Maximum Cost:- "<<ans;
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
}