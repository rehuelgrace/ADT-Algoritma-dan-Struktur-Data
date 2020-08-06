//NAMA		:	REHUEL GRACE MARBUN
//NIM		:	18218006

#include "mesin_kar.h"
#include <stdio.h>
#include "boolean.h"

char CC;
boolean EOP;
static FILE *pita;


void START(char* filename)

{
	//pita = stdin;
    pita = fopen("pitakar.txt","r");
    ADV();
}
void ADV()

{
	static int retval;
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC==MARK);
	if (EOP) {
		fclose(pita);
	}
}

char GetCC()

{
	return(CC);
}

boolean IsEOP()

{
	return (CC==MARK);
}
