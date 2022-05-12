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

int p[26], r[26];

int getSet(int i) {
  return (i == p[i]) ? i : (p[i] = getSet(p[i]));
}


int sameSet(int i, int j) {
  return getSet(i) == getSet(j);
}

void joinSet(int i, int j) {
  if(!sameSet(i, j)) { 
    int x = getSet(i), y = getSet(j);
    if(r[x] > r[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if(r[y] == r[x]) r[y]++;
    }
  }
}

int main() {
  int tc; 
  cin >> tc;
  while(tc--) {
    Fill(p, -1);
    Fill(r, 0);
    int trees = 0, acorns = 0;

    string buffer;
    while((cin >> buffer) && buffer[0] != '*') {
      if(p[buffer[1] - 'A'] == -1) p[buffer[1] - 'A'] = buffer[1] - 'A';
      if(p[buffer[3] - 'A'] == -1) {
        p[buffer[3] - 'A'] = buffer[3] - 'A';
      }
      joinSet(buffer[1] - 'A', buffer[3] - 'A');
    }

    cin >> buffer;
    set<int> roots;
    //for(int i = 0; i < 26; ++i)
      //cout << i << " " << p[i] << " " << r[i]<< endl;

    for(int i = 0; i < buffer.size(); i += 2) {
      if(p[buffer[i] - 'A'] != -1) {
        if(roots.find(getSet(buffer[i] - 'A')) == roots.end()) {
          roots.insert(getSet(buffer[i] - 'A'));
          if(r[getSet(buffer[i] - 'A')] != 0) ++trees;
        }
      } else {
        ++acorns; 
      }


    }

    cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
  }
} 
