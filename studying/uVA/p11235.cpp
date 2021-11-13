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

typedef vector<pair<int, int>> vii;

vector<int> A;
vector< vector<pair<int, int>> > T;  // [0] = most frequent
                                // [1] = left frequency
                                // [2] = right frequency


void build_tree(int p, int i, int j) {
  if(i == j) {
    T[p][0] = pair<int, int>(1, A[i-1]);
    T[p][1] = pair<int, int>(1, A[i-1]);
    T[p][2] = pair<int, int>(1, A[i-1]);
    return;
  }
  build_tree(p<<1    , i          , (i+j)/2);
  build_tree((p<<1)+1, (i+j)/2 + 1, j      );
  pair<int, int> l, m, r, mf;

  if((T[p<<1][1].first == (j-i+1)/2) && 
     (T[p<<1][1].second == T[(p<<1)+1][1].second)
    ) {
    l = make_pair(T[p<<1][1].first + T[(p<<1)+1][1].first, T[p<<1][1].second);
  } else l = T[p<<1][1];

  if((T[(p<<1)+1][2].first == (j-i+1)/2) && 
     (T[(p<<1)+1][2].second == T[(p<<1)][2].second)
    ) {
    r = make_pair(T[p<<1][2].first + T[(p<<1)+1][2].first, T[(p<<1)+1][2].second);
  } else r = T[(p<<1)+1][2];

  if(T[p<<1][2].second == T[(p<<1)+1][1].second) 
    m = make_pair(T[p<<1][2].first + T[(p<<1)+1][1].first, T[p<<1][2].second);
  else m = make_pair(0, 0);

  mf = max({
      T[p<<1][0], 
      T[(p<<1)+1][0],
      m,
      l, 
      r
  });
  T[p][0] = mf;
  T[p][1] = l;
  T[p][2] = r;
}
void build(vector<int> v) {
  A.assign(v.size(), 0);
  for(int i=0; i<v.size(); ++i) A[i] = v[i];
  T.assign(4*v.size(), vii(3, pair<int, int>(0, 0)));
  build_tree(1, 1, v.size());
}

vector<pair<int, int>> query_tree(int p, int i, int j, int L, int R, bool &flag) {
  if((i>R) || (j<L)) {
    flag = true;
    return vii(3, make_pair(0, 0));
  }
  if((i>=L) && (j<=R)) return T[p];
  if(i == j) return T[p];
  
  bool rf = false, lf = false;
  vii l = query_tree(p<<1    , i        , (i+j)/2, L, R, lf), 
      r = query_tree((p<<1)+1, (i+j)/2+1, j      , L, R, rf),
      res(3, make_pair(0, 0));
  pair<int, int> m;

  //cout << i << " " << j << endl;
  if(!lf) { 
    if(!rf && (l[1].second == r[1].second)) {
      res[1] = make_pair(l[1].first + r[1].first, l[1].second);
    }
    else 
      res[1] = l[1];
  } else res[1] = r[1];

  if(!rf) {
    if(!lf && (r[2].second == l[2].second)) {
      res[2] = make_pair(r[2].first + l[2].first, r[2].second);
    }
    else
      res[2] = r[2];
  } else res[2] = l[2];

  if(!rf && !lf) {
    if(l[2].second == r[1].second) {
      m = make_pair(l[2].first + r[1].first, l[2].second);
    }
    else 
      m = make_pair(0, 0);
  }

  res[0] = max({
    r[0], 
    l[0],
    m,
    res[1],
    res[2]
  });
  return res;
}
vector<pair<int, int>> query(int L, int R) {
  bool flag;
  return query_tree(1, 1, A.size(), L, R, flag);
}

int main() {
  int n, q;
  int in_line = 0, out_line = 0;
  while(true) {
    cin >> n;
    if(!n) return 0;
    cin >> q;
    ++in_line;


    vector<int> v(n, 0);
    for(int i = 0; i<n; ++i) {
      cin >> v[i];
    }
    build(v);
    ++in_line;

    while(q--) {
      ++in_line;
      ++out_line;
      int a, b;
      cin >> a >> b;
      cout << query(a, b)[0].first << endl;
    }

  }

}

