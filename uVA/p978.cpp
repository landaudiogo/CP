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
  int tc; 
  cin >> tc;
  while(tc--) {
    int b, sg, sb;
    cin >> b >> sg >> sb;

    multiset<int, greater<int>> green, blue;
    for(int i=0; i<sg; ++i) {
      int strength; 
      cin >> strength;
      green.insert(strength);
    }
    for(int i=0; i<sb; ++i) {
      int strength; 
      cin >> strength;
      blue.insert(strength);
    }

    while(!green.empty() && !blue.empty()) {

      vector<pair<int, int>> battlefields;
      for(
          multiset<int>::iterator itg=green.begin(), 
                                  itb=blue.begin(); 
          itg != green.end() && 
            itb != blue.end() && 
            (distance(green.begin(), itg) < b); 
          ++itg, ++itb) {
        battlefields.push_back(pair<int,int>(*itg, *itb)); 
      }

      for(int i=0; i<battlefields.size(); ++i) {
        auto it = green.find(battlefields[i].first);
        green.erase(it); 
        it = blue.find(battlefields[i].second);
        blue.erase(it); 
        int fight = battlefields[i].first-battlefields[i].second;
        if(fight < 0) {
          blue.insert(abs(fight));
        } else if(fight > 0) {
          green.insert(abs(fight));
        }
      }
    }

    for(multiset<int>::iterator it = green.begin(); it != green.end(); ++it) {
      if(!distance(green.begin(), it)) cout << "green wins\n";
      cout << *it << "\n";

    }
    for(multiset<int>::iterator it = blue.begin(); it != blue.end(); ++it) {
      if(!distance(blue.begin(), it)) cout << "blue wins\n";
      cout << *it << "\n";
    }
    if(blue.empty() && green.empty()) cout << "green and blue died\n";

    if(tc) cout << "\n";
  }
}
