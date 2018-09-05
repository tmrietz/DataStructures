#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "linkedListNode.h"
using namespace std;


template <typename nodeType>
class linkedList{
    private:
        linkedListNode<nodeType>* head;
        linkedListNode<nodeType>* tail;
        int size;

    public:
        linkedList(){
            head = nullptr; tail = nullptr; size=0;
        }
        linkedList(nodeType val){
            linkedListNode<nodeType>* newNode = new linkedListNode<nodeType>(val);
            head = newNode; tail = newNode; size = 1;
        }
        ~linkedList(){};

        void printList(){
            linkedListNode<nodeType>* tmp = head;
            cout << "null<-->";
            while(tmp != nullptr){
                tmp->printNode();
                cout << "<-->";
                tmp = tmp->getNext();
            }
            cout << "null" << endl;
            delete tmp;
        }

        void pushFront(nodeType val){
            linkedListNode<nodeType>* node = new linkedListNode<nodeType>(val);
            node->setNext(head);
            head->setPrev(node);
            head = node;
        }

        void pushBack(nodeType val){
            linkedListNode<nodeType>* node = new linkedListNode<nodeType>(val);
            node->setPrev(tail);
            tail->setNext(node);
            tail = node;
        }

        void insertAt(nodeType val, int index){
            if(sizeCheck(index) == false){
                return;
            } else if(index == size){
                pushBack(val);
                return;
            } else if(index == 0){
                pushFront(val);
                return;
            } else{
                linkedListNode<nodeType>* node = new linkedListNode<nodeType>(val);
                linkedListNode<nodeType>* tmp = head;
                int count = 1;
                while(tmp != nullptr && count <= index){
                    if(count == index){
                        node->setNext(tmp->getNext());
                        node->setPrev(tmp->getPrev());
                        node->getPrev()->setNext(node);
                        node->getNext()->setPrev(node);
                        return;
                    }
                    tmp = tmp->getNext();
                    count++;
                }
            }
        }

        int getSize(){
            return size;
        }

        bool sizeCheck(int index){
            if (index > size || index < 0){
                cout << "ERR: Out of range." << endl;
                return false;
            }
            return true;
        }

        void removeFront(){
            if(head->getNext() != nullptr){
                head = head->getNext();
                delete head->getPrev();
            } else {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
        }

        void removeBack(){
            if(tail->getPrev() != nullptr){
                tail = tail->getPrev();
                delete tail->getNext();
            } else {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
        }

        nodeType getFront(){
            return head->getVal();
        }

        nodeType getBack(){
            return tail->getVal();
        }

        void setFirst(nodeType val){
            linkedListNode<nodeType>* node = new linkedListNode<nodeType>(val);
            head = node; tail = node;
        }

        bool lookUp(nodeType val){
            linkedListNode<nodeType>* tmp = head;
            while(tmp != nullptr){
                if(val == tmp->getVal()){
                    return true;
                }
                tmp = tmp->getNext();
            }
            return false;
        }
};
#endif

/*
int main(){
    linkedListNode<int>* node1 = new linkedListNode<int>(20);
    node1->printNode(); cout << endl;

    linkedList<string>* ll = new linkedList<string>("Taylor");
    ll->printList();
    ll->pushFront("Taylor2");
    ll->printList();
    ll->pushBack("Taylor3");
    ll->printList();
    ll->removeBack();
    ll->printList();
    cout << ll->lookUp("Taylor") << endl;
    ll->printList();
    cout << ll->lookUp("Taylor2") << endl;
    ll->removeFront();
    ll->printList();
    ll->removeBack();
    ll->printList();
    

    delete node1;

    return 0;
}
*/
