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
  while(scanf("%d", &n) && n != 0) {
    map<string, int> choices;
    pair<int, int> ans; //people choosing the same, number of combinations that share the same amount of people choosing the same

    for(int x=0; x<n; ++x) {
      vector<int> courses(5);

      for(int i=0; i<5; ++i) {
        cin >> courses[i];
      }
      sort(courses.begin(), courses.end());

      ostringstream ss;
      for(int i=0; i<5; ++i) {
        if(!i) ss << " ";
        ss << courses[i];
      }

      ++choices[ss.str()];
      if(choices[ss.str()] > ans.first) {
        ans = make_pair(choices[ss.str()], choices[ss.str()]);
      } else if(choices[ss.str()] == ans.first) {
        ans.second += choices[ss.str()];
      }
    }
    cout << ans.second << '\n';
  }

}
