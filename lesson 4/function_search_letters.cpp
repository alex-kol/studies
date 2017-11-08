#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1000000
const int START_ARRAY = 0;
const int SIZE_ALPHABET = 26;

void zeroArray (int* countTemp, int* countLetter, int* indexArray){
    for (int i = START_ARRAY; i < SIZE_ALPHABET; i++){                //zero's in the all array
        countTemp[i] = 0;
        countLetter[i] = 0;
        indexArray[i] = 0;
    }
}

char* getString(){
    char* enterString;

    enterString = (char*) malloc(SIZE_STRING * sizeof(char));
    printf("Input the string:\n\n");
    gets(enterString);
    if (enterString[0] == '\0'){                                       //checking for an empty string
        printf("String is't input!\n");
    }
    return enterString;
}

void getLetterCounter(char* inputedArray, int* countTemp, int* countLetter){
    for (int i = START_ARRAY; i < SIZE_ALPHABET; i++){
        if (inputedArray[i] >= 'A' && inputedArray[i] <='Z') {
            countLetter[inputedArray[i]-'A']++;
            countTemp[inputedArray[i]-'A']++;
        }
        if  (inputedArray[i] >= 'a' && inputedArray[i] <= 'z'){
            countLetter[inputedArray[i]-'a']++;
            countTemp[inputedArray[i]-'a']++;
        }
    }
}

void sortCountLetter (int* countLetter){
    for(int i = START_ARRAY; i < SIZE_ALPHABET; i++){                    // sorting bubble
        for(int j = i + 1; j < SIZE_ALPHABET; j++){
            if(countLetter[i] < countLetter[j]){
                int temp = countLetter[i];
                countLetter[i] = countLetter[j];
                countLetter[j] = temp;
            }
        }
    }
}

void sortLetterIndex(int* countTemp, int* countLetter, int* indexArray){
    int position = 0;

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
}

void showResult(int* countLetter, int* indexArray){
    printf("\nCounted letters (sorting max->min):\n");
    int j = 0;
    for (int i = START_ARRAY; i < SIZE_ALPHABET; i++){
        if (countLetter[i] != 0) {
            printf("[%c] - %d\n", indexArray[j] + 'a',countLetter[i]);
            j++;
        }
    }
}

int main()
{
    int countTemp[SIZE_ALPHABET];
    int countLetter[SIZE_ALPHABET];
    int indexArray[SIZE_ALPHABET];

    char* inputString = getString();

    zeroArray(countTemp, countLetter, indexArray);
    getLetterCounter(inputString, countLetter, countTemp);
    sortCountLetter(countLetter);
    sortLetterIndex(countTemp, countLetter, indexArray);
    showResult(countLetter, indexArray);
    free(inputString);
    return 0;
}
