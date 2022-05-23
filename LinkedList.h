#pragma once
#include "Node.h"
#include <array>

class LinkedList{
    public:
        LinkedList();
        LinkedList(int*, int);
        void addFront(int);
        void addEnd(int);
        void addAtPosition(int, int);
        int search(int);
        void deleteFront();
        void deleteEnd();
        void deletePosition(int);
        int getItem(int);
        void printItems();
        ~LinkedList();


    private:
        Node* head;
};