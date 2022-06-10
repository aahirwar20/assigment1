#include<bits/stdc++.h>
using namespace std;



class sets{
    public:
     vector<int> parent;
     vector<int> Rank;
    void make_set(int v){
      parent[v]=v;
     Rank[v]=0;}

    int find_set(int a){
     if(parent[a]==a){
        return a;}
     return parent[a]=find_set(parent[a]);}

    void union_sets(int a,int b){ 
     a=find_set(a);
      b=find_set(b);
      
      if(a!=b){
       if(Rank[a]<Rank[b])
           swap(a,b);
           parent[b]=a;
           if(Rank[a]==Rank[b]){
               Rank[a]++;
           }
       
   }
    /* data */}
};


int main(){
  int n,m;
  cin>>n>>m;
   sets s;
  s.Rank.resize(n+1);
  s.parent.resize(n+1);
  for(int i=1;i<=n;i++){
    s.make_set(i);
  }
  string sr;
  int u,v;
  
  for(int i=0;i<m;i++){
      cin>>sr;
      cin>>u>>v;
      if(sr.compare("union")==0){
          s.union_sets(u,v);
         
      }
      else if(sr.compare("get")==0){
          if(s.find_set(u)==s.find_set(v)){
              cout<<"YES";
          }
          else{cout<<"NO";}
          cout<<'\n';
      }

  }

  return 0;
}
