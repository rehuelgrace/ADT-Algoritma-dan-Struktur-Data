#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"
#include "boolean.h"

int main(){
	int N, i, idPacket, detik, isi, ctr;
	infotype tmp, e;
	Queue packet;
	boolean sort;
	detik=1;
	i=1;
	ctr=1;
	scanf("%d\n", &N);
	CreateEmpty(&packet,N);
	if (N>0){
		while(i<=N){
			sort = true;
			scanf("%d %d", &idPacket, &isi);
			Prio(tmp)=idPacket;
			Info(tmp)=isi;
			Add(&packet,tmp);
			while(sort==true && !IsEmpty(packet)){
				if(ctr==Prio(InfoHead(packet))){
					Del(&packet, &e);
					printf("%d %d\n", Info(e), detik);
					ctr++;
				}
				else sort=false;
			}
			detik++;
			i++;
		}
	}
	DeAlokasi(&packet);
	return 0;
}

