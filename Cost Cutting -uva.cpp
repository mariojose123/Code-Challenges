#include <iostream>
#include <iostream>   
#include <algorithm> 
using namespace std;
int main() {
  int n;
  int salario[3];
  cin >> n;
  for(int i=0;i<n;i++){
    cin>>salario[0]>>salario[1]>>salario[2];
    for(int j=0;j<3;j++)
    {
    if(salario[j]==*max_element(salario,salario+3)){
      
    }
    else if(salario[j]==*min_element(salario,salario+3)){

    }
    else{
      cout<<"Case "<<i+1<<": "<<salario[j]<<endl;
    }
  }
}
return(0);
}