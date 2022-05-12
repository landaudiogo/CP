#include <cstdio>
#include <algorithm>

using namespace std; 

int main() {
  int p[10];
  for (int i=0; i<10; ++i) p[i] = i;

  do {
    for(int i=0; i<10; ++i) printf("%c", 'A'+p[i]);
    printf("\n"); 
  }
  while(next_permutation(p, p+10));

}
