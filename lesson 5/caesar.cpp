#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 1000000
#define START_ARRAY 0
#define ENGLISH_ALPHABET 26
#define MENU_E 'e'
#define MENU_D 'd'

char* getString (char* enterString){
    enterString = (char*) malloc(SIZE_STRING * sizeof(char));
    printf("\nInput the string:\n");
    fflush(stdin);
    gets(enterString);

    //checking for an empty string
    if (enterString[0] == '\0'){
        printf("String is't input!\n");
    }

    //convert string to lowercase
    strlwr(enterString);
    return enterString;
}

char* encryptString (char* enterString, int encryptionKey, char lenghtStr){
   	for (int i = START_ARRAY; i < lenghtStr; i++){
		if ((enterString[i] >= 'a') && (enterString[i] <= 'z')){

            		//The remainder of dividing by the number of letters in the alphabet is taken in order
            		//so that when key> = 26 remove unnecessary circles of passage in alphabetical order
			enterString[i] = enterString[i] + (encryptionKey % ENGLISH_ALPHABET);

            		//If the encrypted letters has gone beyond the boundaries of the alphabet
            		//make circle and return to the begin
            		if (enterString[i] > 'z'){
				enterString[i] = 'a' + (enterString[i] - 'z') - 1;
			}
		}
    	}
	printf("\nYou encryption string: %s\n",enterString);
	return enterString;
}

char* decryptString (char* enterString, int decryptionKey, char lenghtStr){
	for (int i = START_ARRAY; i < lenghtStr; i++){
		if ((enterString[i] >= 'a') && (enterString[i] <= 'z')){
			enterString[i] = enterString[i] - (decryptionKey % ENGLISH_ALPHABET);
            		if (enterString[i] < 'a'){
				enterString[i] = 'z' - ('a' - enterString[i]) + 1;
			}
		}
    	}
	printf("\nYou decryption string: %s\n",enterString);
	return enterString;
}

int main()
{

/*    int main (int argc, char * argv[]) {
        int i;
         for (i = 0 ; i < argc; i++) {
                 printf("Argument %d: %s\n", i, argv[i]);
         }
         if(argc == 1) {
                 printf("Command line has no additional arguments\n");
         }
         return 0;
*/

    int keyForString = 0;
    char* inputString;
    char lenghtString;
    char cryptMenu;

    for(;;){
        printf("\nWhat to do with the string? Encrypt \"E\" / Decrypt \"D\"\t-=EXIT: ctrl+C=-\n");
        scanf("%c",&cryptMenu);
        printf("\nInput crypt key:\n");
        scanf("%d",&keyForString);

        inputString = getString(inputString);
        lenghtString = strlen(inputString);

        switch (cryptMenu){
            case MENU_E:    encryptString(inputString,keyForString,lenghtString);
                            break;
            case MENU_D:    decryptString(inputString,keyForString,lenghtString);
                            break;
            default:        printf("Wrong input!\n");
                            break;
        }
    }
    free(inputString);
    return 0;
}
