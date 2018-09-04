#include <iostream>
#include <string>
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


template <typename nodeType>
class linkedList{
    private:
        linkedListNode<nodeType>* head;
        linkedListNode<nodeType>* tail;

    public:
        linkedList(){
            head = nullptr; tail = nullptr;
        }
        linkedList(nodeType val){
            linkedListNode<nodeType>* newNode = new linkedListNode<nodeType>(val);
            head = newNode; tail = newNode;
        }
        ~linkedList(){};

        void printList(){
            linkedListNode<nodeType>* tmp = head;
            while(tmp != nullptr){
                tmp->printNode();
                cout << "<-->";
                tmp = tmp->getNext();
            }
            cout << endl;
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

        bool lookUp(nodeType val){
            linkedListNode<nodeType>* tmp = head;
            tmp = head;
            while(tmp != nullptr){
                if(val == tmp->getVal()){
                    return true;
                }
                tmp = tmp->getNext();
            }
            return false;
        }
};


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
