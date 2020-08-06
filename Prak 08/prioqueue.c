/* Rehuel Grace Marbun - 18218006 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueue.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
     /* Algoritma */
    (*P) = (ElmtQueue *) malloc (sizeof (ElmtQueue));
    if ((*P) != NULL) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
    else {
        (*P) = Nil;
    }
}
void Dealokasi (address P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
    free(P);
}
boolean IsEmpty (PrioQueue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
    return (Head(Q) == Nil);
}
int NbElmt(PrioQueue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
   		/* Kamus Lokal */
		address P=Head(Q);
		int count=0;
		/* Algoritma */
		if (IsEmpty(Q)) {
			return 0;
		}
		else {
		while (P != Nil) {
            count += 1;
            P = Next(P);
        }
        return count;
		}
}
/*** Kreator ***/
void CreateEmpty(PrioQueue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
    Head(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void Add (PrioQueue * Q, infotype X){
/* Proses: Mengalokasi X dan menambahkan X aw==
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi elemen list dengan urutan yang sesuai */
	 address P, LastP, PrevP;
	 boolean found;
	 int waktu;

    Alokasi(&P, X);
    if (P != Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
        }else{
			LastP = Head(*Q);
			found = false;
			waktu = Info(LastP).dLayanan;
			while ((LastP != Nil) && (!(found))){
				if ((waktu - Info(P).tKedatangan) > 0){
					if (Next(LastP) == Nil){
						Next(LastP) = P;
					}else{
						PrevP = LastP;
						LastP = Next(LastP);
						if (Info(P).dLayanan < Info(LastP).dLayanan){
							Next(PrevP) = P;
							Next(P) = LastP;
						}else{
							Next(LastP) = P;
						}
					}
					found = true;
				}else{
					if (Next(LastP) == Nil){
						Next(LastP) = P;
						found = true;
					}else{
					LastP = Next(LastP);
					waktu += Info(LastP).tKedatangan;
					}
				}
			}
		}
    }
}
void Del(PrioQueue * Q, infotype * X){
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = Head(*Q);
    Head(*Q) = Next(Head(*Q));
    Next(P) = Nil;
    (*X) = Info(P);
    Dealokasi(P);
}
