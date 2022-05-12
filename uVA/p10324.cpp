#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

int main() {
  char bitstream[1000001]; 
  int Case=1; 

  while (fgets(bitstream, 1000000, stdin)!=NULL){
    int queries, st, end, 
        Nbits=strlen(bitstream); 
    bitstream[Nbits] = '\0';

    if(strcmp(bitstream, "\n")==0) {
      break;
    }

    cin >> queries;
    cout << "Case " << Case++ << ":\n"; 
    for (int i=0; i<queries; ++i) {
      cin >> st >> end; 
      int aux=st; 
      st = min(st, end); end = max(aux, end);

      bool flag=true; 
      for(int j=st; j<=end; ++j)
        if(bitstream[j]!=bitstream[st])
          flag=false;
      cout << (flag?"Yes\n":"No\n");
      while(getchar()!='\n');
    }
  }
}
