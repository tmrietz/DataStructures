#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;


template <typename type>
class dynamicArray{
    private:
        type* arr;
        int right, left, capacity;

    public:
        dynamicArray(){
            arr = new type[10];
            right = 0; left = 0; capacity = 10;
        }

        dynamicArray(int cap){
            arr = new type[cap];
            right = 0; left = 0; capacity = cap;
        }

        void pushBack(type val){
            if(getSize() == getCapacity()){
                resizeArr();
            }
            arr[getSize()] = val;
            right++;
        }

        void pushFront(type val){
            if(getSize() == getCapacity()){
                resizeArr();
            }
            int itr = getSize()-1;
            while(itr >= left){
                arr[itr+1] = arr[itr];
                itr--;
            }
            arr[left] = val;
            right++;
        }

        void removeBack(){
            right--;
        }

        void removeFront(){
            left++;
        }

        int getSize(){
            return right;
        }

        int getCapacity(){
            return capacity;
        }

        type getAt(int position){
            return arr[position];
        }

        type begin(){
            return getAt(left);
        }

        type end(){
            return getAt(right-1);
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
            for(int j=left; j < getSize(); j++){
                cout << arr[j] << " ";
            }
            cout << endl;
        }

        int lookUp(type val){
            for(int s=0; s<getSize(); s++){
                if(arr[s] == val)
                    return s;
            }
            return -1;
        }

        ~dynamicArray(){
            delete [] arr;
            arr = nullptr;
        }
};

#endif