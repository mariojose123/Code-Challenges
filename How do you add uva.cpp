#include <iostream>
#include <cstring>
using namespace std;
int main() {
  long long  A[101][101];
  memset(A,0,sizeof(A));
  for(int i=0;i<=100;i++){
    A[i][1]=1;
  }
  for(int i=2;i<=100;i++){
    for(int j=0;j<=100;j++){
     for(int z=j;z>=0;z--){
       A[j][i]=(A[j][i] + A[j-z][i-1]) % 1000000ll;
     }
    }
  }
  int k,n;
  while(cin>>n>>k&&n!=0&&k!=0){
      printf("%lld\n",A[n][k]);
  }
}