/* File : queue.c */
/* circular buffer dinamik array eksplisit*/
// Nama			: Rehuel grace marbun
// NIM			: 18218006

#include "boolean.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return ((Head (Q)==Nil) && (Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	return (NBElmt(Q)==MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q){
	if (IsEmpty(Q)){
		return 0;
	} else
	return (Tail(Q)-Head(Q))%MaxEl(Q)+1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
	(*Q).T=(infotype*)malloc((Max+1)*sizeof(infotype));
	if ((*Q).T!=NULL){
		MaxEl(*Q)=Max;
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else /*alokasi gagal*/
	MaxEl(*Q)=0;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	MaxEl(*Q)=0;
	free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
	if (IsEmpty(*Q)){
		Head(*Q)=1;
	}
	Tail(*Q)=Tail(*Q)%MaxEl(*Q) +1;
	InfoTail(*Q)=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
	*X = InfoHead(*Q);
	if(NBElmt(*Q)==1){
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else
		Head(*Q)=Head(*Q)%MaxEl(*Q)+1;
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
