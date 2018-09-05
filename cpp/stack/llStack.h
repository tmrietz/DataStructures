#ifndef LLSTACK_H
#define LLSTACK_H

#include "../linkedList/linkedList.h"
#include <iostream>
using namespace std;


template <typename nodeType>
class Stack{
    private:
        linkedList<nodeType>* ll;

    public:
        Stack(){
            ll = new linkedList<nodeType>();
        }
        Stack(nodeType val){
            ll = new linkedList<nodeType>(val);
        }
        ~Stack(){
            delete ll;
        }

        void pop(){
            ll->removeFront();
        }

        void push(nodeType val){
            if(ll->getHead() == nullptr){
                ll->setFirst(val);
            } else {
                ll->pushFront(val);
            }
        }

        nodeType top(){
            return ll->head();
        }

        void size(){
            return ll->getSize();
        }

        bool isEmpty(){
            if(ll->getSize()==0){
                return true;
            }
            return false;
        }

        bool lookUp(nodeType val){
            return ll->lookUp(val);
        }
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