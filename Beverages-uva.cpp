#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef vector<int> vi;
vector<vi> adjMat;
map<string,int> Nmap;
map<int,string> Rmap; 
vi degree;
int V,E;
string x;
string y;
int main() {
  int count=1;
  while(scanf("%i",&V)!=EOF){
    degree.assign(V,0);
    adjMat.assign(V,vi());
    Nmap.clear();
    Rmap.clear();
    for(int i=0;i<V;i++){
      cin>>x;
      Nmap[x]=i;
      Rmap[i]=x;
    }
    priority_queue<int, vector<int>, greater<int> > q;
    cin>>E;
    for(int i=0;i<E;i++){
    cin>>x>>y;
    adjMat[Nmap[x]].push_back(Nmap[y]);
    degree[Nmap[y]]++;
    }
    int p;
    cout<<"Case #"<<count<<": Dilbert should drink beverages in this order:";
    for (int i = 0; i <V; ++i){
        if (degree[i] == 0) q.push(i); 
    }
    while(!q.empty()){
      p= q.top();q.pop();
      cout<<" "<<Rmap[p];
      for(int i=0;i<adjMat[p].size();i++){
        degree[adjMat[p][i]]--;
        if(degree[adjMat[p][i]]==0){
          q.push(adjMat[p][i]);
        }
      }
    }
    count++;
    cout<<".";
    cout<<endl;
    cout<<endl;
  }
  return 0;
}