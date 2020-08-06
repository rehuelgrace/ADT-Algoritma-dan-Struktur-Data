#include <stdio.h>
#include "mesinkar.h"
#include "mesin_kata.h"
#include <stdlib.h>

/* Kamus */
boolean EndKata;
Kata CKata;

//{ ***** Primitif-Primitif Mesin Kata ***** }
void Ignore_Blank()
{
	while ((CC==BLANK)&&(CC != MARK)){
		ADV();
	}
}
/*{ Mengabaikan satu atau beberapa BLANK }
{ I.S. : CC sembarang }
{ F.S. : CC ? BLANK atau CC = MARK }*/
void STARTKATA(char* filename)
{
	char file[999];
	START(file);
	Ignore_Blank();
	if (CC == MARK){
		EndKata=true;
	} else {
		EndKata=false;
		SalinKata();
	}
}
/*{ I.S. : CC sembarang, filename merupakan string nama file pita kata yang akan dibaca }
{ F.S. : EndKata = true, dan CC = Mark; }
{        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
         CC karakter pertama sesudah karakter terakhir kata }*/
void ADVKATA()
{
	Ignore_Blank();
	if (IsEOP()){
		EndKata=true;
	} else SalinKata();
}
/*{ I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
         dari kata yg sudah diakuisisi }
{ F.S. : Jika CC = MARK, maka EndKata = true
         atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
         CC karakter pertama sesudah karakter terakhir kata }*/
void SalinKata()
{
	int i=1;
	while((CC != MARK) && (CC != BLANK)){
		CKata.TabKata[i]=CC;
		ADV();
		i++;
	}
	CKata.Length=(i-1);
}
/*{ Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
         NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
         karakter sesudah karakter terakhir yang diakuisisi }*/
