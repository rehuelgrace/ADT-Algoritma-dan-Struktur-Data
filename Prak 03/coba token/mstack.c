#include "stack.h"
int main(){
/*kamus*/
  Stack S;
  address i;
  infotype x;
/*algoritma*/
  CreateEmpty(&S);
  
  /*mengisi nilai s*/
  printf("masukkan isi stack:\n");
  while(!IsFull(S)) {
  	scanf("%d",&x);
  	if(x==999) break;
  	Push(&S,x);
	}
  TulisStack(S);
  FilterStack(&S);
  printf("\nSetelah dibuang bilangan ganjil:\n");
  TulisStack(S);
	return 0;
}