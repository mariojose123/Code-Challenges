#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
  string x;
  string y;
  int c[1001][1001];
  while(getline(cin,x)){
    getline(cin,y);
    int n=x.length();
    int m=y.length();
    memset(c, 0, sizeof(c[0][0]) * 1001 * 1001);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(x[i-1]==y[j-1]){
          c[i][j]=c[i-1][j-1] + 1;
        }
        else{
          c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
      }
    }
    cout<< c[n][m]<<endl;
  }
  return 0;
}