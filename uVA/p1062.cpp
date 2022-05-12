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



int main() {
  string C;
  int kase=1;
  vector<stack<char>> S;
  while(cin >> C, C!="end") {
    S.clear();

    for(int i=0; i<C.length(); ++i) {
      bool inserted = false;
      for(int j=0; j<S.size(); ++j) {
        if(!S[j].empty() && (S[j].top() >= C[i])) {
          S[j].push(C[i]);
          inserted = true;
          break;
        }
      }
      if(!inserted) {
        S.push_back(stack<char>());
        S.back().push(C[i]);
      }
    }
    cout << "Case " << kase++ << ": "<< S.size() << '\n';
  }

}
