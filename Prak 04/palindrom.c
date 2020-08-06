//Nama		: Rehuel Grace Marbun
//NIM		: 18218006

#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kar.h"

int main()
{
	char filename [999];
	int count, i;
	count=0;
	scanf("%s", filename);
	STARTKATA (filename);
	while(!EndKata){
		i=1;
		while (CKata.TabKata[i]==CKata.TabKata[CKata.Length+1-i]){
			i++;
		}
		if (i>(CKata.Length/2)) {
			count+=1;
		}
		ADVKATA();
	}
	printf("%d\n", count);
	return 0;
}
