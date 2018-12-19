#include <iostream>
#include <cstring>
using namespace std;
int main() {
  unsigned long long number[30001];
  memset(number,0,sizeof(long long)*30001);
  number[0]=1;
  int a[5]={1,5,10,25,50};
  int n;
  for(int j=0;j<5;j++){
      for(int i=1;i<30001;i++){
        if(i-a[j]>=0){
          number[i]+=number[i-a[j]];
        }
      }
  }
  while(cin >>n){
    if(number[n]==1){
      printf("There is only 1 way to produce %i cents change.\n",n);
    }
    else
    {
    printf("There are %llu ways to produce %i cents change.\n",number[n],n);
    }
  }
  return 0;
}