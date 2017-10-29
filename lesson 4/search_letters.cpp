//searching for letters in the string

#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 100000
const int START_ARRAY = 0;
const int SIZE_ALPHABET = 26;

int main()
{
    int countTemp[SIZE_ALPHABET];
    int countLetter[SIZE_ALPHABET];
    int indexArray[SIZE_ALPHABET];
    int position = 0;
    int j = 0;
    char* inputString;

    for (int i = START_ARRAY; i < SIZE_ALPHABET; i++){                 //zero's in the all array
        countTemp[i] = 0;
        countLetter[i] = 0;
        indexArray[i] = 0;
    }
    inputString = (char*) malloc(SIZE_STRING * sizeof(char));
    printf("Input the string:\n\n");
    gets(inputString);
    if (inputString[0] == '\0'){                                       //checking for an empty string
        printf("String is't input!\n");
    }
    for (int i = START_ARRAY; inputString[i] != '\0'; i++){
        if ((inputString[i] >= 'A' && inputString[i] <= 'Z')) {
            countLetter[inputString[i] - 'A']++;
            countTemp[inputString[i] - 'A']++;
        }
        if  (inputString[i] >= 'a' && inputString[i] <= 'z'){
            countLetter[inputString[i] - 'a']++;
            countTemp[inputString[i] - 'a']++;
        }
    }
    for(int i = START_ARRAY; i < SIZE_ALPHABET; i++){                 // sorting bubble
        for(int j = i + 1; j < SIZE_ALPHABET; j++){
            if(countLetter[i] < countLetter[j]){
                int temp = countLetter[i];
                countLetter[i] = countLetter[j];
                countLetter[j] = temp;
            }
        }
    }
    for (int j = START_ARRAY; j < SIZE_ALPHABET; j++){                //sorting elements index
        if (countLetter[j] != 0) {
            for (int i = START_ARRAY; i < SIZE_ALPHABET; i++) {
                if (countTemp[i] == countLetter[j]) {
                    indexArray[position] = i;
                    countTemp[i] = 0;
                    position++;
                }
            }
        }
    }
    printf("\nCounted letters (sorting max->min):\n");
    j = 0;
    for (int i = START_ARRAY; i < SIZE_ALPHABET; i++){
        if (countLetter[i] != 0) {
            printf("[%c] - %d\n", indexArray[j] + 'a',countLetter[i]);
            j++;
        }
    }
    free(inputString);
    return 0;
}
