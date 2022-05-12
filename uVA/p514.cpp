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
  stack<int> station;
  int N; 
  while(scanf("%d", &N), N!=0) {
    
    int c, i=0, j=1; // next car, B pos, next A
    bool ok=true;
    while(scanf(" %d", &c), c!=0) {
      while(station.empty() || (station.top() != c)) {
        if(j > N) {
          ok=false;
          break;
        }
        station.push(j);
        ++j;
      }
      if(ok) station.pop();
      if((++i)==N) {
        if(!ok) cout << "No\n";
        else cout << "Yes\n";
        while(!station.empty()) station.pop();
        i=0, j=1, ok=true;
      }
    }
    cout << endl;
  }
}
