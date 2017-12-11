#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

const int SIZE_ARRAY = 50;

class Map{
public:
    int array[SIZE_ARRAY];

    int hash(char* str){
        return strlen(str);
    }

    int getOfMap(char* str){
        return array[hash(str)];
    }

    void inputInMap(char* str, int value){
        array[hash(str)] = value;
    }
};

#endif
