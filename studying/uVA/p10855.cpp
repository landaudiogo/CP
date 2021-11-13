#include <iostream>

using namespace std;


void
rotate(int n, char *small) {
  char repl[n][n];
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      repl[i][j] = *(small+(n-1-j)*n + i);
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      *(small+i*n + j) = repl[i][j];
    }
  }
}

bool
compare(char *small, int n, char *big, int N, int pos[]) {
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      //cout << *(small + i*n + j) << "=" << *(big + (i+pos[0])*n + (j+pos[1])) << " ";
      if(*(small + i*n + j) != *(big + (i+pos[0])*N + (j+pos[1])) )
        return false;
    }
    //cout << endl;
  }

  return true;
}

void
print2Darray(char *small, int n) {
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cout << *(small + i*n + j) << " ";
    }
    cout << endl;
  }
}

int main() {
  int N, n;
  while(scanf("%d %d", &N, &n), (N||n)) {

    char big[N][N], small[n][n];
    //store the squares
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        cin >> big[i][j];
      }   
    }
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        cin >> small[i][j];
      }   
    }

    for(int k=0; k<4; ++k) {
      int total=0; 
      for(int i=0; i<=N-n; ++i) {
        for(int j=0; j<=N-n; ++j) {
          int pos[] = {i, j};
          bool res = compare((char*)small, n, (char*)big, N, pos);
          if(res) {
            total += 1; 
          }
        }
        
      }
      rotate(n, (char*)small);
      cout << total;
      if(k != 3)
        cout << " ";
    }
    cout << endl;

     

    
  }

}
