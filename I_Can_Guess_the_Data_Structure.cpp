#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
  int n;
  int x;
  int y;
  while(cin>>n){
    queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
    bool isQ=true,isS=true,isPQ = true;
    for(int i=0;i<n;i++){
      cin>>x>>y;
      if(x==1){
          if(isQ){
            q.push(y);
          }
          if(isS){
            s.push(y);
          }
          if(isPQ){
            pq.push(y);
          }
      }
      if(x==2){
          if (isQ) {
					if (q.empty() || q.front() != y)
						isQ = false;
					else
						q.pop();
				}
				if (isS) {
					if (s.empty() || s.top() != y)
						isS = false;
					else
						s.pop();
				}
				if (isPQ) {
					if (pq.empty() || pq.top() != y)
						isPQ = false;
					else
						pq.pop();
				}
      }
    }
    if (isS == true && isQ == false && isPQ == false){
			cout << "stack" << endl;
    }
		else if (isS == false && isQ == true && isPQ == false){
			cout << "queue" << endl;
    }
		else if (isS == false && isQ == false && isPQ == true){
			cout << "priority queue" << endl;
    }
		else if (isS == false && isQ == false && isPQ == false){
			cout << "impossible" << endl;
    }
		else {
			cout << "not sure" << endl;
    }
    
  }
  return 0;
}