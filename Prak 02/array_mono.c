//NIM				: Rehuel Grace M
//Nama				: 18218006
//Tanggal			: 19 September 2019
//Topik praktikum	: ADT Array Eksplisit - Statis
//Deskripsi			: Array Monotonik

#include <stdio.h>
#include "array.h"

int main(){
	int i, Max, Min, N, s, R, G, M, A;
	TabInt T;
	scanf("%d", &N);
	while (N<=0 || N>=IdxMax){
		scanf("%d", &N);
	}
	MakeEmpty(&T);
	for(i=1; i<=N; i++) {
		scanf("%d", &s);
		SetEl(&T,i,s);
	}
	R=1;
	G=1;
	M=1;
	A=GetElmt(T,1);
	for(i=2; i<=N; i++){
		if(GetElmt(T,i)>A){
			R+=1;
		}
		else if (GetElmt(T,i)==A){
			G+=1;
		}
		else if (GetElmt(T,i)<A){
			M+=1;
		}
	}
	if((R==N)||((R>0)&&(G>0)&&(M==0))){
		printf("Array monotonik tidak mengecil\n");
	}
	else if ((M==N)||(R>0)&&(G>0)&&(M==0)){
		printf("Array monotonik tidak membesar\n");
	}
	else if (G==N){
		printf("Array monotonik statik\n");
	}
	else 
	printf("Array tidak monotonik\n");
	return 0;
}
