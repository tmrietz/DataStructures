#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H
#include <iostream>
using namespace std;


template <typename nodeType>
class linkedListNode{
    private:
        nodeType val;
        linkedListNode<nodeType>* next; 
        linkedListNode<nodeType>* prev;

    public:
        linkedListNode(){
            next = nullptr;
            prev = nullptr;
        }

        linkedListNode(nodeType id){
            val = id;
            next = nullptr;
            prev = nullptr;
        }
       
        ~linkedListNode(){
            if(next!=nullptr){
                next->setPrev(prev);
            }
            if(prev!=nullptr){
                prev->setNext(next);
            }
        };

        void printNode(){
            cout << val;
        }

        linkedListNode<nodeType>* getNext(){
            return next;
        }

        void setNext(linkedListNode<nodeType>* node){
            next = node;
        }

        linkedListNode<nodeType>* getPrev(){
            return prev;
        }

        void setPrev(linkedListNode<nodeType>* node){
            prev = node;
        }

        nodeType getVal(){
            return val;
        }
};
#endif