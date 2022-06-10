#include<bits/stdc++.h>
using namespace std;

  


class sets{
    public:
    
    vector<int>parent;
    vector<int>rank;
    void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
    struct Edge{
     int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }}g;
    int n;
    long long int cost=0;
    vector<Edge> result;
    vector<Edge> edges;
   
    
   void spanning_tree(){
      sort(edges.begin(), edges.end());

     for (Edge e : edges) {
     if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }}
     
     }
    /* data */
};


int main(){
  int m;
   sets s;
  cin>>s.n>>m;
  s.parent.resize(s.n+1);
  s.rank.resize(s.n+1);
   int a,b,w;
   for(int i=1;i<=s.n;i++){s.make_set(i);}
  for(int i=0;i<m;i++){
      cin>>a>>b>>w;
      if(a>b) swap(a,b);
     s.g.u=a;s.g.v=b;s.g.weight=w;
     s.edges.push_back(s.g);
      
  }
  
  s.spanning_tree();
  cout<<s.cost;
   return 0;
}
