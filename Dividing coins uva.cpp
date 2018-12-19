#include <iostream>
#include <cstring>
#include <algorithm> 
#include <string>
int max(int a, int b) { return (a > b)? a : b; }
using namespace std;
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
int main() {
  int val[1000];
  int cost[500*100];
  int n;
  int sum;
  int coin;
  cin>>n;
  for(int j=0;j<n;j++){
  sum=0;
  cin>>coin;
  memset(val,0,1000);
  memset(cost,0,500*100);
  for(int i=0;i<coin;i++){
    cin>>val[i];
    sum+=val[i];
  }
    
    int r= knapSack(sum/2,val,val,coin);
    cout<<sum-2*r<<endl;
  }
  }