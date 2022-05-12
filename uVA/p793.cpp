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



vector<int> p; 
vector<int> r;


int getSet(int i) {
  return (i == p[i]) ? i : (p[i] = getSet(p[i]));
}

bool sameSet(int i, int j) {
  return getSet(i) == getSet(j);
}

void joinSet(int i, int j) {
  if(!sameSet(i, j)) {
    int x = getSet(i), 
        y = getSet(j);

    if(r[x] > r[y]) p[y] = x;
    else {
      if(r[x] == r[y]) ++r[y];
      p[x] = y;
    }
  }
}


int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int nc, corr = 0, incorr = 0;
    cin >> nc;
    cin.ignore();

    p.assign(nc, 0);
    for(int i=0; i<nc; ++i) p[i] = i;
    r.assign(nc, 0);

    string command;
    while(getline(cin, command) && (command != "")) {
      istringstream cs(command); 
      char type;
      int c1, c2;
      cs >> type >> c1 >> c2;
      if(type == 'c') joinSet(c1, c2);
      else {
        if(sameSet(c1, c2)) ++corr;
        else ++incorr;
      }
    }
    cout << corr << "," << incorr << endl;
    if(tc) cout << endl;
  }

}
