#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
#define maxN 12
#define maxM 520

using namespace std;

int p[maxN][maxN] = {};


int main() {
  int N; cin >> N;
  while(N--) {
    REP(i,5) {
      REP(j, i+1) {
        cin >> p[i*2][j*2];
      }
    }

    for(int j=1; j<9; j+=2) {
      p[8][j] = (p[6][j-1] - (p[8][j-1] + p[8][j+1]))/2;
    }

    for(int i=7; i>=0; --i) {
      REP(j, i+1) {
        p[i][j] = p[i+1][j] + p[i+1][j+1];
      }
    }

    REP(i, 9) {
      REP(j, i+1) {
        cout << p[i][j];
        if(j!=i) 
          cout << " ";
        
      }
      cout << endl;
    }
    Fill(p, 0);
  }
}



