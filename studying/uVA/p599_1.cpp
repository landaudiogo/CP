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


vector<int> G[26];
bool visited[26];

int dfs(int idx) {
  if(visited[idx]) return 0;
  visited[idx] = true; 

  int depth = 1;
  for(int i = 0; i < G[idx].size(); ++i) {
    depth += dfs(G[idx][i]);
  }
  
  return depth;
}


int main() {
  int tc; 
  cin >> tc;
  while(tc--) {
    Fill(visited, false);
    for(int i = 0; i < 26; ++i) {
      G[i].clear();
    }

    string buffer;
    int trees = 0, acorns = 0; 

    while((cin >> buffer) && buffer[0] != '*') {
      // since it is an undirected graph
      G[buffer[1] - 'A'].push_back(buffer[3]-'A');
      G[buffer[3] - 'A'].push_back(buffer[1]-'A');
    }

    cin >> buffer;
    for( int i = 0; i < buffer.length(); i += 2 ) {
      int depth = dfs(buffer[i]-'A');
      if(depth == 1) {
        ++trees;
        ++acorns;
      } else if(depth > 1) {
        ++trees;
      }
    }

    cout << "There are " << trees-acorns << " tree(s) and " << acorns << " acorn(s).\n";
  }
} 
