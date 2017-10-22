#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int pinArray[5000];
	int dataClient[5000];

	int randPin = 0;
	int pinCode = 0;
	int lenghtArray = 5000;
	int menuAtm = 0;
	int refillCash = 0;
	int inputCash = 0;
	char clearData;
	const int ADMIN_PASS = 8888;

	srand(time(NULL));

	//zero the array's:pin codes and client data
	for (int i = 0; i < lenghtArray; i++){
		pinArray[i] = 0;
		dataClient[i] = 0;
    }
	pinArray[0] = ADMIN_PASS;

	//writing pins to an array
	for (int i = 1; i < lenghtArray; i++){
		randPin = rand()%8999;
		pinArray[i] = 1000 + randPin;
	}

 	//writing balance to an array
	for (int i = 0; i < lenghtArray; i++){
		dataClient[i] = (555 + i) * 2;
	}

	for(;;){
		for(int i = 0; i < 3; i++){
            		printf("\nInput pin:\n");
            		scanf("%d",&pinCode);
		    if ((pinCode < 1000)||(pinCode > 10000)){
			printf("Wrong pin!");
			continue;
		    }
		    if (pinCode == ADMIN_PASS){
			printf("\nHi, ADMIN\n");
			printf("Your ~Balance~: %d\n\n",dataClient[0]);
			printf("1: Balance\n");
			printf("2: Cash money\n");
			printf("3: Refill\n");
			printf("4: Zero data client\n");
			printf("5: View all accounts\n");
			printf("6: View all pins\n");
			scanf("%d",&menuAtm);
			break;
		    } else {
			printf("1: Balance\n");
			printf("2: Cash money\n");
			printf("3: Refill\n");
			scanf("%d",&menuAtm);
			break;
			}
        	}
		switch(menuAtm){
			case 1: for (int i = 0; i < lenghtArray; i++){
					if (pinCode == pinArray[i]){
						printf("\nBalans: %d\n",dataClient[i]);
					}
				}
				break;
			case 2: printf("\nHow much to withdraw money?\n");
				scanf("%d",&inputCash);
				for (int i = 0; i < lenghtArray; i++){
                        		if (dataClient[i] > 0){
                            			if (pinCode == pinArray[i]){
                                			dataClient[i] = dataClient[i] - inputCash;
						}
                        		}else {
                            			printf("No money on the account!!!");
                            			break;
                            			}
                    		}
				break;
			case 3: printf("\nEnter the amount of the replenishment:\n");
				for (int i = 0; i < lenghtArray; i++){
					if (pinCode == pinArray[i]){
                            			printf("Your balans: %d\n",dataClient[i]);
					}
				}
				scanf("%d",&refillCash);
				for (int i = 0; i < lenghtArray; i++){
					if (pinCode == pinArray[i]){
                            			dataClient[i] = dataClient[i] + refillCash;
					}
				}
				break;
			case 4:	printf("\n***Do I clear all accounts??? Are you sure???***\n");
				printf("\t\t***Y or N***\n");
				getchar();
				scanf(" %c",&clearData);
				if ((clearData == 'Y') || (clearData == 'y')){
					for (int i = 1; i < lenghtArray; i++){
						dataClient[0] += dataClient[i]; // all money for ADMIN :)
						dataClient[i] = 0;
					}
					printf("Balance ADMIN: %d\n",dataClient[0]);
					for(int i = 1; i < lenghtArray; i++){
                            			printf("%d: ",dataClient[i]);
                        		}
				}
				break;
			case 5:	printf("\n***View ALL accounts (y/n)???***\n");
				getchar();
				scanf(" %c",&clearData);
				if ((clearData == 'Y') || (clearData == 'y')){
					printf("Balance ADMIN: %d\n",dataClient[0]);
					for (int i = 1; i < lenghtArray; i++){
						printf("%d|",dataClient[i]);
					}
				}
				break;
			case 6:	printf("\n***View ALL pins (y/n)???***\n");
				getchar();
				scanf(" %c",&clearData);
				if ((clearData == 'Y') || (clearData == 'y')){
					printf("Pin ADMIN: %d\n",pinArray[0]);
					for (int i = 1; i < lenghtArray; i++){
						printf("%d|",pinArray[i]);
					}
				}
				break;
		   default: printf("\n\tWrong choose!\n");
			    break;
		}
	}
	return 0;
}
