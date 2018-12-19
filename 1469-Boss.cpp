#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int G,M,L;
using namespace std;
const int inf = 1000;
vector<int>  age;
int dfs(vector<vector<int>> &g, vector<int> &vi, vector<int> &age,
        int node, int col) {

  int ans = inf;
  vi[node] = 1;
  for (auto &to : g[node]) {
    if (vi[to] < 1)
      ans = min(min(ans, age[to]), dfs(g, vi, age, to, col));
  }
  return ans;
}
int main() {
  int m,n,q;
  while(cin>>n>>m>>q){
    vector<vector<int>> g(n);
    vector<int> age(n);
    vector<int> index(n);
    for(int i=0;i<n;i++){
      cin>>age[i];
    }
    int u,v;
    for(int i=0;i<m;i++){
      cin>>u>>v;
      v--;
      u--;
      g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
      index[i]=i;
    }
    string op;
    for(int i=0;i<q;i++){
      vector<int> vi(n, -1);
      cin>>op;
      int a,b;
      if(op=="T"){
        cin>>a>>b;
        a--;b--;
        swap(age[index[a]], age[index[b]]);
        swap(index[a], index[b]);
      }
      else{
        cin>>a;
        a--;
        if(!g[index[a]].size()){
          cout << "*" << endl;
        }
        else{
          cout << dfs(g, vi, age, index[u], i) << endl;
        }
      }
    }
  }
}