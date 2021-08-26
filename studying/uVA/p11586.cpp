#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

int main() {
  int T; cin >> T; 
  while(getchar() != '\n');


  while(T--) {
    string tracks; 
    getline(cin, tracks);
    istringstream ss(tracks);
    string word; 

    int balance=0, Nt=0;
    while(ss >> word) {
      for(auto c : word) {
        balance += (c=='M'?1:-1);
      }
      ++Nt;
    }
    if ((Nt > 1) && (balance == 0))
      cout << "LOOP" << endl;
    else 
      cout << "NO LOOP" << endl; 
  }
}
