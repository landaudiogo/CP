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
#include <set>
#include <vector>
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

int QUEUE=0, 
    STACK=1, 
    PRIORITY=2;

int main() {

  int n;
  while(cin >> n) {
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
    bitset<3> valid = 0b111;

    while(n--) {
      int op, el;
      cin >> op >> el;

      if(op == 1) {
        if(valid[QUEUE]) {
          q.push(el);
        } 
        if(valid[STACK]) {
          s.push(el);
        } 
        if(valid[PRIORITY]) {
          pq.push(el);
        } 
      } 
      else {
        if(valid[QUEUE]) {
          if(q.empty()) valid[QUEUE] = 0;
          else if(q.front() != el) valid[QUEUE] = 0;
          else q.pop();
        } 
        if(valid[STACK]) {
          if(s.empty()) valid[STACK] = 0;
          else if(s.top() != el) valid[STACK] = 0;
          else s.pop();
        } 
        if(valid[PRIORITY]) {
          if(pq.empty()) valid[PRIORITY] = 0;
          else if(pq.top() != el) valid[PRIORITY] = 0;
          else pq.pop();
        }
      }
    }
    if(valid.count() > 1)
      cout << "not sure\n";
    else if(valid.count() == 0)
      cout << "impossible\n";
    else if(valid[QUEUE])
      cout << "queue\n";
    else if(valid[STACK])
      cout << "stack\n";
    else if(valid[PRIORITY])
      cout << "priority queue\n";
      
  }

}
