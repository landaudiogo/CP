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
#include <set>
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
  int n; 
  
  while(cin >> n && n != 0) {
    int ans = 0;
    priority_queue<
      int, 
      vector<int>, 
      greater<int>
    > setn;
    for(int i=0; i<n; ++i) {
      int num;
      cin >> num;
      setn.push(num);
    }
    for(int i=0; i<(n-1); ++i) { 
      int v1 = setn.top();
      setn.pop();
      int v2 = setn.top();
      setn.pop();
      setn.push(v1+v2);
      ans += v1 + v2;
    }
    cout << ans << endl;
  }
}
