#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int no; // No of vertices
 vector<vector<int>>adj;  // adjacency list representation
 vector<int>visit;   //visit value 1 when visiting vertices and 0 not visited and 2 when exit the vertices
 vector<int>tin;     // in time
 vector<int>tout;    // out time
 int timer;       //time
 vector<int>p;     // parent of vertices

 void dfs(int v){        // DFS function
    visit[v]=1;
   tin[v]=timer++;
    for(int u:adj[v]){
        if(u==p[v])continue;
        if(!visit[u]){
        p[u]=v;
        dfs(u);}      //recurrtion function
        
    }
    tout[v]=timer++;
    visit[v]=2;
   
 }
 
 void find_time(){        // function for find in time and exit time of vertice
      p.assign(no,-1);
      timer=0;
      tin.resize(no);
      tout.resize(no);
     for(int i=0;i<no;i++){
       
         if(visit[i]==0){     //for connected graph
             dfs(i);      // call dfs function
         }
     }
         
         
     
    
 }
 
 
int main(){
    int n,m,s=0;
    char h;
    cin>>n>>m;      // no of verteces and no edges
   int a,b;
   adj.resize(n);
   
   visit.assign(n,0);
   p.resize(n);
  
  
       for(int j=0;j<m;j++){   
           cin>>a>>b;          // input vertices of edges
           adj[a].push_back(b);  // make adjacency list 
           adj[b].push_back(a);
       }
   
   no=n;
    
    find_time();   // call function find in and exit time of vertices

   for(int i:tin)cout<<i<<' ';      //  print in time of verteces
   cout<<'\n';
   for(int i:tout)cout<<i<<' ';    //  print exit time of verteces
    return 0;}