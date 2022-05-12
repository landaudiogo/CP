#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>

int main() {
  int a[] = {2, 1, 3, 3, 2, 4, 4}; 
  std::vector<int> v(a, a+(int)(sizeof(a)/sizeof(a[0])));

  std::sort(v.begin(), v.end()); 
  std::vector<int>::iterator it = unique(v.begin(), v.end());
  v.resize(it - v.begin()); 
  for(int i=0; i!=v.size(); ++i) 
    std::printf("%d ", v[i]);
  std:: printf("\n");

  for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    std::printf("%d ", *i);
  std::printf("\n");


  double pi = std::acos(0.0)*2;
  int n = 2;
  std::printf("%*.*f\n", 5, n, pi);

}
