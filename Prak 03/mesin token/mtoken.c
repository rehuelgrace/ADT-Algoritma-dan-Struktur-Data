#include "kata.h"
int main() {
  /*algoritma*/	
  STARTKATA(0,"pitakar.txt");
  while (!EndKata) {
    if(ctoken.val<0) 
      printf("<'%c', -1>\n",ctoken.tkn);
    else 
      printf("<'b', %d>\n",ctoken.val);
    ADVKATA(0);
  }
  return 0;
}