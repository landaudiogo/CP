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
  
  int n; cin >> n;
  cin.ignore(1, '\n');
  cin.ignore(1, '\n');
  while(n--) {
    pair<bool, int> C[101][10];
    vector<pair<int, pair<int, int>>> scoreboard(101, make_pair(0, make_pair(0, 0))); // <solved, <time, index>> <dec, <dec, inc>
    string s;
    while(getline(cin, s), s.length()!=0) {
      int c, p, t; char l;
      istringstream ss(s);
      ss >> c >> p >> t >> l;

      scoreboard[c].second.second = c;
      if(l=='C') {
        if(!C[c][p].first) {
          C[c][p].first = true;
          C[c][p].second += t;
          scoreboard[c].first -= 1;
          scoreboard[c].second.first += C[c][p].second;
        }   
      } else if(l=='I') {
        C[c][p].second += 20;
      }
    }
    sort(scoreboard.begin(), scoreboard.end());
    for(int i=0; i<scoreboard.size(); ++i) {
      if(scoreboard[i].second.second) {
        cout 
          << scoreboard[i].second.second 
          << " "
          << -scoreboard[i].first 
          << " "
          << scoreboard[i].second.first
          << endl;
      }
    }
    if(n)
      cout << endl;
  }


}
