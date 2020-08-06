/* File: stack.c */
/* Nama/NIM: Rehuel Grace/18218006 */
/* Topik: stack */

#include "boolean.h"
#include "stack.h"


/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
	(*S).TOP=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S){
	return (S.TOP==Nil);
}
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsFull(Stack S){
	return (S.TOP==(MaxEl));
}
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
	(*S).TOP++;
	(*S).T[(*S).TOP]=X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infotype *X){
	(*X)=(*S).T[(*S).TOP];
	(*S).TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
