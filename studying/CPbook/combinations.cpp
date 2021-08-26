#include <cstdio>

int main() {
  int s[20], N=20; 
  for(int i=0; i<N; ++i) s[i]=i;
  unsigned int bitmask = 0; 
  for(int i=1; i<(1<<N); ++i) {
    for(int j=0; j<N; ++j) {
      if(((1<<j) & i)) printf("%d ", s[j]);
    }
    printf("\n");
  }

}
