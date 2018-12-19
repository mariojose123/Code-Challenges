#include <iostream>
#include <cstring>
#include <utility> 
#include<vector>
#include <queue>    
using namespace std;
vector<vector< pair<int,int> > > g;
int dijkstra(int a, int b,int n,vector<vector< pair<int,int> > > g)
{
 priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
 vector< int > d(n, -1);
 pair<int,int> p; int v,w;
 q.push( make_pair(0,a) );
 while (!q.empty())
 {
 p = q.top(); q.pop();
 v = p.second;
 w = p.first;
 if ( d[v] != -1 ) continue;
 if (v == b) return w;
 d[v] = w;

 for (int i = 0; i < g[v].size(); ++i)
if ( d[ g[v][i].first ] == -1 )
 {
 q.push( make_pair( w+g[v][i].second, g[v][i].first ) );
 }
 }
 return -1;
}
int main() {
  int x;
  int n,m,S,T;
  int v1,v2,w;
  cin>>x;
  for(int i=0;i<x;i++){
    cin>>n>>m>>S>>T;
    vector<vector< pair<int,int> > > g(n);
    for(int j=0;j<m;j++){
    cin>>v1>>v2>>w;
    g[v1].push_back(make_pair(v2, w));
    g[v2].push_back(make_pair(v1,w));
    }
    int dij = dijkstra(S,T,n,g);
    if(dij<0){
      cout<<"Case #"<<i+1<<": "<<"unreachable"<<endl;
    }
    else{
    cout<<"Case #"<<i+1<<": "<<dijkstra(S,T,n,g)<<endl;
    }
  }
}
