#include<bits/stdc++.h>
using namespace std;

struct Edge {         // structure of weighted edge
    int a, b, cost;
};
int n, m;
vector<vector<int>>d;
const int INF = INT_MAX;

void solve(){   
    for (int k = 1; k <= n; ++k) {  // Floyd-Warshalls Algorithm
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}

}

void update(int a,int b,int cost){   // update all pair distance array 
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][a] < INF && d[b][j] < INF)
                d[i][j] = min(d[i][j], d[i][a] + d[b][j]+cost); 
        }
    }
}

int main(){
   cin>>n>>m;  // print no of edges ,vertex
   Edge e;
   d.resize(n+1);
   for(int i=0;i<=n;i++){d[i].assign(n+1,INF);}
   for(int i=0;i<=n;i++)d[i][i]=0;
   for(int i=0;i<m;i++){  
     // print the information about edges 
    cin>>e.a>>e.b>>e.cost;     // vertex index 1<=index<=n 
      d[e.a][e.b]=e.cost;
   }
   solve();   //call for find all pair distance array 
   cin>>e.a>>e.b>>e.cost;  // print update edge
  
  update(e.a,e.b,e.cost);   //call for update all pair distance array after update edge
    return 0;
}