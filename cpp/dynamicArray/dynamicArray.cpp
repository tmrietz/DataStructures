#include <iostream>
#include "dynamicArray.h"
using namespace std;


dynamicArray::dynamicArray(){
    arr = new int[10];
    size = 0; capacity = 10;
}


dynamicArray::dynamicArray(int cap){
    arr = new int[cap];
    size = 0; capacity = cap;
}


void dynamicArray::dynamicArrayInsert(int val){
    if(getSize() == getCapacity()){
        resizeArr();
    }
    arr[getSize()] = val;
    size++;
}


int dynamicArray::getSize(){
    return size;
}


int dynamicArray::getCapacity(){
    return capacity;
}


int dynamicArray::getValueAt(int position){
    return arr[position];
}


void dynamicArray::setValueAt(int position, int val){
    if(position >= 0 && position <= getSize()){
        arr[position] = val;
    } 
}


bool dynamicArray::isEmpty(){
    if(getSize() == 0){
        return true;
    }
    return false;
}


void dynamicArray::resizeArr(){
    int* tmp = new int[capacity*2];
    for(int s=0; s < getCapacity(); s++){
        tmp[s] = arr[s];
    }
    delete [] arr;
    arr = tmp;
    capacity *= 2;
}


void dynamicArray::printArr(){
    for(int j=0; j < getSize(); j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}


dynamicArray::~dynamicArray(){
    delete [] arr;
    arr = nullptr;
}