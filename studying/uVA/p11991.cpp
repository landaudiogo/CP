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

int main() {
  map<int, vector<int>> nums;
  int n, m;
  while(cin >> n >> m) {
    nums.clear();
    for(int i=0; i<n; ++i) {
      int val; 
      cin >> val;
      auto it = nums.find(val);
      if(it == nums.end()) nums.insert(make_pair(val, vector<int>(1, i)));
      else it->second.push_back(i);
    }

    while(m--) {
      int pos, val;
      cin >> pos >> val;
      auto it = nums.find(val);
      if(it == nums.end()) cout << 0 << endl;
      else {
        if(it->second.size() < pos) cout << 0 << endl;
        else cout << it->second[pos-1]+1 << endl;
      }

    }
  }

}
