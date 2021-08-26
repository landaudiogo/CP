#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
  int a[] = {1,2,3,2,3,4,4,5,4,2,3};
  std::vector<int> v(a, a+(int)(sizeof(a)/sizeof(a[0])));

  std::sort(v.begin(), v.end()); 
  std::vector<int>::iterator it = std::unique(v.begin(), v.end());
  v.resize(it-v.begin());
  for (int i = 0; i < (int)(v.size()); ++i)
    printf("%d ", v[i]);
  printf("\n");
}
