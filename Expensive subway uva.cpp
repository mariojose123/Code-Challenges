#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
using namespace std;
typedef vector<pair<int,int>> vi;
int adjMat[401][401];
map<string,int> Nmap;
int V,E;
int x;
int y;
int z;
string name;
string name2;
bitset<402> bites;

int main() {
  cin>>x>>y;
  while((x||y)){
    for(int i=0;i<x;i++){
      for(int j=0;j<x;j++){
        adjMat[i][j]=-1;
      }
    }
    Nmap.clear();
    bites.reset();
    for(int i=0;i<x;i++){
      cin>>name;
      Nmap[name]=i;
      bites[i]=1;
    }
    for(int i=0;i<y;i++){
      cin>>name>>name2>>z;
      if(adjMat[Nmap[name]][Nmap[name2]]<0){
        adjMat[Nmap[name]][Nmap[name2]]=z;
        adjMat[Nmap[name2]][Nmap[name]]=z;
      }
      else if(adjMat[Nmap[name]][Nmap[name2]]>z){
        adjMat[Nmap[name]][Nmap[name2]]=z;
        adjMat[Nmap[name2]][Nmap[name]]=z;
      }
    }
    cin>>name;
    int minw=INT_MAX;
    long long int min=0;
    int now=Nmap[name];
    int next;
    bool impossivel = false;
    bites[now]=0;
    while(bites.any()){
        minw=INT_MAX;
      for(int i=0;i<x;i++){
        if(bites[i]==0){
        for(int j=0;j<x;j++){
          if(adjMat[i][j]<=minw&&adjMat[i][j]>=0){
          if(bites[j]!=0){
            minw=adjMat[i][j];
            next=j;
          }
          }
      }
    }
    }
      
    if(bites[next]==0){
           impossivel=true;
           bites.reset();
    }
     if(!impossivel){
      min+=minw;
      bites[next]=0;
     }
  }
  if(!impossivel){
  cout<<min<<endl;
  }
  else{
    cout<<"Impossible"<<endl;
  }
  cin>>x>>y;
  }
  return 0;  
 
}