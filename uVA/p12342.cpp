#include <iostream>
#include <cmath>

typedef struct {
  int val;
  double rate;
} escalao; 

using namespace std;

int main() {
  int T; cin >> T;
  int N=T;
  while(T--) {
    escalao E[4] = {
      {180000, 0}, 
      {300000, 0.10}, 
      {400000, 0.15}, 
      {300000, 0.20}
    };

    int income, tax=0; 
    cin >> income;
    for(int i=0; i<4; ++i) {
      income -= E[i].val;
      if (income < 0) {
        double payable = (E[i].val+income)*E[i].rate; 
        tax += ceil(payable);
        break;
      }
      else {
        double payable = (E[i].val)*E[i].rate; 
        tax += ceil(payable);
      }
    }
    if (income > 0) {
      tax += ceil(income*0.25);
    }
    cout 
      << "Case " 
      << N-T
      << ": "
      << ((tax>0)?max(tax, 2000):0)
      << endl;
  }
}
