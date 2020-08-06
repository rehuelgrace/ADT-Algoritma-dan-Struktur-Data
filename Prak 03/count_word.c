#include <stdio.h>
#include "mesin_kar.h"
int main()
{
	int count;
	char filename[999];
	char CC1='!';
	char CC2='@';
	scanf("%s", &filename);
	START (filename);
	count=0;
	while (!IsEOP())
	{
		if(CC1=='d' && CC2=='o' && CC=='r'){
			count+=1;
		}
		CC1=CC2;
		CC2=CC;
		ADV();
	}
	printf("%d\n", count);
	return 0;
}