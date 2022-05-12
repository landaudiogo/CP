#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
#define maxN 10
#define maxM 10

using namespace std;

int mat[maxM][maxN];
int smat;

void 
row(int mat[maxM][maxN], int a, int b) {
  int aux[smat];
  REP(i, smat) {
    aux[i] = mat[a][i];
  }

  REP(i, smat) {
    mat[a][i] = mat[b][i];
    mat[b][i] = aux[i];
  }
}

void 
col(int mat[maxM][maxN],  int a, int b) {
  int aux[smat];
  REP(i, smat) {
    aux[i] = mat[i][a];
  }

  REP(i, smat) {
    mat[i][a] = mat[i][b];
    mat[i][b] = aux[i];
  }
}

void
transpose(int mat[maxM][maxN]) {
  int aux[smat][smat];
  REP(i, smat) {
    REP(j, smat) {
      aux[j][i] = mat[i][j];
    }
  }

  REP(i, smat) {
    REP(j, smat) {
      mat[i][j] = aux[i][j];
    }
  }


}

void
inc(int mat[maxM][maxN]) {
  REP(i, smat) {
    REP(j, smat) {
      mat[i][j] = (mat[i][j]+1)%10;
    }
  }
}

void
dec(int mat[maxM][maxN]) {
  REP(i, smat) {
    REP(j, smat) {
      int res = (mat[i][j]-1);
      res = (res==-1)?10+res:res;
      mat[i][j] = res%10;
    }
  }
}

int main() {
  int T, kase=1; cin >> T;
  while(T--) {
    cin >> smat;
    REP(i, smat) {
      REP(j, smat) {
        char c; scanf(" %c", &c);
        mat[i][j] = c-'0';
      }
    }

    int ops; cin >> ops;
    REP(i, ops) {
      string op; 
      cin >> op;
      if (op == "transpose") {
        transpose(mat);
      } else if(op == "row") {
        int a, b; cin >> a >> b;
        row(mat, a-1, b-1);
      } else if(op == "col") {
        int a, b; cin >> a >> b; 
        col(mat, a-1, b-1);
      } else if(op == "inc") {
        inc(mat);
      } else if(op == "dec") {
        dec(mat);
      }
      
    }

    cout << "Case #" << kase << endl;
    REP(i, smat) {
      REP(j, smat) {
        cout << mat[i][j];
      }
      cout << endl;
    }
    cout << endl;
    ++kase;
  }

}


