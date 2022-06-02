#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component,roots;
int k;



void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
void scc(){
    k=0;
    used.assign(n, false);
    roots.resize(n);
      
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
    if (!used[v]) {
        dfs2(v);
        k++;
        
        for (auto u : component) roots[u] = k;
        component.clear();
    }




}

int main(){
    int no,m;
    cin>>no>>m;
    int a,b;
    n=no;
    adj.resize(n);
    adj_rev.resize(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
         adj_rev[b-1].push_back(a-1);
    }
    scc();
    cout<<k<<'\n';
    for(int u:roots){
        cout<<u<<' ';
    }
    
return 0;
}