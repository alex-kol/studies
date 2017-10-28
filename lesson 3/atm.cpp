//emulator ATM. admin pass 8888
#include <stdio.h>
#include <stdlib.h>

const int ADMIN_PASS = 8888;
const int START_ARRAY = 0;
const int LENGHT_ARRAY = 5000;
const int START_PIN = 1000;
const int START_CLIENT_BALANCE = 555;
const int MAX_INPUT_PINS = 3;
const int MAX_PIN_CODE = 9999;
const int MIN_PIN_CODE = 1000;
const int MENU_ATM_ONE = 1;
const int MENU_ATM_TWO = 2;
const int MENU_ATM_THREE = 3;
const int MENU_ATM_FOUR = 4;
const int MENU_ATM_FIVE = 5;
const int MENU_ATM_SIX = 6;
const int PLUS_BALANCE = 0;

int main()
{
	int pinArray[5000];
	int clientData[5000];
	int pinCode = 0;
	int menuAtm = 0;
	int refillCash = 0;
	int inputCash = 0;
	char clearData;

	//zero the array's:pin codes and client data
	for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
		pinArray[i] = 0;
		clientData[i] = 0;
    }
	pinArray[0] = ADMIN_PASS;

	//writing pins to an array
	for (int i = START_ARRAY + 1; i < LENGHT_ARRAY; i++){
		pinArray[i] = START_PIN + i;
	}

 	//writing balance to an array
	for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
		clientData[i] = (START_CLIENT_BALANCE + i) * 2;
	}

	for(;;){
        for(int i = START_ARRAY; i < MAX_INPUT_PINS; i++){
            printf("\nInput pin:\n");
            scanf("%d",&pinCode);
            if ((pinCode < MIN_PIN_CODE)||(pinCode > MAX_PIN_CODE)){
                printf("\t---> Wrong pin! <---");
                continue;
            }
            if (pinCode == ADMIN_PASS){
                printf("\nHi, ADMIN\n");
                printf("Your ~Balance~: %d\n\n",clientData[0]);
                printf("1: Balance\n");
                printf("2: Cash money\n");
                printf("3: Refill\n");
                printf("4: Zero data client\n");
                printf("5: View all accounts\n");
                printf("6: View all pins\n");
                scanf("%d",&menuAtm);
                switch(menuAtm){
                    case MENU_ATM_FOUR:     printf("\n***Do I clear all accounts??? Are you sure???***\n");
                                            printf("\t\t***Y or N***\n");
                                            getchar();
                                            scanf(" %c",&clearData);
                                            if ((clearData == 'Y') || (clearData == 'y')){
                                                for (int i = START_ARRAY + 1; i < LENGHT_ARRAY; i++){
                                                    clientData[i] = 0;
                                                }
                                                printf("Balance ADMIN: %d\n",clientData[0]);
                                                for(int i = START_ARRAY + 1; i < LENGHT_ARRAY; i++){
                                                    printf("%d|",clientData[i]);
                                                }
                                            }
                                            break;
                    case MENU_ATM_FIVE:	    printf("\n***View ALL accounts (y/n)???***\n");
                                            getchar();
                                            scanf(" %c",&clearData);
                                            if ((clearData == 'Y') || (clearData == 'y')){
                                                printf("Balance ADMIN: %d\nBalance clients: ",clientData[0]);
                                                for (int i = START_ARRAY + 1; i < LENGHT_ARRAY; i++){
                                                    printf("%d|",clientData[i]);
                                                }
                                            }
                                            break;
                    case MENU_ATM_SIX:	    printf("\n***View ALL pins (y/n)???***\n");
                                            getchar();
                                            scanf(" %c",&clearData);
                                            if ((clearData == 'Y') || (clearData == 'y')){
                                                printf("Pin ADMIN: %d\nPins clients: ",pinArray[0]);
                                                for (int i = START_ARRAY + 1; i < LENGHT_ARRAY; i++){
                                                    printf("%d|",pinArray[i]);
                                                }
                                            }
                                            break;
                    default:    break;
                }
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
            case MENU_ATM_ONE:      for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
                                        if (pinCode == pinArray[i]){
                                            printf("\nBalans: %d\n",clientData[i]);
                                        }
                                    }
                                    break;
            case MENU_ATM_TWO:      printf("\nHow much to withdraw money?\n");
                                    scanf("%d",&inputCash);
                                    for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
                                        if (clientData[i] > PLUS_BALANCE){
                                            if (pinCode == pinArray[i]){
                                                clientData[i] = clientData[i] - inputCash;
                                            }
                                        }else {
                                            printf("\t-->No money on the account!!!<--");
                                            break;
                                            }
                                    }
                                    break;
            case MENU_ATM_THREE:    printf("\nEnter the amount of the replenishment:\n");
                                    for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
                                        if (pinCode == pinArray[i]){
                                               printf("Your balans: %d\n",clientData[i]);
                                        }
                                    }
                                    scanf("%d",&refillCash);
                                    for (int i = START_ARRAY; i < LENGHT_ARRAY; i++){
                                        if (pinCode == pinArray[i]){
                                               clientData[i] = clientData[i] + refillCash;
                                        }
                                    }
                                    break;

			default:    break;
		}
	}
	return 0;
}
