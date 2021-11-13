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

  int n;
  while(scanf("%d", &n) != EOF) {
    int corners=(1<<n), ans; 

    int cornerSum[corners] = {};
    for(int i=0; i<corners; ++i) {
      int cornerVal;
      scanf("%d", &cornerVal);
      for(int j=0; j<n; ++j) {
        cornerSum[i^(1<<j)] += cornerVal;

      }
    }

    for(int i=0; i<corners; ++i) {
      for(int j=0; j<n; ++j) {
        int val = cornerSum[i] + cornerSum[i^(1<<j)];
        if(!(i||j)) {
          ans = val;
        }
        if(val > ans) {
          ans = val;
        }
      }
    }

    cout << ans << endl;

  }
}
