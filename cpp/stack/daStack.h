#ifndef DASTACK_H
#define DASTACK_H

#include "../dynamicArray/dynamicArray.h"
#include <iostream>
using namespace std;


template <typename type>
class Stack{
    private:
        dynamicArray<type>* arr;

    public:
        Stack(){
            ll = new dynamicArray<type>();
        }
        Stack(type val){
            ll = new dynamicArray<type>(capacity);
        }
        ~Stack(){
            delete arr;
        }

        void pop(){
            arr->removeBack();
        }

        void push(type val){
            arr->pushBack(val);
        }

        type top(){
            return arr->back();
        }

        void size(){
            return arr->getSize();
        }

        bool isEmpty(){
            return arr->isEmpty();
        }
};
#endif