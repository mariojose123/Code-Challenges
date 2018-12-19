#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  vector<int> pares;
  vector<int> impares;
  int valor;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>valor;
    if(valor%2==0){
      pares.push_back(valor);
    }
    else{
      impares.push_back(valor);
    }
  }
  sort(pares.begin(),pares.end());
  sort(impares.begin(),impares.end(),std::greater<int>());
  for(int i =0;i<pares.size();i++){
    cout<<pares[i]<<endl;
  }
  for(int i =0;i<impares.size();i++){
    cout<<impares[i]<<endl;
  }
  return 0;
}