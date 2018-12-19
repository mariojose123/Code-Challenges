#include <iostream>
#include <cstring>
using namespace std;
int main() {
  
  int n=1000000;
  bool A[n];
  A[0]=false;
  A[1]=false;
  for(int i=2;i<=n;i++){
    A[i]=true;
  }
  for(int i=2;i*i<=n;i++){
   if( A[i] == true){
     for(int j = i*2;j<=n;j+=i){
       A[j] = false;
     }
   } 
  }
  A[2]=false;
  int v;
  cin>>v;
  while(v!=0){
  int min1=1000000;
  for(int i=1;i<v;i++){
    if(A[i]&&A[v-i]){
       cout<<v<<" = "<<i<<" + "<<v-i<<endl;
       break;
    }
  }
  cin>>v;
  }
  return 0;
}