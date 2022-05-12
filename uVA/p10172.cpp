#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 6
#define maxM 520

using namespace std;

int ans;
int main() {
  int SET;
  cin >> SET;

  for(int k=0; k<SET; ++k) {
    int N, S, Q, ans=0, remaining=0;
    cin >> N >> S >> Q;
    stack<int> c;
    vector<queue<int>> CQ;

    for(int i=0; i<N; ++i) {
      queue<int> q; 
      int qsize; 
      cin >> qsize; 
      remaining += qsize;
      for(int j=0; j<qsize; ++j) {
        int d; cin >> d; 
        q.push(d);
      }
      CQ.push_back(q);
    }

    int i=0; 
    while(remaining) {

      //Unload from stack to station
      while(!c.empty()) {
        int cg = c.top();
        if(cg == (i+1)) {
          c.pop();
          --remaining;
          ++ans;
        } else if (CQ[i].size() < Q){
          c.pop();
          CQ[i].push(cg);
          ++ans;
        } else break;
      }

      // load to stack
      while((c.size() < S) && (!CQ[i].empty())) {
        int cg = CQ[i].front();
        CQ[i].pop();
        c.push(cg);
        ++ans;
      }

      if(remaining) {
        i = (i+1)%N;
        ans += 2;
      }
    }
    
  cout << ans << '\n';
  }
  
}
