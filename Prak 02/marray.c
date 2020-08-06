#include "array.h"
#include <stdio.h>

/*KAMUS*/
TabInt T;
int i, N, nilaimax, nilaimin;


/*ALGORITMA*/
int main() {
	scanf("%d", &N);
	while ((N <= 0)||(N > MaxNbEl(T))) {
		scanf("%d", &N);
	}
	
	for (i=0;i<=N;i++) {
		scanf("%d", &T.TI[i]);
	}
	
	printf("[%d", T.TI[0]);
	
	for (i=1;i<=(N-1);i++) {
		printf(",%d", T.TI[i]);
	}
	printf("]\n");
	
	
	nilaimin = T.TI[0];
	for (i=1; i<=(N-1);i++) {
		if (T.TI[i] <= nilaimin)
			nilaimin = T.TI[i];
	}
	printf("%d\n", nilaimin);
	
	nilaimax = T.TI[0];
	for (i=1; i<=(N-1);i++) {
		if (T.TI[i] >= nilaimax)
			nilaimax = T.TI[i];
	}
	printf("%d\n", nilaimax);
	
	return 0;
}
