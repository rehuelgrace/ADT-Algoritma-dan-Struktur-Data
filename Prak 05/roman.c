/* File: roman.c */
/* Nama/NIM: Rehuel Grace/18218006 */
/* Topik: stack */
/* Deskripsi: mengimplementasikan fungsi pada file header roman.h */

#include "roman.h"
#include <stdio.h>

/* **** Roman Digit Operator *** */
boolean IsRomanDigit(infotype X)
/* Mengirim true jika X adalah digit romawi I, V, X, L, C, D, atau M (case sensitive) */
{
	return (X == 'I' || X == 'V' || X == 'X' || X == 'L' || X == 'C' || X == 'D' || X == 'M');
}
int RomanToDec(infotype X)
/* I.S. X adalah digit romawi yang dikenali */
/* F.S. Mengembalikan nilai desimal dari X */
{
	/* KAMUS */
	int decimal=0;
	/* ALGORITMA */
	if (IsRomanDigit(X)) {
		if (X == 'I') {
			decimal = 1;
		}
		else if (X == 'V') {
			decimal = 5;
		}
		else if (X == 'X') {
			decimal = 10;
		}
		else if (X == 'L') {
			decimal = 50;
		}
		else if (X == 'C') {
			decimal = 100;
		}
		else if (X == 'D') {
			decimal = 500;
		}
		else {
			decimal = 1000;
		}
	}
	return (decimal);
}
int Decimal(Stack S)
/* Mengembalikan nilai desimal dari bilangan romawi R */
/* I.S. R berisi digit-digit romawi yang dikenali dengan susunan yang benar,
        digit paling atas adalah digit terakhir */
/* F.S. Mengembalikan nilai desimal dari bilangan romawi R */
{
	/* KAMUS */
	int count, x1, x2;
	char c1, c2;
	Pop(&S, &c1);
	x1= RomanToDec(c1);
	count=x1;
	/* ALGORITMA */
	while (!IsEmpty(S)) {
		Pop(&S,&c2);
		x2 = RomanToDec(c2);
		if (x1>x2) {
			x2 = x2*(-1);
		}
		else {
			x1=x2;	
		}
		count+=x2;
	}
	return(count);
}
