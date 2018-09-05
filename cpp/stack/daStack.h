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
            return arr[arr->getSize()];
        }

        void size(){
            return arr->getSize();
        }

        bool isEmpty(){
            return arr->isEmpty();
        }

/*     THIS SHOULD BE BINARY SEARCH
        bool lookUp(type val){
            return ll->lookUp(val);
        }
*/
};
#endif

/*
int main(){
    linkedList<string>* ll = new linkedList<string>("test");
    ll->printList();
    ll->insertAt("test2",2);
    ll->printList();
    delete ll;
    return 0;
}
*/