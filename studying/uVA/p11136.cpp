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
  multiset<int> urn;
  while(cin >> n && n!=0) {
    urn.clear();
    int pay = 0; 
    while(n--) {
      int k; 
      cin >> k;
      while(k--) {
        int bill; 
        cin >> bill; 
        urn.insert(bill);
      }

      multiset<int>::iterator itmin, itmax;
      itmin = urn.begin();
      itmax = --urn.end();

      pay += *itmax - *itmin; 
      urn.erase(itmax);
      urn.erase(itmin);
    }

    cout << pay << "\n";

  }
}
