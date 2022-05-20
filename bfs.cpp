#include<bits/stdc++.h>
using namespace std;
queue<int>q;
void bfs(int i, vector<vector<int>> a, vector<int> visited){
    int u;
    q.push(i);
    visited[i] =1;
    cout<<"BFS traversal:- \n";
    cout<<i<<" ";
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v=1; v<visited.size(); v++){
            if(a[u][v] == 1 and visited[v] == 0){
                q.push(v);
                visited[v]=1;
                cout<<v<<" ";
            }
        }
    }
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
    vector<int>visited(8,0);
    bfs(1,a,visited);
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
    
}