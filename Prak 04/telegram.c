//Nama		: Rehuel Grace Marbun
//NIM		: 18218006

#include <stdio.h>
#include "mesin_kata.h"

int main(){
	int count, jumlah;
	char filename[999];
	scanf("%s", filename);
	STARTKATA(filename);
	jumlah = 0;
	count = 0;
	if (EndKata)
	{
		jumlah=0;
	}
	else
	{
		while (!EndKata){
			count+=1;
			if (CKata.Length < 11) {
				jumlah += 1000;
			}
			else { jumlah +=1500; }
			ADVKATA();
		}
	}
	if (count>10){
		jumlah = jumlah + 200;
	}
	printf("%d\n", jumlah);
	return 0;
}
