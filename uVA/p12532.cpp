#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <set>
#include <queue>
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

vector<int> A;
vector<int> T;

void build_tree(int p, int i, int j) { 
  if(i == j) { T[p] = A[i-1]; return; }
  build_tree(p<<1    , i          , (i+j)/2);
  build_tree((p<<1)+1, ((i+j)/2)+1, j      );
  T[p] = T[p<<1] * T[(p<<1) + 1];
}

void build(vector<int> v) {
  A.assign(v.size(), 0);
  T.assign(4*v.size(), 0);
  for(int i = 0; i<v.size(); ++i) {
    if(v[i] > 0) A[i] = 1;
    else if(v[i] < 0) A[i] = -1;
    else A[i] = 0;
  }
  build_tree(1, 1, A.size());
}

void update_tree(int p, int i, int j, int idx, int val) { 
  if((idx < i) || (idx > j)) return;
  if(i == j) {
    if(val > 0) T[p] = 1;
    else if(val < 0) T[p] = -1;
    else T[p] = 0;
    return;
  }
  update_tree(p<<1    , i          , (i+j)/2, idx, val);
  update_tree((p<<1)+1, ((i+j)/2)+1, j      , idx, val);
  T[p] = T[p<<1] * T[(p<<1) + 1];
}
void update(int idx, int val) {
  update_tree(1, 1, A.size(), idx, val);
}

int query_tree(int p, int i, int j, int L, int R, bool &flag) { 
  if(i > R || j < L) { flag = true; return -1; }
  if((i >= L) && (j <= R)) { return T[p]; }

  bool lf = false, rf = false;
  int l = query_tree(p<<1    , i          , (i+j)/2, L, R, lf), 
      r = query_tree((p<<1)+1, ((i+j)/2)+1, j      , L, R, rf);

  int ans = 1;
  if(!rf) ans *= r;
  if(!lf) ans *= l;
  //cout << "--- " << ans << endl;
  return ans;
}
int query(int L, int R) { 
  bool flag = false;
  return query_tree(1, 1, A.size(), L, R, flag);
}


int main() {
  int n, k;
  while(cin >> n >> k) {
    vector<int> v(n, 0);
    for(int i = 0; i<n; ++i) cin >> v[i];
    build(v);
    for(int i = 0; i<k; ++i) {
      char command;
      int a, b;
      cin >> command >> a >> b;

      if(command == 'C') update(a, b);
      else if(command == 'P') {
        int ans = query(a, b);
        if(ans == 1) cout << '+';
        else if(ans == -1) cout << '-';
        else cout << 0;
      }
    }
    cout << endl;
  }
}
