#include<bits/stdc++.h>
using namespace std;
int main(){
    clock_t start,end;
    start = clock();
    int a[9][9] = {
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
        {INT_MAX,INT_MAX,25,INT_MAX,INT_MAX,INT_MAX, 5,INT_MAX  },
        {INT_MAX,25,INT_MAX,12,INT_MAX,INT_MAX,INT_MAX,10  },
        {INT_MAX,INT_MAX,12,INT_MAX,8,INT_MAX,INT_MAX,INT_MAX  },
        {INT_MAX,INT_MAX,INT_MAX,8,INT_MAX,16,INT_MAX,14  },
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,16,INT_MAX, 20,18  },
        {INT_MAX,5,INT_MAX,INT_MAX,INT_MAX, 20,INT_MAX, INT_MAX  },
        {INT_MAX,INT_MAX,10,14,18,INT_MAX,INT_MAX,INT_MAX  }
    };
    int t[2][7],ans=0;
    int near[8] ;
    int min = INT_MAX,u,v;
    for(int i =1;i<=7; i++){
        for(int j =i; j<=7; j++){
            if(a[i][j]<min){
                min = a[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u, t[1][0] = v;
    ans+=a[u][v];
    near[u] = 0, near[v] = 0;
    for(int i =1; i<=7; i++){
        if(a[i][u]<a[i][v] and i!=u and i!=v){
            near[i] = u;
        }
        else if(a[i][u]>=a[i][v]and i!=u and i!=v){
            near[i] = v;
        }
    }
    for(int i=1; i<6; i++){
        min = INT_MAX;
        int k;
        for(int j=1; j<=7; j++){
            if(a[j][near[j]]<min and near[j]!=0){
                min = a[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;t[1][i] = near[k];
        ans+=a[k][near[k]];
        near[k] = 0;
        for(int j=1; j<=7; j++){
            if(a[j][k]<a[j][near[j]] and near[j]!=0){
                near[j] = k;
            }
        }
    }
    cout<<"The traversed paths for given graph will be:-\n";
    for(int i=0; i<6; i++){
        cout<<t[0][i]<<"->"<<t[1][i]<<endl;
    }
    cout<<"Minmum cost for traversing all the nodes:- "<<ans;
    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<endl<<"Time taken:- "<<fixed<<time_taken<<setprecision(5);
    return 0;
}