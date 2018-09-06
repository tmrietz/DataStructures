#include "../dynamicArray/dynamicArray.h"
using namespace std;


template <typename type>
class Dequeue{
    private:
        dynamicArray<type>* arr;

    public:
        Dequeue(){
            arr = new dynamicArray<type>();
        }
        Dequeue(int cap){
            arr = new dynamicArray<type>(cap);
        }
        ~Dequeue(){
            delete arr;
        }

        void pushFront(type val){
            arr->pushFront(val);
        }

        void pushBack(type val){
            arr->pushBack(val);
        }

        void removeFront(){
            arr->removeFront();
        }

        void removeBack(){
            arr->removeBack();
        }

        type front(){
            return arr->begin();
        }

        type back(){
            return arr->end();
        }

        void printDequeue(){
            arr->printArr();
        }
};

int main(){
    Dequeue<string>* dequeue = new Dequeue<string>();
    dequeue->pushFront(string("test"));     //test test
    dequeue->printDequeue();

    dequeue->pushBack(string("test2"));     //test test2
    dequeue->printDequeue();

    dequeue->removeFront();                 //test2 test2
    dequeue->printDequeue();

    dequeue->removeBack();                  //
    dequeue->printDequeue();

    delete dequeue;
    return 0;
}

