#include <iostream>
#include <string>
using namespace std;

template <typename nodeType>
class linkedListNode{
    private:
        nodeType val;
        linkedListNode* next; 
        linkedListNode* prev;

    public:
        linkedListNode(){
            val = NULL;
        };

        linkedListNode(nodeType id){
            val = id;
        }

        void printNode(){
            cout << val << endl;
        }

        ~linkedListNode(){};
};



int main(){
    linkedListNode<int>* node1 = new linkedListNode<int>(20);
    linkedListNode<string>* node2 = new linkedListNode<string>("Taylor");

    node1->printNode();
    node2->printNode();

    delete node1;
    delete node2;

    return 0;
}
