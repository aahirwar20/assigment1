#include<bits/stdc++.h>
using namespace std;

class fenwickTree{
    public:
int n;

vector<long long int>bit;
    fenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    fenwickTree(vector<int> a)
        : fenwickTree(a.size()) {
           
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    long long int sum(int idx) {
        long long int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx){
            bit[idx] += delta;}
    }
 
  int quiry_point(int k){
       
      return range_sum(k,k);
}


 long long int range_sum(int a,int b){
    return sum(b-1) - sum(a - 2);
 }

 void update_range(int a,int b,int u){
  for(int i=a;i<=n;i++){
      add(i-1,u);
  }
  for(int i=b;i<=n;i++){
       add(i, -u);
  }
   
 }
  

};

int main(){
   int n,q,arr;
   cin>>n>>q;
   
   vector<int> s;
   for(int i=0;i<n;i++){
    cin>>arr;
    s.push_back(arr);
   }
  fenwickTree f(s);
  
   int check;
  for(int i=0;i<q;i++){
  cin>>check;
  if(check==2){
    int k;
    cin>>k;
    cout<<f.quiry_point(k)<<'\n';}
  else {int a,b,u;
  cin>>a>>b>>u;
    f.update_range(a,b,u);}
  }
    return 0;
}