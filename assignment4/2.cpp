#include<bits/stdc++.h>
using namespace std;

class dijkstra{    // class for finding minimum cost with some other details
    public:
     const int inf=INT_MAX;     
     vector<vector<pair<int,int>>> adj;   //adjacent vertex list or detail about any edges 
     int n;            // no of vertex
     int min_cost;     // minimum cost 
     int max_r;        // find max vertex edges route with minimum cost
     int min_r;         // find min vertex edges route with minimum cost
     int min_routs;     // no of routes  with minimum cost


     void min_dijkstra(int s,vector<int> &d,vector<int> &p,vector<int> &m,vector<int> &min,vector<vector<int>> &pr){
        d.assign(n+1,inf);
         p.assign(n+1,-1);
         m.assign(n+1,0);
          min.assign(n+1,0);
        pr.resize(n+1);
       vector<bool> u(n+1,false);
        d[1]=0;
        for(int i=1;i<=n;i++){    //Dijkstra algorithms 
            int v= -1;

            for(int j=1;j<=n;j++)
             if(!u[j]&&(v==-1||d[j]<d[v]))
             v=j;

            if(d[v]==inf)
            break;
            u[v]=true;
            for(auto e:adj[v]){
              int to=e.first;
              int len=e.second;
              if(d[v]+len<d[to]){
                  m[to]=m[v]+1;
                  min[to]=min[v]+1;
                d[to]=d[v]+len;
                p[to]=v;
                
              }
              else if(d[v]+len==d[to]){
                   if(m[v]+1>m[to]){m[to]=m[v]+1;}    // find max vertex edges route with minimum cost
                   if(min[v]+1<min[to]){min[to]=min[v]+1;}  // find min vertex edges route with minimum cost
                   
                     pr[to].push_back(v);
               
              }
             
            }
        }

     }
     

     void min_prize(int s,int k){   // funtion find the mininum cost with how many routes detail
        vector<int>d;
        vector<int>p;
        vector<int>max;
        vector<int>min;
       
        
        vector<vector<int>>pr;
        min_dijkstra(s,d,p,max,min,pr);
        min_cost= d[k];
       
        for(int i=0;i<=n;i++){pr[i].push_back(p[i]);}     
        int mr=1;
        for(int v = k; v != s; v = p[v]){       // find no of routes with minimum costs
           
           mr*=pr[v].size();
          
        }
        min_routs=mr;
        min_r=min[k];
        max_r=max[k];
     }
};

int main(){
    int n,m;
    dijkstra a;
    cin>>n>>m;
    a.n=n;
    a.adj.resize(n+1);
    int st;
    pair<int,int>pr;
    for(int i=0;i<m;i++){      // fill detail about edges in adjacent metrix
        cin>>st>>pr.first>>pr.second;
        a.adj[st].push_back(pr);
    }
   a.min_prize(1,n);
   cout<<a.min_cost<<' ';    // print output
   cout<<a.min_routs<<' ';
   cout<<a.min_r<<' ';
   cout<<a.max_r<<' ';
    return 0;
}