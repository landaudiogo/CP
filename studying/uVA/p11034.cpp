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

int main() {
  int tc;
  cin >> tc;
  while(tc--) {

    int l, m; 
    cin >> l >> m;
    vector<queue<int>> Q(2);

    // read the input
    for(int i=0; i<m; ++i) {
      int len;
      string s; 
      cin >> len >> s;
      if(s == "left") 
        Q[0].push(len);
      else 
        Q[1].push(len);
    }

    // simulate the process
    int stops = 0;
    int bank = 0;
    while(!Q[0].empty() || !Q[1].empty()) {

      int space = l*100;
      while(!Q[bank].empty() && 
            ((space-Q[bank].front()) > 0) ) {
        space -= Q[bank].front();
        Q[bank].pop();
      }

      ++stops;
      bank ^= 1;
    }

    cout << stops << '\n';
  }
}
