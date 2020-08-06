#include <stdio.h>
#include "roman.h"
#include "stack.h"

int main(){
	Stack S;
	int n, sum, i;
	char x;
	CreateEmpty(&S);
	scanf("%d", &n);
	i = 1;
	while (i <= n){
		scanf("%d", &x);
		Push(&S,x);
		i++;
	}
	Decimal(S);
	return 0;
}

//ANEH