#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> li = {1,2,3,4,10,20,25,34,36};
  int v = 3;
  printf("%d\n", binary_search(li.begin(), li.end(), v));
}
