#include <iostream>
#define SIZE_ARRAY 15

using namespace std;

class ArrayList{
private:
    int* array;
    int currentSize;
    int allocatedSize;

    void fillNewArray(int* newArray){
        for(int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
    }
    void addToNotFullArray(int newValue){
        array[currentSize] = newValue;
        currentSize++;
    }

    void addToFullArray(int newValue){
        doubleCapacityOfArray();
        addToNotFullArray(newValue);
    }

public:
    ArrayList(){
        array = new int [SIZE_ARRAY];
        currentSize = 0;
        allocatedSize = SIZE_ARRAY;
    }

    void doubleCapacityOfArray(){
        int* newArray = new int (allocatedSize  *2);
        allocatedSize *= 2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
    }

    void addToArray(int newValue){
        if(currentSize < allocatedSize){
            addToNotFullArray(newValue);
        }else{
            addToFullArray(newValue);
        }
    }

    void addToArray(int newValue, int index){
        if(index >= currentSize){
            cout<<"WRONG"<<endl;
            return;
        }
        if(currentSize >= allocatedSize){
            doubleCapacityOfArray();
        }
        for(int i = currentSize; i > index; i--){
            array[i] = array[i-1];
        }
        array[index] = newValue;
        currentSize++;
    }

    void trimToSizeArray(){
        int* tempArray = new int[currentSize];

        for(int i = 0; i < currentSize; i++){
            tempArray[i] = array[i];
        }
        delete[] array;
        array = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            array[i] = tempArray[i];
        }
        delete[] tempArray;
    }

    void removeIndex(int index){
        for(int i = 0; i < currentSize; i++){
            if(array[i] == index){
                for( ; i < currentSize - 1; i++){
                    array[i] = array[i + 1];
                }
                array[currentSize - 1] = 0;
                currentSize = currentSize - 1;
            }
        }
    }

    void printArray(){
        for(int i = 0; i < currentSize; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, const char * argv[])
{
    ArrayList* list = new ArrayList();

    for(int i = 0; i < SIZE_ARRAY; i++){
        list->addToArray(i);
    }
    list->printArray();
    list->removeIndex(5);
    list->removeIndex(9);
    list->printArray();
    list->trimToSizeArray();
    list->addToArray(4,0);
    list->printArray();
    list->addToArray(8,2);
    list->printArray();
}
