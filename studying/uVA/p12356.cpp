#include <iostream>
#include <cmath>

using namespace std;

typedef struct element_ {
  element_ *next, *prev;
  size_t index;
} soldier; 

void
delete_range(soldier frontline[], unsigned L, unsigned R) {
  if((frontline[L].prev != NULL) && (frontline[R].next != NULL)) {
    frontline[L].prev->next = frontline[R].next;
    frontline[R].next->prev = frontline[L].prev;
    cout << frontline[L].prev->index << " " << frontline[R].next->index << endl;
  } else if ((frontline[L].prev == NULL) && (frontline[R].next != NULL)) {
    frontline[R].next->prev = NULL;
    cout << "* " << frontline[R].next->index << endl;
  } else if((frontline[L].prev != NULL) && (frontline[R].next == NULL)) {
    frontline[L].prev->next = NULL;
    cout << frontline[L].prev->index << " *\n";
  } else {
    cout << "* *\n";
  }

  frontline[L].prev = NULL; 
  frontline[L].next = NULL; 
  frontline[R].prev = NULL;
  frontline[R].next = NULL;
}

int main() {
  int S, B; 

  while(scanf("%d %d", &S, &B), (S||B)) {
    soldier frontline[S+1];

    for(int i=1; i<=S; ++i) {
      if(i==1) {
        frontline[i].next = (min(i+1,S)==S) ? 
          NULL:&frontline[min(i+1,S)];
        frontline[i].prev = NULL;
      }
      else if(i==S) {
        frontline[i].prev = (max(1, i-1)==1) ? 
          NULL:&frontline[max(1, i-1)];
        frontline[i].next = NULL;
      }
      else {
        frontline[i].next = &frontline[min(i+1,S)];
        frontline[i].prev = &frontline[max(1,i-1)];
      }
      frontline[i].index = i;
    }

    while(B--) {
      int L, R; cin >> L >> R;
      delete_range(frontline, L, R);
    }
    cout << "-\n";
  }
}
