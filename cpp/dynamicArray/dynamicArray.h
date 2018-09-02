#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class dynamicArray{
    private:
        int* arr;
        int size, capacity;

    public:
        dynamicArray();
        dynamicArray(int cap);
        ~dynamicArray();
        
        int getSize();
        int getCapacity();
        int getValueAt(int position);
        void setValueAt(int position, int val);
        void dynamicArrayInsert(int val);
        void resizeArr();
        bool isEmpty();
        void printArr();
};

#endif