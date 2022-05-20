#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[][4] = { { 0, 3, 9, 2 },
                       { 2, 0, 6, 11 },
                       { 8, 5, 0, 3 },
                       { 4, 10, 7, 0 } };
    int origin = 0;
    vector<int>vertex;
    for(int i =0; i<4; i++){
        if(i!=origin){
            vertex.push_back(i);
        }
    }
    // int ans = 0;
    pair<int,string>ans;
    
    ans.first = INT16_MAX;
    do{
        int minm_cost = 0;
        int k = origin;
        for(int i =0; i<vertex.size(); i++){
            minm_cost += a[k][vertex[i]];
            k = vertex[i];
        }
        minm_cost += a[k][origin];
        if(ans.first>minm_cost){
            ans.first = minm_cost;
            ans.second = to_string(origin+1);
            for(int i=0; i<vertex.size(); i++){
                ans.second += "->"+to_string(vertex[i]+1);
            }
            ans.second += "->"+to_string(origin+1);
        }
    }while(next_permutation(vertex.begin(),vertex.end()));
    cout<<ans.first<<" "<<ans.second;
}