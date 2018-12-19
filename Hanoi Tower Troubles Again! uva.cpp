#include <iostream>
#include <stdio.h>  
#include <math.h>
using namespace std;
bool isperfectsquare(double number){
  double i=  sqrt((double)number);
  return(i-floor((i))==0);
}
int main() {
  int peg[50]={0};
  int max[50]={0};
  double i=2;
  max[0]=1;
  peg[0]=1;
  int j=0;
  int maxn=0;
  while(j!=50){
    for(int z=0;z<=50;z++){
    if(z==50){
         j=z;
         break;
       }
    if(isperfectsquare(i+peg[z])||peg[z]==0){
       if(peg[z]==0){
        max[z]=i;
        maxn=z;
        peg[z]=i;
        i++;
        break;
       }
      peg[z]=i;
      max[maxn]=i;
      i++;
      break;
    }
    }
  }
  int tc;
  cin>>tc;
  int n;
  for(int i=0;i<tc;i++){
    cin>>n;
    cout<<max[n-1]<<endl;
  } 
return(0);
}