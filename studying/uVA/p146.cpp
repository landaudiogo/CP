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
  string s;
  while(getline(cin, s), s!="#") {
    char c;
    bool decreasing = true;
    for(int i=1; i<s.size(); ++i) {
      if(s[i] > s[i-1]) 
        decreasing = false; 
    }
    if(decreasing) {
      cout << "No Successor\n";
      continue;
    }
    next_permutation(s.begin(), s.end());
    cout << s << endl;
  }
}
