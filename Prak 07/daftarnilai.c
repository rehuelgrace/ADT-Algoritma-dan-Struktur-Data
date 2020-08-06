/* 	NIM/Nama 	: 18218006/Rehuel Grace Marbun
	Topik	 	: ADT List Linear */


#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>

int main (){
    List L;
    int X;
    
    CreateEmpty(&L);
    do{
        scanf("%d",&X);
        if(!((X<0)||(X>100)))
            InsVFirst(&L,X);
    } while (!((X<0)||(X>100)));
    
    if(!IsEmpty(L)){
        printf("%d\n",NbElmt(L));
        printf("%d\n",Max(L));
        printf("%d\n",Min(L));
        printf("%.2f\n",Average(L));
        InversList(&L);
        PrintInfo(L);printf("\n");
        InversList(&L);
        PrintInfo(L);printf("\n");
    } else {
        printf("Daftar nilai kosong\n");
    }
    return 0;
}
