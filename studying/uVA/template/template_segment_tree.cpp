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


template<class T> 
class SegmentTree {
private:
  vector<int> A;
  vector<T> st;

  int lchild(int p) { return p<<1; }
  int rchild(int p) { return (p<<1)+1; }

  void build(int p, int i, int j) { 
    
  }

  int query(int p, int i, int j, int L, int R, bool &flag) { 
    if(i>R || j<L) { flag = true; return -1; }
    if((i>=L) && (j>=R)) { return st[p]; }

    int mid = (i+j)/2;
    bool lf = false, rf = false;
    T l = query(lchild(p), i, mid, L, R, lf), 
      r = query(rchild(p), mid+1, j, L, R, rf);

    /*
     * Perform logic 
     */
  }

  void update(int p, int i, int j, int idx, int val) {
    if(idx<i || idx>j) return;
    if(i==j) { st[p] = val; return; }

    int mid = (i+j)/2;
    update(lchild(p), i, mid, idx, val);
    udpate(rchild(p), mid+1, j, idx, val);
  }
  
  void propagate(int p, int i, int j) {

  }

 
public:
  SegmentTree(vector<int> v) {
    A.assign(v.size(), 0);
    st.assign(4*v.size(), T());
    for(int i=0; i<v.size(); ++i) A[i] = v[i];
  }

  int query(int L, int R) { 
    return query(1, 0, A.size()-1, L, R);
  }
  
  void update(int idx, int val) {
    update(1, 0, A.size()-1, idx, val);
  }
};


int main() { 
  return 0;
}
