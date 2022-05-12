#include <iostream>
#define DIM 2

using namespace std;

int main() {
  int sz, p;
  
  while(scanf("%d %d", &sz, &p), (sz||p)) {
    if (p==1) {
      cout << "Line = " << (int)sz/2+1 << ", column = " << (int) sz/2+1 << "." << endl;
      continue;
    }
    int rs=1; // ring side
    while((rs*rs) < p) 
      rs+=2; 
    int last_ring = p - (rs-2)*(rs-2) -1;
    int side = last_ring/(rs-1);
    int extra = last_ring%(rs-1);

    int x_off, y_off;
    int start_x=sz/2+rs/2, start_y=sz/2+rs/2; // top right corner is the starting position

    if(side==0) { // top
      x_off = -1-extra;
      y_off = 0;
    } else if(side==1) { // left
      x_off = -(rs-1);
      y_off = -1-extra;
    } else if(side==2) { // bottom
      x_off = extra-(rs-2);
      y_off = -(rs-1);
    } else if(side==3) { // right
      x_off = 0;
      y_off = extra-(rs-2);
    }
    cout << "Line = " << start_y+y_off+1 << ", column = " << start_x+x_off+1 << "." << endl;

  }
}
