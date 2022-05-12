#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
  string line;
  while(getline(cin, line)) {
    istringstream ss(line);
    int N, number;
    vector<int> S, res;
    ss >> N; ss >> number; S.push_back(number);
    
    while(ss >> number) {
      S.push_back(number);
      res.push_back(abs(*(S.end()-1)-*(S.end()-2)));
    }
    sort(res.begin(), res.end());
    bool flag=false; 
    for(int i=0; i<res.size(); ++i) {
      if(res[i]!=i+1)
        flag=true;
    }
    if (flag)
      cout << "Not jolly\n";
    else
      cout << "Jolly\n";
  }
}
