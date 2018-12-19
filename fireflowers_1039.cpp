#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
bool contain(double x1,double y1,double c1,double x2,double y2,double c2){
double d = sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
if(c1 >= ( d + c2 )){
   return true;
}
else{
   return false;
}
}
int main() {
  double x1,y1,c1,x2,y2,c2;
  string line;
while (scanf("%lf %lf %lf %lf %lf %lf",&c1,&x1,&y1,&c2,&x2,&y2)!=EOF)
{

    if(contain(x1,y1,c1,x2,y2,c2)){
      cout<<"RICO"<<endl;
    }
    else{
      cout<<"MORTO"<<endl;
    }
}
return 0;
}