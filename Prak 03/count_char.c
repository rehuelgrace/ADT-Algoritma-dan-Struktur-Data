#include <stdio.h>
#include "mesin_kar.h"

int main(){
	int count=0;
	char filename [999];
	scanf("%s", filename);
	START(filename);
	while (!(IsEOP())){
		if (CC=='e'){
			count+=1;
		}
		ADV();
	}
	printf("%d\n", count);
	return 0;
}
