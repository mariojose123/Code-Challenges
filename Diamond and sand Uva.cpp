#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  int dim=0;
  string s;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    if(s==""){
      break;
    }
    int found=s.find("<");
    while(found!=string::npos){
      int found2=s.find(">",found);
      if(found2!=string::npos){
        s.erase(found2,1);
        s.erase(found,1);
        dim++;
      }
      else{
        break;
      }
      found=s.find("<");
    }
    cout<<dim<<endl;
    dim=0;
}
return 0;
}