#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int no; // No of vertices
 vector<vector<int>>adj; // adjacency list representation
 vector<int>visit; //visit value 1 when visiting vertices and 0 not visited and 2 when exit the vertices
 int start_point; // starting point of cycle
 int end_point;  // end point of cycle
 vector<int>p;
 vector<int>cycle;
 bool dfs(int v,int par){  // dfs function for checking cycle
    visit[v]=1;
    for(int u:adj[v]){
        if(u==par)continue;
        if(visit[u]){
            start_point=u; // assign starting point
            end_point=v; // assign end point
            
            return true;
        }
        p[u]=v;
        if(dfs(u,p[u])){return true;}  // recurrsion conditon
        
    }
    
    visit[v]=2;
    return false; 
 }
 
 void find_cycle(){ // function find cycle
      p.assign(no,-1);
      start_point=-1;
      end_point=-1;
       
     for(int i=0;i<no;i++){
       
         if(!visit[i]&&dfs(i,p[i])){break;} // call dfs function and  if found a cycle then go out of loop 
     }
         if(start_point==-1){
             cout<<"IMPOSSIBLE";
         }
         else{
             for(int v=end_point;v!=start_point;v=p[v])cycle.push_back(v);
             cycle.push_back(start_point);
             cout<<cycle.size()<<"\n";  // prints no of elements in cycle 
             reverse(cycle.begin(),cycle.end());
             
             for(int v:cycle){   
                 cout<<v<<' ';   // prints vertices in cycle
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
           cin>>a>>b;// input vertices of edges
           adj[a].push_back(b);  // make adjacency list 
           adj[b].push_back(a);
       }
   
   no=n;
    
    find_cycle(); // call find cycles
   
    return 0;}