#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
  iii A = make_pair(ii(6, 20), -1998);
  iii B = make_pair(ii(5, 29), -1999);
  iii C = make_pair(ii(5, 20), -1997);
  vector<iii> birthdays = {A, B, C};
  sort(birthdays.begin(), birthdays.end());
  for (int i=0; i<birthdays.size(); ++i) 
    printf("%d, %d %d\n", birthdays[i].first.first, birthdays[i].first.second, birthdays[i].second*-1); 
}
