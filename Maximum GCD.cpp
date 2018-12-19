#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
using namespace std;
int gcd1(int p, int q) {
if (q > p) return(gcd1(q,p));
if (q == 0) return(p);
return( gcd1(q, p % q) );
}
int main() {
 int n;
 string x;
 cin>>n;
 int gdc;
 int min1=1;
 getline(cin,x);
 for(int i=0;i<n;i++){
   min1=0;
   getline(cin,x);
   stringstream iss(x);
   int number;
   vector<int> myNumbers;
   while ( iss >> number ){
      myNumbers.push_back( number );
   }
   for(int i=0;i<myNumbers.size();i++){
     for(int j=0;j<myNumbers.size();j++){
       if(j!=i){
         gdc=gcd1(myNumbers[i],myNumbers[j]);
         if(gdc>min1){
           min1=gdc;
         }
       }
     }
   }
   myNumbers.clear();
   cout<<min1<<endl;
 } 
 
}