#include<bits/stdc++.h>
using namespace std;
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> srt;
vector<int> c;
bool check =true;

void dfs(int v) {
    visited[v] = true;
    c[v]=1;
    for (int u : adj[v]) {
        if(c[u]==1){check=false;}
        if (!visited[u])
            dfs(u);
    }
    srt.push_back(v);
    c[v]=2;
}

void sort_vector() {
    visited.assign(n, false);
    srt.clear();
    
    c.assign(n,0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(srt.begin(), srt.end());
    if(!check){cout<<"IMPOSSIBLE";}
    else{
    for(int i=0;i<srt.size();i++){
        cout<<++srt[i]<<'\n';
    }}
}

int main(){
    int no,m;
    cin>>no>>m;
    int a,b;
    n=no;
    adj.resize(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    sort_vector();
    return 0;
}