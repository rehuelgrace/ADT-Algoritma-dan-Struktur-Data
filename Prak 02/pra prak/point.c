/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

/*Nama	: Rehuel Grace Marbun */
/*NIM	: 18218006*/

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

typedef struct { 
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT P;
		P.X = X;
		P.Y = Y;
return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	float X,Y;
	scanf("%f",&X);
	scanf("%f",&Y);
	*P=MakePOINT(X,Y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
	printf("(%.2f,%.2f)",P.X,P.Y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return ((P1.X==P2.X)&&(P1.Y==P2.Y));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	return ((P1.X!=P2.X) || (P1.Y!=P2.Y));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
	return ((P.X==0)&&(P.Y==0));
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return (P.Y==0) ;
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return (P.X==0);
}

int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
	if((P.X>0)&&(P.Y>0)){
	return 1;}
	else if ((P.X>0)&&(P.Y<0)){
	return 4;}
	else if ((P.X<0)&&(P.Y<0)){
	return 3;}
	else
	return 2;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	P.X=P.X + deltaX;
	P.Y=P.Y + deltaY;
	return P;
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    (*P).X+=deltaX;
    (*P).Y+=deltaY;
}

float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	float jar;
	P.X=P.X*P.X;
	P.Y=P.Y*P.Y;
	jar=P.X+P.Y;
	jar=sqrt(jar);
	return jar;
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
	float pj;
	POINT P;
	
	P.X=P2.X-P1.X;
	P.Y=P2.Y-P1.Y;
	P.X*=P.X;
	P.Y*=P.Y;
	pj=P.X+P.Y;
	pj=sqrt(pj);
	return pj;
}

#endif
