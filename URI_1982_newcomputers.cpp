#include <iostream>
#include <vector>
#include <cmath>
#include <cerrno>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
struct point {
 int x, y;
 point() { x = y = 0; }
 point(int _x, int _y) : x(_x),
y(_y) {}
int operator^(point p2) {return x*p2.y - y*p2.x;};
int operator*(point p2) {return x*p2.x + y*p2.y;};
};
point pivot;
point p0;
bool angle(point p1, point p2){
    p0=pivot;
    p1.x=p1.x-p0.x; p2.x=p2.x-p0.x;
    p1.y=p1.y-p0.y; p2.y=p2.y-p0.y;
    if(p1.y==0&&p1.x>0) return true; //angle of p1 is 0, thus p2>p1
    if(p2.y==0&&p2.x>0) return false; //angle of p2 is 0 , thus p1>p2
    if(p1.y>0&&p2.y<0) return true; //p1 is between 0 and 180, p2 between 180 and 360
    if(p1.y<0&&p2.y>0) return false;
    if((p1^p2)==0&&p1*p2>0) return p1*p1<p2*p2;
    return (p1^p2)>0; //return true if p1 is clockwise from p2
}
struct vec { double x, y; // representação
 vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) { // converter dois pontos para um vetor a->b
 return vec(b.x - a.x, b.y - a.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }


double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
 return cross(toVec(p, q), toVec(p, r)) > 0; }

vector<point> CH(vector< point> P) { // o conteúdo de P pode ser reordenado
 int i, j, n = (int)P.size();
 if (n <= 3) {
 if (!((P[0].x == P[n-1].x)&&(P[0].y == P[n-1].y))) P.push_back(P[0]);
 return P; // caso especial, o CH é o próprio P
 }
 // primeiro, encontrar pivô P0, ponto com menor Y (no caso de empate, maior X)
 int P0 = 0;
 for (i = 1; i < n; i++)
 if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
 P0 = i;
 point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // trocar P[P0] com P[0]
// segundo, ordenar pontos segundo grau em relação ao pivô P0
 pivot = P[0]; // variável global
 sort(++P.begin(), P.end(),angle); // P[0] não é ordenado
 // third, the ccw tests
 vector<point> S;
 S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // S inicial
 i = 2; // então, os outros pontos são verificados
 while (i < n) { // nota: N deve ser >= 3 para que este método funcione
 j = (int)S.size()-1;
 if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // curva à esquerda, aceitar
 else S.pop_back(); }//ou remover o topo de S até que ocorra uma curva à esquerda
 return S; // retornar o resultado CH(P)
}
double dist(point p1, point p2) { // std::hypot(dx, dy) retorna sqrt(dx *
 return hypot(p1.x - p2.x, p1.y - p2.y); }

int main() {
  int n;
   point ponto;
  vector< point> pontos;
  cin>>n;
  double soma=0;
  while(n!=0){
    vector< point> pontos;
    soma=0;
    for(int i=0;i<n;i++){
    cin>>ponto.x;
    cin>>ponto.y;
    pontos.push_back(ponto);
    }
    pontos=CH(pontos);
    int i;
	for(i=0;i<pontos.size()-1;i++){
	   soma+=dist(pontos[i],pontos[i+1]);
	}
	cout <<"Tera que comprar uma fita de tamanho "<<fixed << setprecision(2) << soma<<"."<<endl;

	cin>>n;
}
}