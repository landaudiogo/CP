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
  int tc;
  cin >> tc;
  while(tc--) {
    int a, b;
    cin >> a >> b;
    int diff = abs(a-b);
    if((diff%2 != 0) || ((a<0) && (b<0))) {
      cout << -1;
    }
    else if (!diff) {
      if(a && b)
        cout << 1;
      else
        cout << 0;
    }
    else {
      cout << 2;
    }
    cout << '\n';
  }   
}
