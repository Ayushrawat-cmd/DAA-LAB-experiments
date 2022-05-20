#include<bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int>> a){
    static vector<int>visited(8,0);
    if(visited[u] == 0){
        cout<<u<<" ";
        visited[u] =1;
        for(int v=1; v<visited.size(); v++){
            if(a[u][v] == 1 and visited[v] == 0){
                dfs(v,a);
            }
        }
    }
    return ;
}

int main(){
    clock_t start,end;
    start = clock();
    vector<vector<int>>a = {
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0},
        {0,1,0,1,0,0,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,0,1,0,1,0,0},
        {0,0,0,1,1,0,1,1},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0}
    };
    cout<<"DFS traversal:- \n";
    dfs(1,a);
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
    
}