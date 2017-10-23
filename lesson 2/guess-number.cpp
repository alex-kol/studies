//guess number from 0 to 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
	int numberUser = 0;
	int letterUser = 0;
	int randNumMachine = 0;
	char selectUser;

	srand(time(NULL));
	randNumMachine = rand()%10;
	for (;;){
		printf("\n***You have 3 attempts!***\n");
		for (int i = 0; i < 3; i++){
			for (;;){
				printf("\nGuess the positive number from 0 to 10:\n");
				int letterUser = scanf("%d",&numberUser);
				
				if (numberUser < 0){
					printf("No. It's a negative number!\n");
					continue;
				}
				
				if (letterUser == false){
					printf("No. It's a letter!\n");
					getchar();
					continue;
				}
				
				break;
			}
			
			if (numberUser > randNumMachine){
				printf("SMALLER!---->Attempt:%d\n",i+1);
			}
			
			if (numberUser < randNumMachine){
				printf("BIGGER!---->Attempt:%d\n",i+1);
			}
			
			if (numberUser == randNumMachine){
				printf("\nYou WIN!!!\n");
				break;
			}
		}
		printf("\n\t-=CONTINUE GAME: Y/N=-\n");
		getchar();
		scanf("%c",&selectUser);
		
		if ((selectUser == 'y')||(selectUser == 'Y')){
			randNumMachine = 0;
			randNumMachine = rand()%10;
			system("cls");
		}
		
		if ((selectUser == 'n')||(selectUser == 'N')){
 			system("cls");
			printf("\t-=GAME OVER=-");
			break;
		}
	}
	return 0;
}
