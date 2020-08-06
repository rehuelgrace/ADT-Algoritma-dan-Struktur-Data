#include <stdio.h>
#include "mesin_kar.h"
int main()
{
	char filename[999];
	char CC1='?';
	//char cc2=' ';
	int count=0;
	scanf("%s", filename);
	START(filename);
	while (!IsEOP())
	{
		if((CC1=='L')&&(CC=='E')){
			count+=1;
		}
		// cc2 = cc1;
		CC1 = CC;
		ADV();
	}
	printf("%d", count);
	return 0;
}
