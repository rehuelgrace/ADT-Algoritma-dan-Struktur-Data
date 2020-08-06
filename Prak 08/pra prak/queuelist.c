/* File : queuelist.h */
/* Nama/NIM: Rehuel Grace/18218006 */
/* Deskripsi: queue dengan list */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#include "queuelist.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
	(*P) = (ElmtQueue *) malloc (sizeof (ElmtQueue));
    if ((*P) != NULL) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
    else {
        (*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q){
	return((Head(Q)==Nil)&&(Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
	/* Kamus Lokal */
	/* Kamus Lokal */
    address P=Head(Q);
    int count=0;
    /* Algoritma */
    if (IsEmpty(Q)) {
        return 0;
    }
    else {
        count = 1;
        while (P != Tail(Q)) {
            count += 1;
            P = Next(P);
        }
        return count;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X){
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
		}
			Tail(*Q) = P;
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adSSalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Del(Queue * Q, infotype * X){
	/* Kamus Lokal */
    address P;
    /* Algoritma */
    *X = InfoHead(*Q);
    P = Head(*Q);
    Head(*Q) = Next(Head(*Q));
    if (Head(*Q) == Nil) {
        Tail(*Q) = Nil;
    }
    Next(P) = Nil;
    Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
