#include <iostream>
#include <cstdio>

using namespace std; 

typedef struct {
  bool state;
  int consumption;
} device; 

int main() {

  int n, m, c, Seq=1;

  while(scanf("%d %d %d", &n, &m, &c), (n || m || c)) {
    int curr=0, maxCurr=0; 

    device D[n]; 
    bool blown=false;

    for(int i=0; i<n; ++i) {
      D[i].state = false;
      cin >> D[i].consumption; 
    }

    for(int i=0; i<m; ++i) {
      int idx; cin >> idx; 
      if (blown == true)
        continue;
      if (D[idx-1].state == false) {
        curr += D[idx-1].consumption; 
        if (curr > maxCurr) 
          maxCurr = curr;
        if (curr > c) 
          blown = true; 
      }
      else if (D[idx-1].state == true) {
        curr -= D[idx-1].consumption; 
      }
      D[idx-1].state ^= 1;
    }
    if (blown)
      cout 
        << "Sequence " 
        << Seq 
        << "\nFuse was blown.\n"; 
    else 
      cout 
        << "Sequence " 
        << Seq 
        << "\nFuse was not blown.\n"
        << "Maximal power consumption was "
        << maxCurr 
        << " amperes.\n";
    ++Seq;
    cout << endl;
  }
}
