#include <map>
#include <string>
#include <iostream>

using namespace std; 

typedef struct {
  string name; 
  double received;
  int give;
} person; 



int main() {
  int ng; 
  int flag=0; 
  
  while(scanf("%d", &ng) != EOF) {
    if(flag)
      cout << endl; 
    else
      flag = 1; 
    map<string, person> G;     
    string order[10];
    int tmp=0;
    while(tmp!=ng) {
      string name; cin >> name; 
      order[tmp++] = name;
      person A = {"", 0,0};
      G[name] = A;
    }

    for(int i=0; i<ng; ++i) {
      int give, ngive;
      string g; cin >> g;
      cin >> give >> ngive;
      if(!ngive) continue;
      G[g].give += give;
      G[g].received += give%ngive; 
      int t2 = ngive;
      while(t2--) {
        string r; cin >> r; 
        G[r].received += (int)give/ngive;
      }
    }

    for(int i=0; i<ng; ++i) {
      cout << order[i] << " "; 
      cout << G[order[i]].received - G[order[i]].give << endl;
    }
  }
}
