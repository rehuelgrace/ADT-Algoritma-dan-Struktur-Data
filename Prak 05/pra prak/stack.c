//Nama				: Rehuel Grace Marbun
//NIM				: 18218006
//Topik				: Stack

#include <stdio.h>
#include "stack.h"
void CreateEmpty(Stack *S){
	(*S).TOP = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S){
	return(S.TOP==Nil);
}
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsFull(Stack S){
	return(S.TOP==MaxEl);
}
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
	(*S).TOP++;
	(*S).T[(*S).TOP-1]=X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infotype *X){
	(*X)=(*S).T[(*S).TOP-1];
	(*S).TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
