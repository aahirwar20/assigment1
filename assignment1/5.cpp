#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int no; // No of vertices
 int s;
 vector<vector<int>>adj;  // adjacency list representation
 vector<bool>used;  //used value is true if vertice visited and false  if  visited not yet  
vector<int> tin, low; // low value of sub tree
int timer;


void IS_BRIDGE(int v,int to){  // deteles the bridges 
    for(int i=0;i<adj[v].size();i++){ // deleting adjacent of v
        if(adj[v][i]==to){adj[v].erase(adj[v].begin()+i);}}
    for(int i=0;i<adj[to].size();i++){ // deleting adjacent of to
        if(adj[to][i]==v){adj[to].erase(adj[to].begin()+i);}}
    
 
 }
void dfs(int v, int p = -1) { // function  dfs
    used[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue; //for skip condition for parent of verteces
        if (used[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);  //assigne low value
            if (low[to] > tin[v])
                IS_BRIDGE(v, to); // call function  for deleting the functions
        }
    }
}
 
 
void find_bridges(){   // function for find bridge
    timer = 0;
    used.assign(no, false);
    tin.assign(no, -1);
    low.assign(no, -1);
    for (int i = 0; i < no; ++i) {
        if (!used[i])
            dfs(i);  // call dfs 
    }
}


int main(){
    int n,m;
    char h;
    cin>>n>>m;  // no of verteces and no edges
   int a,b;
   adj.resize(n);
    no=n;
    for(int j=0;j<m;j++){
           cin>>a>>b;// input vertices of edges
           adj[a].push_back(b);  // make adjacency list 
           adj[b].push_back(a);
       }
      find_bridges();      // call function for find bridges and delets the bridges
     for(int i=0;i<no;i++){    //print adjacancy list after deleting the bridge
        cout<<i<<' ';
        for(int j:adj[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
  return 0;
}
   