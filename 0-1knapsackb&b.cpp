#include<bits/stdc++.h>
using namespace std;
pair<int,int> fractional_knapsack(int wt[], int cost[], int n, int capacity){
    vector<pair<double,pair<int,int>>>help;
    for(int i=0; i<n; i++){
        help.push_back(make_pair((double)cost[i]/(double)wt[i],make_pair(wt[i], cost[i])));
    }
    sort(help.begin(), help.end());
    int i = n-1;
    double ub=0.0, lb=0.0;
    while(capacity!=0 and i>=0){
        if(capacity>=help[i].second.first){
            ub+=(double)help[i].second.second;
            lb+=(double)help[i].second.second;
            capacity-=help[i].second.first;
        }
        else{
            ub+=((double)help[i].second.second)*((double)capacity/(double)help[i].second.first);
            capacity = 0;
        }
        i--;
    }
    return make_pair(ub,lb);
}
int bfs(int n, int wt[]){
    
}
int main(){

    return 0;
}