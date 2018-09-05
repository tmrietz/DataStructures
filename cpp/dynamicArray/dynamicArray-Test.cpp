#include <iostream>
#include "dynamicArray.h"
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    dynamicArray<int>* dynArr = new dynamicArray<int>();
    int size, capacity;
    size = dynArr->getSize();
    capacity = dynArr->getCapacity();
    cout << "size: " << size << "   capacity: " << capacity << endl;
    dynArr->printArr();

    for(int i=0; i<16; i++){
        dynArr->pushBack( arr[i] );
    }
    size = dynArr->getSize();
    capacity = dynArr->getCapacity();
    cout << "size: " << size << "   capacity: " << capacity << endl;
    dynArr->printArr();


    delete dynArr;
    dynArr = nullptr;
    return 0;
}
