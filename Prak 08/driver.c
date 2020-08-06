/* File : driverprioqueue.c */
/* Representasi priority queue dengan list berkait dengan first (HEAD) sebagai alamat penghapusan elemen */
/* Queue terurut mengecil berdasarkan elemen dLayanan */
/* Jika dLayanan sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#include "prioqueue.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	PrioQueue Q;
	CreateEmpty(&Q);

	int i, n;
	scanf("%d", &n);

	if(n != 0) {
		// Add infotypes to Queue
		for(i=0; i<n; i++) {
			infotype X;
			scanf("%d %d %d", &X.tKedatangan, &X.id, &X.dLayanan);
			Add(&Q, X);
		}

		// Iterate Queue
		int t = 1;
		int dt = 0;

		while(!IsEmpty(Q)) {
			if(InfoHead(Q).tKedatangan > t) {
				dt = InfoHead(Q).tKedatangan - t;
			}
			infotype X;
			Del(&Q, &X);
			printf("%d %d %d\n", t + dt, X.id, t - X.tKedatangan + dt);
			t = t + X.dLayanan;
		}
	} else {
		printf("Tidak ada layanan\n");
	}
	return 0;
}