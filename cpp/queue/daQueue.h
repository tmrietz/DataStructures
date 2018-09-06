#ifndef DAQUEUE_H
#define DAQUEUE_H

#include "../dynamicArray/dynamicArray.h"
using namespace std;

template <typename type>
class Queue{
    private:
        dynamicArray<type>* arr;

    public:
        Queue(){
            arr = new dynamicArray<type>();
        }
        Queue(int cap){
            arr = new dynamicArray<type>(cap);
        }
        ~Queue(){
            delete arr;
        }

        void push(type val){
            arr->pushFront(val);
        }

        void pop(){
            arr->removeBack();
        }

        type front(){
            return arr->begin();
        }

        type back(){
            return arr->end();
        }
};
#endif


/*
int main(){
    Queue<string>* queue = new Queue<string>();
    queue->push(string("test"));
    cout << queue->front() << endl;
    cout << queue->back() << endl;

    queue->push(string("test2"));
    cout << queue->front() << endl;
    cout << queue->back() << endl;

    queue->pop();
    cout << queue->front() << endl;
    cout << queue->back() << endl;
    return 0;
}
*/