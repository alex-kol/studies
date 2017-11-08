//counting words in a string
#include <stdio.h>
#include <malloc.h>

#define SIZE_STRING 1000000

const int START_ARRAY = 0;

int searchWords (char* inputString){
    int wordCount = 0;
    int flag = 0;
    for (int i = START_ARRAY; inputString[i] != '\0'; i++){
        if ((inputString[i] >= 'a' && inputString[i] <= 'z') || (inputString[i] >= 'A' && inputString[i] <= 'Z')){
            if (inputString[i] != ' ' && flag == 0) {
                wordCount += 1;
                flag = 1;
            }
        } else {
            if (inputString[i] == ' '){
                flag = 0;
            }
        }
    }
   return wordCount;
}

int main ()
{
    char* inputString;

    inputString = (char*) malloc(SIZE_STRING * sizeof(char));
    printf("Input the string:\n\n");
    gets(inputString);
    printf("\nWords in the input string: [%d]\n", searchWords(inputString));
    free(inputString);
    return 0;
}
