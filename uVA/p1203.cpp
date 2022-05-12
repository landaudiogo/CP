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
#include <queue>

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

  priority_queue<
    pair<pair<int, int>, int>, 
    vector<pair<pair<int, int>, int>>, 
    greater<pair<pair<int, int>, int>>
  > pq;
  string command;

  while(cin >> command && command != "#") {
    int qid, delta;
    cin >> qid >> delta;

    pq.push(make_pair(make_pair(delta, qid), delta));
  }

  int qs; 
  cin >> qs; 

  while(qs--) {
    pair<pair<int, int>, int> top = pq.top();
    cout << top.first.second << endl;
    pq.pop();
    top.first.first += top.second;
    pq.push(top);
  }



}
