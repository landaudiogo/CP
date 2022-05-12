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

vector<int> Vs[26];
bitset<26> awake;


int charidx(char c) {
  return c-'A';
}

int main() {
  int n;
  while(cin >> n) {
    awake.reset();
    for(int i=0; i<26; ++i) Vs[i].clear();

    int cs;
    cin >> cs;
    string st;
    cin >> st;
    bool flag = false;

    for(int i=0; i<3; ++i) awake[charidx(st[i])] = 1;

    set<int> sleep;
    for(int i=0; i<cs; ++i) {
      string p;
      cin >> p;
      Vs[charidx(p[0])].push_back(charidx(p[1]));
      Vs[charidx(p[1])].push_back(charidx(p[0]));
      if(!awake[charidx(p[0])] ) sleep.insert(charidx(p[0]));
      if(!awake[charidx(p[1])] ) sleep.insert(charidx(p[1]));
    }

    if(sleep.size() != (n-3)) flag = true;
    int asleep = sleep.size(), iter = 0;
    while((asleep>0) && !flag) {
      int numAwoke;
      bitset<26> aux; aux.reset();
      for(auto it = sleep.begin(); it != sleep.end(); ++it) {
        int contact = 0;
        for(int i=0; i<Vs[*it].size(); ++i) {
          if(awake[ Vs[*it][i] ])  ++contact;
        }
        if(contact >= 3) {
          aux[*it] = 1;
        }
      }
      for(int i=0; i<26; ++i) if(aux[i]) sleep.erase(i);
      if(aux.count() == 0) {
        flag = true;
        break;
      }
      asleep -= aux.count();
      awake |= aux;
      ++iter;
    }
    if(!flag) cout << "WAKE UP IN, " << iter << ", YEARS\n";
    else cout << "THIS BRAIN NEVER WAKES UP\n";
  }
}
