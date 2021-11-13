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
#include <bitset>

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
  int one, rep, kase=1;
  while(scanf("%d %d", &one, &rep), (one || rep)) {
    bitset<1000001> schedule=0b0, task = 0b0;
    bool ok = true;
    double st, end, delta; 
    for(int i=0; i<one; ++i) {
      scanf(" %lf %lf ", &st, &end);
      if(!ok) continue;
      for(int j=st; j<end; ++j) {
        if(schedule[j]) {
          ok = false; break;
        }
        schedule.set(j, 1);
      }
    } 
    for(int i=0; i<rep; ++i) {
      scanf(" %lf %lf %lf ", &st, &end, &delta);
      int r=(1000000-st)/delta;
      if(!ok) continue; 
      for(int j=0; j<=r; ++j) {
        if(!ok) break; 
        for(int k=st+delta*j; (k<(end+delta*j)) && (k < 1000000) ; ++k) {
          if(schedule[k]) {
            ok = false; break;
          }
          schedule.set(k, 1);
        }
      }

    }
    if(!ok)
      cout << "CONFLICT\n";
    else
      cout << "NO CONFLICT\n";
    ++kase;
  }
}
