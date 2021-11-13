#include <iostream>

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define uint64 unsigned long long
#define int64 long long

using namespace std;


const int dx[] {-1, 0, 1, 0};
const int dy[] {0, 1, 0, -1};


int main() {
  int t; cin >> t;
  while(t--) {
    int g[3][3];
    REP(i, 3) {
      REP(j, 3) {
        char c; scanf(" %c", &c);
        g[i][j] = c-'0';
      }
    }

    int q=0; 
    while(true) {
      bool zeros = true; 
      int aux[3][3] = {};
      REP(i, 3) {
        REP(j, 3) {
          REP(k, 4) {
            int idxx = j+dx[k], idxy = i+dy[k];
            if((idxx >= 0 && idxx < 3) && (idxy >= 0 && idxy < 3)) {
              aux[i][j] ^= g[idxy][idxx];
              //cout << i << "-" << j << " = " << aux[i][j] << endl;
            }
            if(aux[i][j] != 0) {
              zeros = false;
              //cout << "here\n";
            }
          }
          //cout << endl;
        }
        
      }

      if(zeros) {
        cout << q-1 << endl;;
        break;
      }

      REP(i,3) {
        REP(j,3) {
          g[i][j] = aux[i][j];
        }
      }
      ++q;
    }
  }
}
