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
  int n; 
  while(scanf(" %d", &n), n!=0) {
    int a=0, b=0;
    bool odd=true;
    for(int i=0; i<31; ++i) {
      if(n & (1<<i)) {
        if(odd)
          a |= (1<<i);
        else 
          b |= (1<<i);
        odd ^= 1; 
      }
    }
    cout << a << " " << b << endl;
  }

}
