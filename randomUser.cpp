#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
	int numUser=0;
	int randNum=0;
	int selectUser;
	
	srand(time(NULL));
	randNum=rand()%10;
	do {
		for(int i=0;i<3;i++){
			for (;;){
				printf("Guess the positive number from 0 to 10: \n");
				scanf("%d",&numUser);
				if (numUser<0){
					printf("\nIt's NEGATIVE: \n");	
					continue;
				}
				break;
			}
			if (numUser>randNum){
				printf("\nSmaller!\n");
			}
			if (numUser<randNum){
				printf("\nBigger!\n");
			}
			if (numUser==randNum){
				printf("\nYou WIN!!!\n");
				break;
			}
			} 
			printf("Continue games: Yes-1 or No-0:\n");
			scanf("%d",&selectUser);
			randNum=0;
			randNum=rand()%10;
			system("cls");
	} while (selectUser==1);
	return 0;
}
