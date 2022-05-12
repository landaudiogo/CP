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


bitset<1024010> pland;
vector<bool> A;
vector<int> ST;
vector<int> state;

int stateNone = 0b00, 
    stateSet =  0b01, 
    stateFlip = 0b10,
    stateClear = 0b11;

int tree_build(int p, int l, int r) { 
  if(l == r) return (ST[p] = A[l]);
  int vl = tree_build((p<<1)  , l          , (l+r)/2),
      vr = tree_build((p<<1)+1, (l+r)/2 + 1, r      );
  ST[p] = vl + vr;
  return ST[p];
}
void build(int bitsetSize) { 
  A.assign(bitsetSize, 0);
  for(int i = 0; i < bitsetSize; ++i) A[i] = pland[i];
  ST.assign(4*bitsetSize, 0);
  state.assign(4*bitsetSize, 0);
  tree_build(1, 0, bitsetSize-1);
}

int applyflip(int currState) {
  if(currState == stateFlip) return stateNone;
  else if(currState == stateClear) return stateSet;
  else if(currState == stateSet) return stateClear;
  else return stateFlip;
}
void propagate(int p, int i, int j) {
  if(state[p] == stateNone) return;
  else if(state[p] == stateSet)   ST[p] = j-i+1;
  else if(state[p] == stateClear) ST[p] = 0;
  else if(state[p] == stateFlip)  ST[p] = j-i+1-ST[p];
  if(i != j) {
    if(state[p] == stateClear || state[p] == stateSet)
      state[p<<1] = state[(p<<1)+1] = state[p];
    else {
      state[p<<1] = applyflip(state[p<<1]);
      state[(p<<1)+1] = applyflip(state[(p<<1)+1]);
    }
  }
  state[p] = stateNone;
}

void tree_set(int p, int i, int j, int L, int R) {
  propagate(p, i, j);
  if(i > R || j < L) return;
  if(i == j) { ST[p] = 1; return; }
  if(i >= L && j <= R) {
    ST[p] = j-i+1;
    state[p<<1] = state[(p<<1)+1] = stateSet;
    return;
  }
  tree_set(p<<1    , i        , (i+j)/2, L, R);
  tree_set((p<<1)+1, (i+j)/2+1, j      , L, R);
  ST[p] = ST[(p<<1)] + ST[(p<<1)+1];
}
void setbits(int L, int R) { tree_set(1, 0, A.size()-1, L, R); }

void tree_clear(int p, int i, int j, int L, int R) {
  propagate(p, i, j);
  if(i > R || j < L) { return; }
  if(i == j) { ST[p] = 0; return; }
  if(i >= L && j <= R) { 
    ST[p] = 0;
    state[p<<1] = state[(p<<1)+1] = stateClear;
    return;
  }
  tree_clear(p<<1, i        , (i+j)/2, L, R);
  tree_clear((p<<1)+1, (i+j)/2+1, j      , L, R);
  ST[p] = ST[p<<1] + ST[(p<<1)+1];
}
void clear(int L, int R){ tree_clear(1, 0, A.size()-1, L, R); }

void tree_flip(int p, int i, int j, int L, int R) {
  propagate(p, i, j);
  if(i > R || j < L) return;
  if(i == j) { ST[p] = ST[p]^1; return; }
  if(i >= L && j <= R) {
    ST[p] = (j-i+1) - ST[p];
    state[p<<1] = applyflip(state[p<<1]);
    state[(p<<1)+1] = applyflip(state[(p<<1)+1]);
    return;
  }
  tree_flip(p<<1    , i        , (i+j)/2, L, R);
  tree_flip((p<<1)+1, (i+j)/2+1, j      , L, R);
  ST[p] = ST[p<<1] + ST[(p<<1)+1];
}
void flip(int L, int R) { tree_flip(1, 0, A.size()-1, L, R); }



int rq(int p, int i, int j, int L, int R, bool &flag) {
  propagate(p, i, j);
  if((i > R) || (j < L)) { flag = true; return -1; }
  if((i >= L) && (j <= R)) return ST[p];

  bool f1 = false, f2 = false; 
  int r1 = rq((p<<1)  , i        , (i+j)/2  , L, R, f1), 
      r2 = rq((p<<1)+1, (i+j)/2+1, j        , L, R, f2);

  int res = 0;
  if(!f1) res += r1;
  if(!f2) res += r2;
  return res;
}
int query(int L, int R) { bool flag = false; return rq(1, 0, A.size()-1, L, R, flag); }

int main() {
  int tc; 
  cin >> tc;
  for(int x = 0; x<tc; ++x) {
    int m; 
    cin >> m;

    int currIdx = 0;
    while(m--) {
      int t; 
      string bits;
      cin >> t >> bits;
      for(int i = 0; i < t; ++i) 
        for(int j = 0; j < bits.size(); ++j, ++currIdx) 
          pland[currIdx] = (bits[j] == '0') ? 0 : 1;
    }
    build(currIdx);

    int q, snum = 0; 
    cin >> q;
    cout << "Case: " << x << endl;
    while(q--) {
      char op; 
      int a, b;
      cin >> op >> a >> b;
      if(op == 'I') flip(a, b);
      else if(op == 'E') clear(a, b);
      else if(op == 'F') setbits(a, b);
      else if(op == 'S') {
        cout 
          << "Q"
          << ++snum
          << ": "
          << query(a, b) 
          << endl;
      }
    }
  }
}
