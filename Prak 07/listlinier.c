/* 	NIM/Nama 	: 18218006/Rehuel Grace Marbun
	Topik	 	: ADT List Linear
	Deskripsi 	: Implementasi dari ADT List Linear dengan representasi fisik pointer pada listlinear.h */

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L)==Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L)=Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }

}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    // KAMUS LOKAL
    address P;
    boolean Found;

    // ALGORITMA
    P = First(L);
    Found = false;

    while ((P != Nil) && (!Found))
    {
        if (Info(P) == X)
        {
            Found = true;
        }
        else
        {
            P = Next(P);
        }
    }

    return P;

}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    // KAMUS LOKAL
    address P,Last;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil)
    {
        if (IsEmpty(*L))
        {
            Next(P) = First(*L);
            First(*L) = P;
        }
        else
        {
            Last = First(*L);
            while (Next(Last) != Nil)
            {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = First(*L);
    First(*L) = Next(P);
    Next(P) = Nil;
    *X = Info(P);

    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    // KAMUS LOKAL
    address Prec,Last;

    // ALGORITMA
    Prec = Nil;
    Last = First(*L);

    while (Next(Last) != Nil)
    {
        Prec = Last;
        Last = Next(Last);
    }
    *X = Info(Last);

    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Prec) = Nil;
    }
    Dealokasi(&Last);

}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    // KAMUS LOKAL
    address Last;

    // ALGORITMA
    if (IsEmpty(*L))
    {
		InsertFirst(L,P);
	}
	else
    {
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        Next(P) = Nil;
        Next(Last) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    if (Next(*P) == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    // KAMUS LOKAL
    address P,Prec;

    // ALGORITMA
    P = Search(*L,X);
    if (P != Nil)
    {
        if(P == First(*L))
        {
            DelFirst(L,&P);
            P = Nil;
        }
        else
        {
            Prec = First(*L);
            while (Next(Prec) != P)
            {
                Prec = Next(Prec);
            }
            Next(Prec) = Next(P);
            P = Nil;
        }

        Dealokasi(&P);
    }

}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    // KAMUS LOKAL
    address Prec,Last;

    // ALGORITMA
    Prec = Nil;
    Last = First(*L);

    while(Next(Last) != Nil)
    {
        Prec = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Prec) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    printf("[");

    if (!IsEmpty(L))
    {
        P = First(L);
        while (Next(P) != Nil)
        {
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }

    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    // KAMUS LOKAL
    address P;
    int Count;

    // ALGORITMA
    P = First(L);
    Count = 0;
    while (P != Nil)
    {
        Count++;
        P = Next(P);
    }

    return Count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    // KAMUUS LOKAL
    address P;
    infotype max;

    // ALGORITMA
    P = Next(First(L));
    max = Info(First(L));
    while (P != Nil)
    {
        if (max < Info(P))
        {
            max = Info(P);
        }
        P = Next(P);
    }

    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
	address max=First(L);
	address C=First(L);
	while (C!=Nil){
		if(Info(C)>Info(max)){
			max=C;
		}
		C=Next(C);
	}
	return max;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
	return Info(AdrMin(L));
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
	address min=First(L);
	address C=First(L);
	while (C!=Nil){
		if(Info(C)<Info(min)){
			min=C;
		}
		C=Next(C);
	}
	return min;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
	float jumlah=0;
	int count=0;
	address C=First(L);
	while (C!=Nil){
		jumlah+=Info(C);
		count+=1;
		C=Next(C);
	}
	return(jumlah/count);
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void Konkat1 (List *L1, List *L2, List *L3){
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    CreateEmpty(L3);

    while (!IsEmpty(*L1))
    {
        DelFirst(L1,&P);
        InsertLast(L3,P);
    }
    while (!IsEmpty(*L2))
    {
        DelFirst(L2,&P);
        InsertLast(L3,P);
    }
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void InversList (List *L){
    address P,Q, C;
    C=First(*L);
    P=First(*L);
    Q=Next(P);
    while (Q!=Nil){
        P=Q;
        Q=Next(Q);
        
        P;
        InsertFirst(L,P);
        Next(C)=0;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void SortList(List *L){
    address max, Q, First;
    First = First(*L);
    max = First(*L);
    Q = Next(*L);
    while (Q != Nil) {
        if (max <= Q) {
            InsertAfter(L,Q,max);
            max = Q;
            Q = Next(Q);
        }
        InsertFirst(L,Q);
        Next(First) = 0;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list terurut naik : */
/* Elemen kedua > Elemen pertama*/