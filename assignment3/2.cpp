#include<bits/stdc++.h>
using namespace std;

  

class sets{
    public:
     struct Edge {
    int u, v;}g;
    int n;
    vector<Edge> edges;

    void cut(int a,int b){
        
        if(a>b) swap(a,b);
        
        
        for(auto e=edges.begin();e<=edges.end();e++){
            if(e->u==a&&e->v==b){
             edges.erase(e);
            }
        }
      
       
    }

     bool ask(int a,int b){
        vector<int> tree_id(n+1);
     for (int i = 1; i < n+1; i++)
    tree_id[i] = i;

     

    for (Edge e : edges) {
    if (tree_id[e.u] != tree_id[e.v]) {
        int old_id = tree_id[e.u], new_id = tree_id[e.v];
        for (int i = 1; i < n+1; i++) {
            if (tree_id[i] == old_id)
                tree_id[i] = new_id;
        }
    }
     }
      if(tree_id[a]==tree_id[b]){
          return true;}
          else{
        return false;}
      
     }
    /* data */
};


int main(){
  int m,q;
   sets s;
  cin>>s.n>>m>>q;
  
   int a,b;
   
  for(int i=0;i<m;i++){
      cin>>a>>b;
      if(a>b) swap(a,b);
     s.g.u=a;s.g.v=b;
     s.edges.push_back(s.g);
      
  }
  
  string sr;
  int u,v;
  
  for(int i=0;i<q;i++){
      cin>>sr;
      cin>>u>>v;
      if(sr.compare("cut")==0){
          s.cut(u,v);
         
      }
      else if(sr.compare("ask")==0){
          if(s.ask(u,v)){
          cout<<"YES";}
          else{cout<<"NO";}
          cout<<'\n';
      }

  }

  return 0;
}
