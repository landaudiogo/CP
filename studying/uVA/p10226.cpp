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
  int tc; 
  map<string, double> T;

  cin >> tc;
  cin.ignore();

  cin.ignore();
  while(tc--) {
    T.clear();
    int total = 0;
    string tree;

    while(getline(cin, tree) && !tree.empty()) { 
      T[tree] = T[tree] + 1;
      ++total;
    }
    
    for(auto it = T.begin(); it != T.end(); ++it) {
      printf("%s %.4lf\n", it->first.c_str(), (it->second/total)*100);
    }
    if(tc)
      cout << "\n";
  }
}
