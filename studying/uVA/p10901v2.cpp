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
  vector<queue<pair<int, int>>> Q(2);
  int tc;
  cin >> tc;
  while(tc--) {
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> ans(m);

    //read the input
    for(int i=0; i<m; ++i) {
      int arrival;
      string side; 
      cin >> arrival >> side;
      if(side == "left") {
        Q[0].push(make_pair(arrival, i));
      } else {
        Q[1].push(make_pair(arrival, i));
      }
    }

    //simulate
    int time = 0;
    int bank = 0; //left
    int idx = 0;
    while(!Q[0].empty() || !Q[1].empty()) {
      int earliest_car = numeric_limits<int>::max();
      if(!Q[0].empty())
        earliest_car = Q[0].front().first;
      if(!Q[1].empty())
        earliest_car = min(earliest_car, Q[1].front().first);
      time = max(earliest_car, time);
      
      int fcount=0; 
      while(!Q[bank].empty() && 
            (fcount < n) && 
            (Q[bank].front().first <= time)) {
        ans[Q[bank].front().second] = time + t;
        Q[bank].pop();
        ++fcount; 
      }

      time += t;
      bank ^= 1;
    }

    //print out the answers
    for(int i=0; i<m; ++i) {
      cout << ans[i] << '\n';
    }
    if(tc) cout << '\n';
  }

}
