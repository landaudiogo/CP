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

  int m, n;
  while(cin >> m >> n) {
    vector< vector<pair<int, int>> > Mat(n, vector<pair<int, int>>());
    for(int i=0; i<m; ++i) {
      string idxs, vals;
      int nzero;
      cin >> nzero;
      getline(cin, idxs);
      getline(cin, vals);
      istringstream sidxs(idxs), svals(vals);

      while(nzero--) {
        int idx, val;
        sidxs >> idx; 
        svals >> val;
        Mat[idx-1].push_back(pair<int, int>(i+1, val));
      }

    }

    cout << n << " " << m << endl;
    for(int i=0; i<n; ++i) {
      cout << Mat[i].size();
      for(int j=0; j<Mat[i].size(); ++j) {
        cout << " " << Mat[i][j].first;
      }
      cout << endl;
      for(int j=0; j<Mat[i].size(); ++j) {
        if(j) cout << " ";
        cout << Mat[i][j].second;
      }
      cout << endl;

    }
  }

}  
