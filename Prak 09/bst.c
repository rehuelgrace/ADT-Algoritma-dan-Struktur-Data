/*Nama		: Rehuel Grace*/
/*NIM		: 18218006*/

#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

void InsertBST (infotype X, BinTree *P){
	if (IsTreeEmpty(*P)){
		MakeTree(X,Nil,Nil,P);
	} else {
		if (X<=Akar(*P)){
			InsertBST(X,&Left(*P));
		}
		else
			InsertBST(X,&Right(*P));
	}
}

int main(){
	int N, i=1;
	BinTree P=Nil;
	infotype daun;
	do{
		scanf("%d\n", &N);
	}
	while(N<0);
	if(N>0){
		do{
			scanf("%d", &daun);
			InsertBST(daun,&P);
			i+=1;
		}
		while(i<=N);
	}
	PrintPreorder(P);
	printf("\n%d\n", Tinggi(P));
	return 0;
}
