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


vector<int> p; // parent
vector<int> r; // rank
vector<int> s; // size
map<string, int> uni;

int getSet(int i) {
  return (p[i] == i) ? i : (p[i] = getSet(p[i]));

}

int sameSet(int i, int j) { 
  return getSet(i) == getSet(j);
}

void joinSet(int i, int j) { 
  if(!sameSet(i, j)) {
    int x = getSet(i), y = getSet(j);
    if(r[x] > r[y]) { 
      p[y] = x; 
      s[x] += s[y]; 
    }
    else {
      p[x] = y;
      s[y] += s[x];
      if(r[y] == r[x]) ++r[y];
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    p.clear();
    r.clear();
    s.clear();
    uni.clear();

    int f; 
    cin >> f;
    while(f--) {
      string f1, f2;
      cin >> f1 >> f2;
      auto it1 = uni.find(f1);
      if(it1 == uni.end()) {
        int currSize = uni.size();
        uni[f1] = currSize;
        p.push_back(uni[f1]);
        r.push_back(0);
        s.push_back(1);
      }
      auto it2 = uni.find(f2);
      if(it2 == uni.end()) {
        int currSize = uni.size();
        uni[f2] = currSize;
        p.push_back(uni[f2]);
        r.push_back(0);
        s.push_back(1);
      }

      joinSet(uni[f1], uni[f2]);
      cout << s[getSet(uni[f1])] << endl;
    }

  }

}
