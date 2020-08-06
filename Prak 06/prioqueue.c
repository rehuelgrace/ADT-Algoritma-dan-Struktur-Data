/*	NIM:18218006
    Nama: Rehuel grace
    Topik praktikum : ADT Queue
    Deskripsi: Program priority queue	*/


#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
{
    return Head(Q)==Nil && Tail(Q)==Nil;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q)
{
    return  NBElmt(Q)==MaxEl(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q)
{
    if(IsEmpty(Q)) return 0;
    else return ((Tail(Q)-Head(Q))%MaxEl(Q))+1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
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
void DeAlokasi(Queue * Q)
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
{
	boolean found = true;
	if(IsEmpty(*Q))
	{
		Head(*Q)=1;
	}
    	Tail(*Q)=(Tail(*Q)%MaxEl(*Q)) +1;
    	
    	Elmt(*Q,Tail(*Q))=X;
    	address i=Tail(*Q);
  		address next=Tail(*Q);
  		infotype temp;
    	while(found && i!=Head(*Q))
    	{
      		if(next-1==0)
    		{
				next=MaxEl(*Q);
    		}
    		else next--;

    		//printf("%d\n", next);
    		//printf("---%d %c---\n", Prio(Elmt(*Q,next)), Info(Elmt(*Q,next)));
    		if(Prio(Elmt(*Q,next))<Prio(Elmt(*Q,i)))
    		{
				temp = Elmt(*Q,i);
				Elmt(*Q,i)=Elmt(*Q,next);
				Elmt(*Q,next)=temp;
    		}
    		else {found = false;}
    		i=next;
    		}
    	}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (Queue * Q, infotype * X)
{
    *X = InfoHead(*Q);
	if(NBElmt(*Q)==1){
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else
		Head(*Q)=(Head(*Q)%MaxEl(*Q))+1;
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintQueue (Queue Q)
{
	infotype tmp;
	while(!IsEmpty(Q))
	{
		printf("%d %d\n", Prio(InfoHead(Q)), Info(InfoHead(Q)));
		Del(&Q, &tmp);
	}
	printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
