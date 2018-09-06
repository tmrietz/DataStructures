#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;


template <typename type>
class dynamicArray{
    private:
        type* arr;
        int size, capacity;

    public:
        dynamicArray(){
            arr = new type[10];
            size = 0; capacity = 10;
        }

        dynamicArray(int cap){
            arr = new type[cap];
            size = 0; capacity = cap;
        }

        void pushBack(type val){
            if(getSize() == getCapacity()){
                resizeArr();
            }
            arr[getSize()] = val;
            size++;
        }

        void pushFront(type val){
            if(getSize() == getCapacity()){
                resizeArr();
            }
            int itr = getSize()-1;
            while(itr >= 0){
                arr[itr+1] = arr[itr];
                itr--;
            }
            arr[0] = val;
            size++;
        }

        void removeBack(){
            size--;
        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        type getAt(int position){
            return arr[position];
        }

        void setAt(int position, type val){
            if(position >= 0 && position <= getSize()){
                arr[position] = val;
            } 
        }

        bool isEmpty(){
            if(getSize() == 0){
                return true;
            }
            return false;
        }

        void resizeArr(){
            type* tmp = new type[capacity*2];
            for(int s=0; s < getCapacity(); s++){
                tmp[s] = arr[s];
            }
            delete [] arr;
            arr = tmp;
            capacity *= 2;
        }

        void printArr(){
            for(int j=0; j < getSize(); j++){
                cout << arr[j] << " ";
            }
            cout << endl;
        }

        ~dynamicArray(){
            delete [] arr;
            arr = nullptr;
        }
};

#endif