#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int no;  // No of vertices
 int s;  // source vertice
 vector<vector<int>>adj; // adjacency list representation
 vector<bool>used; //used value is true if vertice visited and false  if  visited not yet
 queue<int> q;  //list of same distace vertices
 
 vector<int>d,p;   //sortest distance source vector
 
 void bfs(){  //bfs fuction
    
      used.assign(no,false);
   p.resize(no);d.resize(no);
   q.push(s);  // assign source vertice
   used[s]=true;
   p[s]=-1;
  d[s]=0;
  
  
   while(!q.empty()){
       int v=q.front();
       q.pop();
       used[v]=true;
       
       for(int u:adj[v]){  //u is adjacent verteces of v
           if(!used[u]){
               used[u]=true;
               q.push(u);
               d[u]=d[v]+1;  
               p[u]=v;   //v is parent vertece of u
           }
       }
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
           adj[b].push_back(a);  // make adjacency list
       }
       int g;
   cin>>g;
   s=g;
  
  
    
    bfs();  // call bfs function for  find distace vector from source vertice
    for(int i=0;i<d.size();i++){cout<<d[i]<<" ";}   // print distance vector
    
  return 0;
}
   