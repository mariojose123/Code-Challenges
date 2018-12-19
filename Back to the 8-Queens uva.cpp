#include <iostream>
#include <cmath>  
using namespace std;
int min1=1000;
int p[8];
int row[8];
bool place(int r,int c){
  for(int prev=0;prev<c;prev++){
    if(row[prev]==r||(abs(row[prev] - r) == abs(prev-c))){
      return false;
    }
  }
  return true;
}
void backtrack(int c){
  if(c==8){
    int total=0;
    for(int i=0;i<8;i++){
      if(abs(row[i]-p[i])!=0){
        total++;
      }
    }
    if(total<min1){
      min1=total;
    }
  }
  for(int r=0;r<8;r++){
    if(place(r,c)){
    row[c]=r;backtrack(c+1);
    }
  }
}
int main() {
  int counter=0;
  while(cin>>p[0]){
    min1=1000;
    p[0]--;
    for(int i=1;i<8;i++){
      cin>>p[i];
      p[i]--;
    }
    counter++;
    backtrack(0);
    cout<<"Case "<<counter<<":"<<" "<<min1<<endl;
  }
}