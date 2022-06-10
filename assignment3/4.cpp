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
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
 
 void update_point(int k,int u){
      long long int d=range_sum(k,k);
    add(k-1,u-d);
 }

 long long int range_sum(int a,int b){
  return sum(b-1) - sum(a - 2);
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
  
   int check,a,b;
  for(int i=0;i<q;i++){
  cin>>check>>a>>b;
  if(check==1){f.update_point(a,b);}
  else {cout<<f.range_sum(a,b)<<'\n';}
  }
    return 0;
}