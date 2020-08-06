/* File: fibonacci.c */
/* Nama/NIM: Rehuel Grace/18218006 */
/* Topik: stack */

#include <stdio.h>
#include "stack.h"
int fibonacci(int x){
	if (x==1){
		return 0;
	} else if (x==2){
		return 1;	
	} else {
		return fibonacci(x-2)+fibonacci(x-1);
	}
}

int main(){
	int bilangan, hasil;
	scanf("%d", &bilangan);
	hasil = fibonacci(bilangan);
	printf("%d\n", hasil);
	return 0;
}
