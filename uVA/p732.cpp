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

char ans[105], a[105], b[105], st[105];
int stidx, ansidx, len;

void dfs(int aidx, int bidx) {
  if(bidx == len) {
    bool first = true;
    for(int i=0; i<ansidx; ++i) {
      cout << (first ? "" : " ") << ans[i];
      first = false; 
    }
    cout << '\n';
  }

  if(aidx < len) {
    st[stidx++] = a[aidx];
    ans[ansidx++] = 'i';
    dfs(aidx+1, bidx);
    --stidx;
    --ansidx;
  }


  if(stidx && (st[stidx-1] == b[bidx])) {
    ans[ansidx++] = 'o';
    char tmp = st[--stidx];
    dfs(aidx, bidx+1);
    --ansidx;
    st[stidx++] = tmp;
  }
}

int main() {
  while(fgets(a, 105, stdin)!=NULL) {
    if(strcmp(a, "\n")==0) continue;
    while(fgets(b, 105, stdin), strcmp(b, "\n")==0);
    len = strlen(a)-1;
    cout << "[\n";
    if(strlen(a) == strlen(b)) {
      ansidx = 0, stidx = 0;
      dfs(0, 0);
    }
    cout << "]\n";
  }
}
