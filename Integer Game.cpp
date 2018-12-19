#include <iostream>
#include <string>
using namespace std;
int main() {
  int n; 
  string num;
  cin>>n;
  int i=1;
  while(n--){
    char winner;
    cin>>num;
    bool passa=false;
    int sum=0;
    int passada=0;
    for(int j=0;j<num.size();j++){
      sum+=num[j]-'0';
    }
    for(int j=0;j<num.size();j++){
      if ((sum-(num[j] - '0')) % 3 == 0){
         passa=true; 
      }
      if ((num[j] - '0') % 3 == 0){
          passada++;
      }
    }
    if(num.size()==1){
      winner='S';
    }
    else{
    if(sum%3==0){
      if(passada%2==1){
        winner='S';
      }
      else{
        winner='T';
      }
    }
    else if(passa){
       if(passada%2==0){
        winner='S';
      }
      else{
        winner='T';
      }
    }
    else{
      winner='T';
    } 
    }
    cout<<"Case "<<i<<": "<<winner<<endl;
    i++;
  }
}