#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_STRING 1000000
#define ENGLISH_ALPHABET 26

char* getString (char* enterString){
    enterString = (char*) malloc(SIZE_STRING * sizeof(char));
    printf("\nInput the string:\n");
    fflush(stdin);
    gets(enterString);

    //checking for an empty string
    if (enterString[0] == '\0'){
        printf("String is't input!\n");
    }
    return enterString;
}

void encryptString (char enteredString[], char key[]){
    char lenghtString = strlen(enteredString);
    char lenghtKey = strlen(key);

    for (int i = 0, n = 0, j = lenghtString; i < j; i++, n++){
		if (n >= lenghtKey){
        	n = n % lenghtKey;
        }
        if (enteredString[i] >= 97 && enteredString[i] <= 122){
        	enteredString[i] = (enteredString[i] + key[n]);
		}
        if(enteredString[i] >= 65 && enteredString[i] <= 90){
        	enteredString[i] = (enteredString[i] + key[n]);
		}
        if (((enteredString[i] >= 97 && enteredString[i] <= 122) || (enteredString[i] >= 65 && enteredString[i] <= 90)) == 0){
        	enteredString[i] = enteredString[i] - 26 ;
    	}
	}
	printf("\nYou encryption string: %s\n", enteredString);
}

void decryptString(char enteredString[] ,char key[]){
    char lenghtString = strlen(enteredString);
    char lenghtKey = strlen(key);

	for (int i = 0,n = 0, j = lenghtString; i < j  ; i++, n++){
    	if(n >= lenghtKey){
        	n = n % lenghtKey;
        }
        if ((enteredString[i] >= 97 && enteredString[i] <= 122) || (enteredString[i] >= 65 && (enteredString[i] <= 90))){
    		enteredString[i] = enteredString[i] - key[n];
         }
        if (((enteredString[i] >= 97 && enteredString[i] <= 122) || (enteredString[i] >= 65 && enteredString[i] <= 90)) == 0){
        	enteredString[i] = enteredString[i] + 26 ;
        }
	}
	printf("You decryption string: %s\n",enteredString);
}

void key (char key []){
    char lenghtKey = strlen(key);
	for(int i = 0; i < lenghtKey; i++){
    	if(strlwr(key)){
        	key[i] = key[i] - 64;
        }
        else{
        	key[i] = key[i] - 96;
    	}
	}
}

int main(int argc, char* argv[])
{
	char* inputString;
	char keyForString[ENGLISH_ALPHABET];
	int j = 0;
	char cryptKey;

	for (int i = 0, j = strlen(keyForString); i < j ; i++){
	   keyForString[i] = 0;
	}
	inputString = getString(inputString);
	printf("\nInput crypt key:\n");
	gets(keyForString);
	key(keyForString);
	if (!strcmp (argv[1], "-e")){
        encryptString(inputString,keyForString);
    }
    if (!strcmp (argv[1], "-d")){
        decryptString(inputString, keyForString);
    }
	free(inputString);
}
