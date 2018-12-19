#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
 int V, AdjMatrix[200][200];
 int cases=0;
 int x,y;
 while(cin>>x>>y&&x&&y){
 double contador=0;
 double t=0;
 cases+=1;
 for (int i = 0; i < 200; i++) {
 for (int j = 0; j < 200; j++){
 AdjMatrix[i][j] = numeric_limits<int>::max();
 AdjMatrix[j][i] = numeric_limits<int>::max();
 }
 AdjMatrix[i][i] = 0;
 }
 AdjMatrix[x][y] = 1;
 while(cin>>x>>y&&x&&y){
 AdjMatrix[x][y] = 1; // directed graph
 }
 for (int k = 0; k < 200; k++){ // common error: remember that loop order is k->i->j
 for (int i = 0; i < 200; i++){
 for (int j = 0; j < 200; j++){
 if(AdjMatrix[i][k]+AdjMatrix[k][j]<=0){
  AdjMatrix[i][j] = min(AdjMatrix[i][j], numeric_limits<int>::max());

 }
 else{
 AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
 }
 }}}

 for (int i = 0; i < 200; i++){
 for (int j = 0; j < 200; j++){
 if( AdjMatrix[i][j]>0&&AdjMatrix[i][j]!=numeric_limits<int>::max()){
    contador+=AdjMatrix[i][j];
    t++;
 }
 }
 }
 cout<<"Case "<<cases<<": average length between pages = "<<fixed<<setprecision(3)<<contador/t<<" clicks"<<endl;
 }

}