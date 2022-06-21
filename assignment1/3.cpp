#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int no; // No of vertices
 vector<vector<int>>adj; // adjacency list representation
 vector<int>visit; //visit value 1 when visiting vertices and 0 not visited and 2 when exit the vertices
 int s; // source verteces 
 vector<vector<int>>comp; //  componects data
 vector<int>p; //parent of vertices

 void dfs(int v){  // dfs function
     comp[s-1].push_back(v);
    visit[v]=1;
    for(int u:adj[v]){
        if(u==p[v])continue; //for skip condition for parent of verteces
        if(!visit[u]){    
        p[u]=v;
        dfs(u);}  //recurrsion function
        
    }
    visit[v]=2;
   
 }
 
 void find_cpm(){   // finding connecting componants
      p.assign(no,-1);
      s=0;
     
     for(int i=0;i<no;i++){    
       
         if(visit[i]==0){   // call unvisited  vertices
             s++;
             comp.resize(s);
             dfs(i);     // call of dfs function 
         }
     }
         
         
     
    
 }
 
 
int main(){
    int n,m,s=0;
    char h;
    cin>>n>>m;   // no of verteces and no edges
   int a,b;
   adj.resize(n);
   
   visit.assign(n,0);
   p.resize(n);
  
  
       for(int j=0;j<m;j++){
           cin>>a>>b;  // input vertices of edges
           adj[a].push_back(b);  // make adjacency list 
           adj[b].push_back(a);
       }
   
   no=n;
    
    find_cpm();
    cout<<comp.size()<<'\n';  // prints no of connecting components
   for(int i=0;i<comp.size();i++){  //list of vertices of connecting components
       cout<<i+1<<": ";
       for(int j:comp[i]){
           cout<<j<<' ';
       }
       cout<<'\n';
   }
  return 0;
}
   