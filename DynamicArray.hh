////////////////////////////////////////////////////////////////////////////////
// array.hpp
//
// Create an array class with insert, get, delete, and size functions
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <limits.h>

class DynamicArray {
private:
    //Private Variables
    int size;
    int numOfValues;
    int* array = NULL;
    //Private Functions
    void shrink();
    void grow();


public:
    //Default Constructor
    DynamicArray() {
        size = 0;
        numOfValues = 1;
        array = new int[numOfValues];
    }
    //Constructor with size input from the user
    DynamicArray(int numOfValues) {
        size = 0;
        this->numOfValues = numOfValues;
        array = new int[numOfValues];
    }
    //Public Functions
    int getSize() {return size;}
    int getCapacity() {return numOfValues;}
    int getNum(int index);
    void insertAt(int num, int index);
    void deleteAt(int index);
    void push_back(int num);
    void pop_back();
    void printArray();
};

//Shrink array by half of its current capacity
void DynamicArray::shrink() {
    numOfValues = size;
    int* temp = new int[numOfValues];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    
    delete[] array;
    
    array = temp;
}

//Grow array by doubling its current size
void DynamicArray::grow() {
    numOfValues = numOfValues*2;
    int* temp = new int[numOfValues];

    for(int i = 0; i < numOfValues; i++){
        temp[i] = array[i];
    }

    delete[] array;

    array = temp;
}

//Get element at index
int DynamicArray::getNum(int index) {
    //Index is not accepted
    if (index < 0 || index > size-1) {
        return INT_MAX;
    }
    return array[index];
}
//Insert a value at a given index and shift all subsequent values
void DynamicArray::insertAt(int num ,int index) {
    //Check Bounds
    if(index > numOfValues || index < 0) {
        return;

    }
    //Check if array is large enough to hold values
    if(size ==  numOfValues ){
        grow();
    }
    //Shift all values by one until target index
    for(int i = size-1; i >= index; i--) {
        array[i+1] = array[i]; 
    }
    //Insert Value at target and increase size count
    array[index] = num;
    size++;
}
//Delete a value at a given index and shift all subsequent values
void DynamicArray::deleteAt(int index) {
    //Shift all values
    for(int i = index; i < size; i++) {
        array[i] = array[i+1];
    }
    //Replace last value and decrement size
    array[size-1] = 0;
    size--;
    //Check if capacity can be shrunk
    if(size == numOfValues/2) {
        shrink();
    }
}
//Push value to end of list
void DynamicArray::push_back(int num) {
    //Check if array is large enough to hold values
    if(size ==  numOfValues){
        grow();
    }
    //Push value
    array[size] = num;
    size++;
}
//Pop value at end of list
void DynamicArray::pop_back() {
    if (size == 0) {
        return;
    }
    //Pop Value
    array[size-1] = 0;
    size--;
    //Check if capacity can be shrunk
    if(size == numOfValues/2) {
        shrink();
    }
}
//Print values in array using list format
void DynamicArray::printArray() {
    std::cout<<"[";
    for(int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i+1 < size) {
            std::cout << ",";
        }
    }
    std::cout<<"]\n";
}