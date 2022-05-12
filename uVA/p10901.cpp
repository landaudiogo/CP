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
  queue<pair<int, int>> ferry, leftb, rightb;
  int tc;
  cin >> tc;
  while(tc--) {
    int n, t, m;
    string ans[10000];
    cin >> n >> t >> m;
    for(int i=0; i<m; ++i) {
      int arrival;
      string side; 
      cin >> arrival >> side;
      if(side == "left") {
        leftb.push(make_pair(arrival, i));
      } else {
        rightb.push(make_pair(arrival, i));
      }
    }

    //run the simulation
    bool currBank = false; //start on the left
    int time = 0;
    while(!rightb.empty() || !leftb.empty() || !ferry.empty()) {

      //ferry on the right
      if(currBank == false) { 
        //unload ferry
        while(!ferry.empty()) {
          int ord = ferry.front().second; 
          ferry.pop();
          stringstream ss;
          ss << time; 
          ss >> ans[ord];
        }

        //load ferry
        while(!leftb.empty() && 
              (leftb.front().first <= time) && (ferry.size() < n)) {
          ferry.push(leftb.front());
          leftb.pop();
        }

        //update bank and time
        if(ferry.empty()) {
          if(!leftb.empty() && !rightb.empty()) {
            if(leftb.front().first <= rightb.front().first) {
              time = leftb.front().first;
            } else {
              time = max(rightb.front().first, time) + t;
              currBank = !currBank;
            }
          } else if(leftb.empty() && rightb.empty()) {
            break;
          } else if(leftb.empty()) {
            time = max(rightb.front().first, time) + t;
            currBank = !currBank;
          } else if(rightb.empty()) {
            time = leftb.front().first;
          }
        } else {
          currBank = !currBank;
          time += t;
        }
      } 

      // ferry on the right
      else { 
        // unload ferry
        while(!ferry.empty()) {
          int ord = ferry.front().second; 
          ferry.pop();
          stringstream ss;
          ss << time; 
          ss >> ans[ord];
        }

        //load ferry
        while(!rightb.empty() &&
              (rightb.front().first <= time) && (ferry.size() < n)) {
          ferry.push(rightb.front()); 
          rightb.pop();
        }
        
        //update bank and time
        if(ferry.empty()) {
          if(!rightb.empty() && !leftb.empty()) {
            if(rightb.front().first <= leftb.front().first) {
              time = rightb.front().first;
            } else {
              time = max(leftb.front().first, time) + t;
              currBank = !currBank;
            }          
          } 
          else if(rightb.empty() && leftb.empty()) {
            break;
          } else if(rightb.empty()) {
            time = max(leftb.front().first, time) + t;
            currBank = !currBank; 
          } else if(leftb.empty()) {
            time = rightb.front().first;
          }
        } else {
          currBank = !currBank;
          time += t;
        }   
      }
    }
    for(int i=0; i<m; ++i) {
      cout << ans[i] << '\n';
    }
    if(tc) cout << '\n';
  }

}
