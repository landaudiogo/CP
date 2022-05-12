#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std; 

int main() {
  int n, m, k; 
  cin >> n; 
  while(n--) {
    long long table[256] = {}, total=0, price;
    cin >> k;
    while(k--) {
      char c;
      cin >> c >> price;
      table[c + 128] = price;
    }
    cin >> m; cin.ignore();
    while (m--) {
      char c, line[10001];
      while((c=getchar()) != '\n') {
        total += table[c + 128];
      }
    }
    printf("%lld.%02lld$\n", total/100, total%100);
  }
}
