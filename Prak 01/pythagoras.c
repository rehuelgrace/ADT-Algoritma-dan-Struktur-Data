//NIM				: Rehuel Grace M
//Nama				: 18218006
//Tanggal			: 18 September 2019
//Topik praktikum	: Pengenalan C
//Deskripsi			: Memeriksa apakah ABC merupakan segitiga

/* Program Pythagoras */

/* Input: 3 integer: A, B, C */

/* Output: Pernyataan apakah A, B, dan C membentuk segitiga dan siku-siku */

#include <stdio.h>

/* PROCEDURE DAN FUNCTION */

int Square(int a){
	return (a*a);
}
/* Menghasilkan pangkat dua dari a */

int Max (int a, int b, int c){
	if(a>b && a>c){
		return (a);
	}
	else if (b>c && b>a){
		return (b);
	}
	else if (c>a && c>b){
		return (c);
	}
}
/* menghasilkan nilai terbesar di antara a, b, c */



void CekSegitiga(int a, int b, int c){
	if((a<(b+c)) && (b<(a+c)) && (c<(a+b))) {
		printf("SEGITIGA\n");
		CekSikuSiku(a,b,c);
	}
	else {
		printf("BUKAN SEGITIGA\n");
	}
}
/* I.S. : a, b, dan c terdefinisi

   F.S. : Jika a, b, dan c tidak membentuk segitiga, tertulis di layar: BUKAN SEGITIGA

          Jika a, b, dan c membentuk segitiga, tertulis di layar: SEGITIGA, dan mengecek apakah a, b, dan c membentuk segitiga siku-siku */

void CekSikuSiku(int a, int b, int c){
	if(((Max(a,b,c)==a) || (Max(a,b,c)==b) || (Max(a,b,c)==c))&&(((Square(a)+Square(b))==Square(c)) || ((Square(a)+Square(c))==Square(b)) || (((Square(b)+Square(c))==Square(a)))))  
	{
		printf("SEGITIGA SIKU-SIKU\n");
	}
	else {
		printf("BUKAN SEGITIGA SIKU-SIKU\n");
	}
}
/* I.S. : a, b, dan c terdefinisi dengan c adalah bilangan paling besar dan a, b, dan c membentuk segitiga

   F.S. : Jika a, b, dan c membentuk segitiga siku-siku, tertulis di layar: SEGITIGA SIKU-SIKU,

          Jika a, b, dan c tidak membentuk segitiga siku-siku, tertulis di layar: BUKAN SEGITIGA SIKU-SIKU */

       
/* PROGRAM UTAMA */

int main () {

       /* KAMUS */

       int A, B, C;

 

       /* ALGORITMA */

       /* Input */

       scanf("%d", &A);

       scanf("%d", &B);

       scanf("%d", &C);

      

       /* Mengecek apakah A, B, dan C segitiga */

       CekSegitiga(A, B, C);

      

       return 0;

}
