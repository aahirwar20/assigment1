#include<bits/stdc++.h>
using namespace std;

struct Edge {         // structure of weighted edge
    int a, b, cost;
};

int n, m;
vector<Edge> edges;    // edges 
const int INF = INT_MAX;

void Bellman_fords()
{
    vector<long long int> d(n+1);  // distance vector 
    vector<int> p(n+1, -1);
    int t=-1;
    for (int i = 1; i <= n; ++i) {
        t = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {      // replace with sortes distance
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                t = e.b;
            }
        }
    }

    if (t == -1) {
        cout << "NO";   // print NO if no negative cycle in graph 
    } else {
        for (int i = 1; i <= n; ++i)    // print YES in negative cycle in graph and order of negative cycle
           t = p[t];

        vector<int> cycle;
        for (int v = t;; v = p[v]) {
            cycle.push_back(v);
            if (v == t && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main(){
   cin>>n>>m;
   Edge e;
   for(int i=0;i<m;i++){   // print the information about edges 
    cin>>e.a>>e.b>>e.cost;
    edges.push_back(e);
   }
  Bellman_fords();   // call of function for find negative cycle 

    return 0;
}