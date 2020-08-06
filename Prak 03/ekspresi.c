#include <stdio.h>
#include "mesin_kata.h"
#include "boolean.h"

void GetOperan (int &operan){
	operan = 0;
	while (IsOperan(CC)) {
		operan = operan * 10 + KarakterToInteger(CC);
		ADV()
	}
}

boolean IsOperan (char CC){
	return ((CC == '0') || (CC == '1') || (CC == '2') || (CC == '3') || (CC == '4') || (CC == '5') || (CC == '6') || (CC == '7') || (CC == '8') || (CC == '9'))
}

int KarakterToInteger (char x){
	int integer;
	switch (x) {
		case '0' : hasil = 0; break;
		case '1' : hasil = 1; break;
		case '2' : hasil = 2; break;
		case '3' : hasil = 3; break;
		case '4' : hasil = 4; break;
		case '5' : hasil = 5; break;
		case '6' : hasil = 6; break;
		case '7' : hasil = 7; break;
		case '8' : hasil = 8; break;
		case '9' : hasil = 9; break;
		default : hasil = -999; break;
	}
	return hasil;
}

int main(){
	char filename [999];
	int operan1, operan2;
	char operator;
	scanf("%s", filename);
	STARTKATA(filename);
	while (!EndKata) {
		if (IsOperan()) {
			GetOperan(operan1);
			ADVKATA();
			GetOperan(operan2);
		} else { //not IsOperan
			printf("%d %c %d\n",operan1,operator,operan2);
	    	switch(operator) {
    	 		case '*' : 
      					operan1*=operan2;
      					break;
      			case '/' : 
      					operan1/=operan2;
      					break;
      			case '+' : 
      					operan1+=operan2;
      					break;
      			case '-' : 
      					operan1-=operan2;
			}
		}
		ADVKATA();
		printf
	}
	// Ignore_Blank();
	// GetOperan(operan1);
	// Ignore_Blank();
	// GetOperan(operan2);
	// Ignore_Blank();

	// while (!(IsEOP())){
	// 	if (CC=='e'){
	// 		count+=1;
	// 	}
	// 	ADV();
	// }
	// printf("%d\n", count);
	return 0;
}
